from os import system, name

output = print
newline = "\n"
prompt = ">>> "


def clear():
    system('cls' if name == 'nt' else 'clear')
