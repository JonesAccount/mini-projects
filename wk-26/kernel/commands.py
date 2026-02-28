from utils import clear, output, newline


def commands_module():
        clear()
        orders = ("terminal/term – терминал", "help – помощь")
        for el in orders:
            output(":", el, sep="")
        try:
            command = input(f"{newline}Enter")
            clear()
            from terminal import terminal_module
            terminal_module()
        except:
            pass
