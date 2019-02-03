import sys

sys.stderr.write("aaaa singleton\n")

while True:
    result = sys.stdin.read(1)
    sys.stderr.write(result)
# for line in sys.stdin:
    # sys.stderr.write(line)
