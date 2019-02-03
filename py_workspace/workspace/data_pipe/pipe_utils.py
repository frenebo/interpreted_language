import os
import errno

class PipeUtils:
    _pipe_dir_name = "pipes"

    @staticmethod
    def init_pipe_dir_if_missing():
        try:
            os.makedirs(PipeUtils._pipe_dir_name)
        except OSError as e:
            if e.errno != errno.EEXIST:
                raise
