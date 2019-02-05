import os
from .baseworkspacecomponent import BaseWorkspaceComponent, BaseWorkspaceComponentInstance, ComponentInstantiationException
import threading
import subprocess
import json

class SingletonProcessComponentInstance(BaseWorkspaceComponentInstance):
    def __init__(self):
        pass

class SingletonProcessComponent(BaseWorkspaceComponent):
    def __init__(self, cmd_string, input_port_types, output_port_types):
        super().__init__(input_port_types, output_port_types)

        assert isinstance(cmd_string, str), "Assert that command string argument is a string"

        self._subproc = subprocess.Popen(
            cmd_string,
            shell=True,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            # stderr=subprocess.STDOUT
        )

    def create_component_instance(self, input_data_pipe_dict, output_data_pipe_dict):
        for required_key in self._input_ports:
            if required_key not in input_data_pipe_dict:
                print("Process missing input \"" + required_key + "\"")

        for required_key in self._output_ports:
            if required_key not in output_data_pipe_dict:
                print("Process missing output \"" + required_key + "\"")

        instruction_obj_for_subproc = {
            "input_pipe_paths": {},
            "output_pipe_paths": {},
        }

        for input_name in self._input_ports:
            instruction_obj_for_subproc["input_pipe_paths"]["input_name"] = input_data_pipe_dict[input_name].get_pipe_path()

        for output_name in self._output_ports:
            instruction_obj_for_subproc["output_pipe_paths"]["output_name"] = output_data_pipe_dict[output_name].get_pipe_path()

        json_instruction_string = json.dumps(instruction_obj_for_subproc) + "\n"
        self._subproc.stdin.write(
            json_instruction_string.encode()
        )
        self._subproc.stdin.flush()

        return SingletonProcessComponentInstance()
