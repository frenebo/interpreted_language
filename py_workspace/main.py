from workspace import DataWorkspace
from workspace.components import OneOffStdinStdoutComponent, InputComponent, OutputComponent, SingletonProcessComponent
import time

if __name__ == "__main__":
    workspace = DataWorkspace()

    workspace.add_component("input", InputComponent("text"))

    # workspace.add_component(
    #     "a",
    #     OneOffStdinStdoutComponent("cat", "text", "text")
    # )

    workspace.add_component(
        "a",
        SingletonProcessComponent(
            "python3 example_singleton.py",
            {"default": "text"},
            {"default": "text"},
        ),
    )

    workspace.add_component("output", OutputComponent("text"))

    workspace.add_connection("input", "a")
    workspace.add_connection("a", "output")

    workspace_instance = workspace.create_and_start_instance()
    print("created first")
    second_instance = workspace.create_and_start_instance()
    print("created second")


    while True:
        time.sleep(1)
