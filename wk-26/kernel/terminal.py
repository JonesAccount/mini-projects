from utils import clear, output, newline, prompt
from arithmetic import arithmetic_module


def terminal_module():
    clear()
    output(f"{newline * 2}Консольная система WK-26{newline}{"– " * 20}")
    output(f"Терминал | help для справки{newline}")
    while True:
        command = input(prompt)
        if command[0].isdigit() or command[1].isdigit() if len(command) > 1 else False:
            arithmetic_module(command)
        elif command.lower() == "help":
            from instruction import menu
            menu()
        