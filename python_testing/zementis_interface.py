import contextlib
import io

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
    data_types = ["json"]
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
    def test_run():
        if ZementisInterface.entry_func_wrapper == None:
            raise Exception("No entry function defined")

        entry_fun = ZementisInterface.entry_func_wrapper.fun
        entry_input_type = ZementisInterface.entry_func_wrapper.input_type
        entry_output_type = ZementisInterface.entry_func_wrapper.output_type

        fun_stdout_redirect = io.StringIO()

        entry_fun()
