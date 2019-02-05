from .baseworkspacecomponent import BaseWorkspaceComponent, BaseWorkspaceComponentInstance, ComponentInstantiationException
import threading
import os

class OutputComponentInstance(BaseWorkspaceComponentInstance):
    def __init__(self, input_data_pipe):
        pipe_path = input_data_pipe.get_pipe_path()

        def threaded_read():
            fd = os.open(pipe_path, os.O_RDONLY)

            with os.fdopen(fd, 'r') as in_fifo:
                print("output: " + in_fifo.read())

        # running this is thread since opening the named pipe blocks until a reader opens it also
        thread = threading.Thread(target=threaded_read)
        thread.start()

class OutputComponent(BaseWorkspaceComponent):
    def __init__(self, data_type):
        assert isinstance(data_type, str), "Assert that data type is a string"

        super().__init__(
            {"default": data_type}, # output component has one input port
            {}, # output component has no outputs coming out of it
        )

    def create_component_instance(self, input_data_pipe_dict, output_data_pipe_dict):
        if "default" not in input_data_pipe_dict:
            raise ComponentInstantiationException("No pipe for \"default\" input port")

        return OutputComponentInstance(input_data_pipe_dict["default"])
