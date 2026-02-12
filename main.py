from tkinter import *

window = Tk()

# ----------Page----------
window.title("Counter numbers")
window.config(bg="black")
window.geometry("800x600")
window.resizable(0, 0)


# ----------Variable----------
counter = 0


# ----------Frame----------
frm_page = Frame(
    master=window,
    relief=GROOVE,
    bg="purple",
    bd=10)


# ----------Show widgets----------
def plus_func():
    global counter
    counter += 1
    lbl_count.config(text=counter)

def minus_func():
    global counter
    counter -= 1
    lbl_count.config(text=counter)


# ----------Label----------
lbl_title = Label(
    master=frm_page,
    text="- COUNTER NUMBERS -",
    font=("small capital", 30, "bold"),
    fg="white",
    bg="purple")

lbl_count = Label(
    master=frm_page,
    text=counter,
    font=("sans-serif", 50, "bold"),
    fg="white",
    bg="purple")


# ----------Button----------
btn_plus = Button(
    master=frm_page,
    text="+",
    font=("Arial", 65),
    fg="white",
    bg="#8B008B",
    activebackground="#8B008B",
    command=plus_func)

btn_minus = Button(
    master=frm_page,
    text="-",
    font=("Arial", 65),
    fg="white",
    bg="#8B008B",
    activebackground="#8B008B",
    command=minus_func)


# ----------Show widgets----------
frm_page.pack(fill=BOTH, expand=1)

lbl_title.pack(side=TOP)
lbl_count.place(x=360, y=280)

btn_plus.pack(side=RIGHT)
btn_minus.pack(side=LEFT)


window.mainloop()
