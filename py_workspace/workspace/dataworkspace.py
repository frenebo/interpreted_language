from .workspaceinstance import WorkspaceInstance
from .components import BaseWorkspaceComponent
from .workspaceconnectiondescription import WorkspaceConnectionDescription

class DataWorkspaceConfigException(Exception):
    """Exception for problems in setting up a data workspace, not in instantiating the workspace"""

class DataWorkspace():
    def __init__(self):
        self._components = {}
        self._connection_descriptions = []

    def create_and_start_instance(self):
        workspace_instance = WorkspaceInstance(self._components.copy(), self._connection_descriptions.copy())
        workspace_instance.start()

        return workspace_instance

    def add_component(self, key, component):
        assert isinstance(key, str), "Assert component key is a string"
        assert isinstance(component, BaseWorkspaceComponent), "Assert component is instance of WorkspaceComponent"

        if key in self._components:
            raise DataWorkspaceConfigException("A component with the key \"" + key + "\" already exists in this workspace")

        self._components[key] = component

    def add_connection(self, source_component_key, target_component_key, source_port_key="default", target_port_key="default"):
        if source_component_key not in self._components:
            raise DataWorkspaceConfigException("Could not find component with key \"" + source_component_key + "\"")

        if target_component_key not in self._components:
            raise DataWorkspaceConfigException("Could not find component with key \"" + target_component_key + "\"")

        if source_port_key not in self._components[source_component_key].get_output_port_names():
            raise DataWorkspaceConfigException(
                "Source component \"" + source_component_key + "\" has no output port named \"" + source_port_key + "\"")

        if target_port_key not in self._components[target_component_key].get_input_port_names():
            raise DataWorkspaceConfigException(
                "Target component \"" + target_component_key + "\" has no input port named \"" + target_port_key + "\"")

        # @TODO check for identical connections, or for connections that already occupy the specified output port?

        self._connection_descriptions.append(WorkspaceConnectionDescription(source_component_key, target_component_key, source_port_key, target_port_key))
