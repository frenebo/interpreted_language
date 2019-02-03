import sys
import json
# import PIL

input_str = sys.stdin.read()

jsonVal = json.loads(input_str)

result = {}
for key in jsonVal:
    result[key] = jsonVal[key]*2

sys.stdout.write(json.dumps(result))
