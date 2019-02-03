from .baseworkspacecomponent import BaseWorkspaceComponent, BaseWorkspaceComponentInstance, ComponentInstantiationException

class InputComponentInstance(BaseWorkspaceComponentInstance):
    def __init__(self, output_data_pipe):
        pass

class InputComponent(BaseWorkspaceComponent):
    def __init__(self, data_type):
        assert isinstance(data_type, str), "Assert that datas type is a string"

        super().__init__(
            {}, # no input ports
            {"default": data_type}, # one output port: "default""
        )

    def create_component_instance(self, input_data_pipe_dict, output_data_pipe_dict):
        if "default" not in output_data_pipe_dict:
            raise ComponentInstantiationException("No pipe for \"default\" output port")

        return InputComponentInstance(output_data_pipe_dict["default"])

