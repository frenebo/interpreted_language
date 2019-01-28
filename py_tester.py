from python_testing import ZementisInterface

@ZementisInterface.set_entry_func(input_type="json", output_type="json")
def ex_func(in_obj):
    return in_obj

ZementisInterface.set_up_interface()
