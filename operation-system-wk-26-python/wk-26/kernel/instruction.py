from utils import clear, output, newline


def menu():
    clear()
    output(f"[1] Команды{newline}[2] Утилиты{newline}[3] Файловая система{newline}[4] Об WK-26{newline}")
    try:
        command = int(input("Input: "))
        if command == 1:
            from commands import commands_module
            commands_module()
    except:
        pass
