import contextlib
import io
import sys
import json
import threading
import os

class ZementisDataTypeConfigError(Exception):
    """Exception for invalid data type configuration"""

class EntryFuncWrapper():
    def __init__(self, fun, input_type, output_type):
        if input_type not in ZementisInterface.data_types:
            raise ZementisDataTypeConfigError("Input type type \"" + input_form + "\" is invalid")
        if output_type not in ZementisInterface.data_types:
            raise ZementisDataTypeConfigError("Output type type \"" + input_form + "\" is invalid")

        self.fun = fun
        self.input_type = input_type
        self.output_type = output_type

class ZementisInterface:
    data_types = ["json", "text"]
    entry_func_wrapper = None

    # generates a decorator and registers the function
    @staticmethod
    def set_entry_func(input_type, output_type):
        if ZementisInterface.entry_func_wrapper != None:
            raise Exception("Entry function is already defined")

        def decorator(fun):
            ZementisInterface.entry_func_wrapper = EntryFuncWrapper(fun, input_type, output_type)
            return fun

        return decorator

    @staticmethod
    def set_up_interface():
        if ZementisInterface.entry_func_wrapper == None:
            raise Exception("No entry function defined")

        entry_fun = ZementisInterface.entry_func_wrapper.fun
        entry_input_type = ZementisInterface.entry_func_wrapper.input_type
        entry_output_type = ZementisInterface.entry_func_wrapper.output_type

        fun_stdout_redirect = io.StringIO()

        for line in sys.stdin:
            sys.stderr.write("Just read a line!\n")
            def threaded_call():
                stdin_instruction_json = json.loads(line)
                input_pipe_path = stdin_instruction_json["input_pipe_paths"]["input_name"]

                fd = os.open(input_pipe_path, os.O_RDONLY)

                pipe_read_value = None
                with os.fdopen(fd, 'r') as in_fifo:
                    pipe_read_value = in_fifo.read()

                input_val = None

                # process input
                if entry_input_type == "json":
                    input_val = json.loads(pipe_read_value)
                elif entry_input_type == "text":
                    input_val = pipe_read_value
                else:
                    raise Exception("Unimplemented input type " + entry_input_type)

                # run function
                raw_result = None
                with contextlib.redirect_stdout(fun_stdout_redirect):
                    raw_result = entry_fun(input_val)

                result_text = None
                if entry_output_type == "json":
                    result_text = json.dumps(raw_result)
                elif entry_output_type == "text":
                    result_text = raw_result
                else:
                    raise Exception("Unimplemented output type " + entry_output_type)

                output_pipe_path = stdin_instruction_json["output_pipe_paths"]["output_name"]
                fd = os.open(output_pipe_path, os.O_WRONLY)

                with os.fdopen(fd, 'w') as output_fifo:
                    output_fifo.write(result_text)
                    # output_fifo.flush()


            thread = threading.Thread(target=threaded_call)
            thread.start()


            # sys.stdout.write(result + "\n")
            # sys.stdout.flush()

        # for ch in fun_stdout_redirect.getvalue()
        #     print(ch)
