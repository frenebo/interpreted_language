
class WorkspaceConnectionDescription:
    def __init__(self, source_component_name, target_component_name, source_port_name, target_port_name):
        assert isinstance(source_component_name, str), "Assert that source component name is string"
        assert isinstance(target_component_name, str), "Assert that target component name is string"
        assert isinstance(source_port_name, str), "Assert that source port name is string"
        assert isinstance(target_port_name, str), "Assert that target port name is string"

        self._source_component_name = source_component_name
        self._target_component_name = target_component_name
        self._source_port_name = source_port_name
        self._target_port_name = target_port_name

    def get_source_component_name(self):
        return self._source_component_name

    def get_target_component_name(self):
        return self._target_component_name

    def get_source_port_name(self):
        return self._source_port_name

    def get_target_port_name(self):
        return self._target_port_name
