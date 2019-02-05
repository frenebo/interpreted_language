import os
import errno
import shutil

class PipeUtilsException(Exception):
    """Exception for pipe utils actions"""

class PipeUtils:
    _pipe_dir_name = "pipes"

    @staticmethod
    def remove_pipe_dir():
        try:
            shutil.rmtree(PipeUtils._pipe_dir_name)
        except FileNotFoundError:
            pass

    @staticmethod
    def init_pipe_dir_if_missing():
        try:
            os.makedirs(PipeUtils._pipe_dir_name)
        except OSError as e:
            # don't raise exception if the dir already exists
            if e.errno != errno.EEXIST:
                raise PipeUtilsException("Error creating directory: " + e.strerror)

    @staticmethod
    def create_named_pipe(pipe_name):
        PipeUtils.init_pipe_dir_if_missing()

        pipe_path = PipeUtils.get_pipe_path(pipe_name)

        try:
            os.mkfifo(pipe_path)
        except OSError as e:
            raise PipeUtilsException("Could not create named pipe: " + e.strerror)


    @staticmethod
    def get_pipe_path(pipe_name):
        return PipeUtils._pipe_dir_name + "/" + pipe_name
