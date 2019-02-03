
class ComponentInstantiationException(Exception):
    """Exception to be thrown in the instantiation of a component"""

class BaseWorkspaceComponentInstance():
    def __init__(self):
        pass

class BaseWorkspaceComponent():
    def __init__(self, input_ports, output_ports):
        assert isinstance(input_ports, dict), "input ports argument is dict"
        assert isinstance(output_ports, dict), "output ports argument is dict"

        for k, v in input_ports.items():
            assert isinstance(k, str), "input port dict has strings for keys"
            assert isinstance(v, str), "input port dict has strings for values"

        for k, v in output_ports.items():
            assert isinstance(k, str), "output port dict has strings for keys"
            assert isinstance(v, str), "output port dict has strings for values"

        self._input_ports = input_ports
        self._output_ports = output_ports

    def get_input_port_names(self):
        return list(self._input_ports.keys())

    def get_output_port_names(self):
        return list(self._output_ports.keys())

    def create_component_instance(self, input_data_pipe_dict, output_data_pipe_dict):
        raise NotImplementedError("create_component_instance is not implemented in base class")
