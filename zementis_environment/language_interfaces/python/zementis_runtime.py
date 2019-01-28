from runpy import run_path
from python_testing import ZementisInterface

import sys

if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise Exception("Program takes one argument: file name")

    name = sys.argv[1]

    run_path(name)
    ZementisInterface.test_run()
