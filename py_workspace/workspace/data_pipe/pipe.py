from .pipe_utils import PipeUtils

class DataPipe:
    def __init__(self, pipe_name):
        assert isinstance(pipe_name, str), "Assert that pipe name is a string"
        self._pipe_name = pipe_name

        PipeUtils.init_pipe_dir_if_missing()

    # def
