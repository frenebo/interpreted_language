from .pipe_utils import PipeUtils

class DataPipe:
    def __init__(self, pipe_name):
        assert isinstance(pipe_name, str), "Assert that pipe name is a string"
        self._pipe_name = pipe_name

        PipeUtils.create_named_pipe(pipe_name)

    def get_pipe_path(self):
        return PipeUtils.get_pipe_path(self._pipe_name)

    # def
