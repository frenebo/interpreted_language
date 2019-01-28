import contextlib
import io
import sys
import json

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
    data_types = ["json", "string"]
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
            input_val = None

            # process input
            if entry_input_type == "json":
                input_val = json.loads(line)
            elif entry_input_type == "string":
                input_val = line
            else:
                raise Exception("Unimplemented input type " + entry_input_type)

            # run function
            raw_result = None
            with contextlib.redirect_stdout(fun_stdout_redirect):
                raw_result = entry_fun(input_val)

            # process output
            result = None
            if entry_output_type == "json":
                result = json.dumps(raw_result)
            elif entry_input_type == "string":
                input_val = line
            else:
                raise Exception("Unimplented output type " + entry_output_type)

            sys.stdout.write(result + "\n")
            sys.stdout.flush()

        # for ch in fun_stdout_redirect.getvalue()
        #     print(ch)
