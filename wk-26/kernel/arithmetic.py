from utils import output

def arithmetic_module(operation):
    try:
        output(eval(operation))
    except:
        pass
