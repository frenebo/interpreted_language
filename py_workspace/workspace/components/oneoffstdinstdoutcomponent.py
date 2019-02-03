import subprocess
from .baseworkspacecomponent import (
    BaseWorkspaceComponent,
    ComponentInstantiationException,
    BaseWorkspaceComponentInstance,
)

class OneOffStdinStdoutComponentInstance(BaseWorkspaceComponentInstance):
    def __init__(self, command_string, input_data_pipe, output_data_pipe):
        super().__init__()
        subprocess.call(command_string)

class OneOffStdinStdoutComponent(BaseWorkspaceComponent):
    def __init__(self, command_string, input_type, output_type):
        assert isinstance(command_string, str), "Assert command string argument is a string"
        assert isinstance(input_type, str), "Assert input type is a string"
        assert isinstance(output_type, str), "Assert output type is a string"

        self._command_string = command_string

        super().__init__(
            {"default": input_type},
            {"default": output_type}
        )

    def create_component_instance(self, input_data_pipe_dict, output_data_pipe_dict):
        if "default" not in input_data_pipe_dict:
            raise ComponentInstantiationException("No pipe for \"default\" input port")

        if "default" not in output_data_pipe_dict:
            raise ComponentInstantiationException("No pipe for \"default\" output port")

        return OneOffStdinStdoutComponentInstance(
            self._command_string,
            input_data_pipe_dict["default"],
            output_data_pipe_dict["default"])
