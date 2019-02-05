import sys
import json

from zementis_interface import ZementisInterface

@ZementisInterface.set_entry_func("text", "text")
def text_doubler(input_text):
    return input_text.strip() + " !!! " + input_text.strip()

ZementisInterface.set_up_interface()

# class

# for line in sys.stdin:
#     sys.stderr.write("Got a line of stdin: " + line + "\n")
#     data = json.loads(line)
