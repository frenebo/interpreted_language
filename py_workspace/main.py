from workspace import DataWorkspace
from workspace.components import OneOffStdinStdoutComponent, InputComponent, OutputComponent
import time

if __name__ == "__main__":
    workspace = DataWorkspace()

    workspace.add_component("input", InputComponent("text"))

    workspace.add_component(
        "a",
        OneOffStdinStdoutComponent("ls", "text", "text")
    )

    workspace.add_component(
        "b",
        OneOffStdinStdoutComponent("ls", "text", "text")
    )

    workspace.add_component("output", OutputComponent("text"))

    workspace.add_connection("input", "a")
    workspace.add_connection("a", "b")
    workspace.add_connection("b", "output")

    workspace_instance = workspace.create_and_start_instance()

    while True:
        time.sleep(1)
