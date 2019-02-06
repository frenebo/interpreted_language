from ..data_pipe import DataPipe, PipeUtils
import random

class WorkspaceInstanceException(Exception):
    """Exception for a problem in instantiating the workspace"""

class WorkspaceInstance():
    def __init__(self, components, connection_descriptions):
        assert isinstance(components, dict), "Assert that components argument to init is a dict"
        assert isinstance(connection_descriptions, list), "Assert that connection_descriptions argument to init is a list"

        self._uninstantiated_components = components.copy()
        self._connection_descriptions = connection_descriptions.copy()

        self._component_instances = None
        self._data_pipes = None

    def _new_data_pipe_id(self):
        pipe_id = None

        is_unique = False
        while not is_unique:
            if (pipe_id is not None) and (not PipeUtils.exists_pipe(pipe_id)):
                is_unique = True
            else:
                pipe_id = str(int(random.uniform(0, 1)*1000000))

        return pipe_id


    def start(self):
        if self._component_instances is not None:
            raise WorkspaceInstanceException("Workspace instance has already been started")

        PipeUtils.remove_pipe_dir()

        self._component_instances = {}
        self._data_pipes = {}

        # dictionary of dictionaries, with the key for base dict being component name and the
        # second level dict being the dictionary of INPUT connections, with port name as key
        component_input_connection_dicts = {}

        # dictionary of dictionaries, with the key for base dict being component name and the
        # second level dict being the dictionary of OUTPUT connections, with port name as key
        component_output_connection_dicts = {}

        for key in self._uninstantiated_components:
            component_input_connection_dicts[key] = {}
            component_output_connection_dicts[key] = {}

        # set up connections
        for conn_description in self._connection_descriptions:
            data_pipe_key = self._new_data_pipe_id()
            data_pipe = DataPipe(data_pipe_key)

            self._data_pipes[data_pipe_key] = data_pipe

            # add to connections by source component dict
            source_component_name = conn_description.get_source_component_name()
            source_port_name = conn_description.get_source_port_name()

            component_output_connection_dicts[source_component_name][source_port_name] = data_pipe

            # add to connection by target component dict
            target_component_name = conn_description.get_target_component_name()
            target_port_name = conn_description.get_target_port_name()

            component_input_connection_dicts[target_component_name][target_port_name] = data_pipe

        for key, component in self._uninstantiated_components.items():
            self._component_instances[key] = component.create_component_instance(
                component_input_connection_dicts[key],
                component_output_connection_dicts[key],
            )
