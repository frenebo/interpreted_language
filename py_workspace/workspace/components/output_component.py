from .baseworkspacecomponent import BaseWorkspaceComponent, BaseWorkspaceComponentInstance, ComponentInstantiationException

class OutputComponentInstance(BaseWorkspaceComponentInstance):
    def __init__(self):
        pass

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

        return OutputComponentInstance()
