from python_testing import ZementisInterface

@ZementisInterface.set_entry_func(input_type="json", output_type="json")
def ex_func(input_obj):
    output_obj = {}

    for key in input_obj:
        output_obj[key] = input_obj[key]*2

    return output_obj

ZementisInterface.set_up_interface()
