from tkinter import *

window = Tk()

# ----------Настройки окна----------
window.title("Заметки")
window.config(background="black")
window.geometry("800x600")
window.resizable(0, 0)


# ----------Коллекции----------
id_notes = list()


# ----------Главная рамка----------
frm = Frame(
    master=window,
    relief=GROOVE,
    borderwidth=5
)


# ----------Тексты----------
lbl_title = Label(
    master=frm,
    text="- Менеджер заметок -",
    font=("Mono", 20, "bold"),
    fg="black",
)

lbl_space = Label(
    master=frm,
    text="",
    font=("Aqua Bold", 5, "bold"),
)


# ----------Поля----------
text_for_txt_input = "Поля для ввода"
txt_input = Text(
    master=frm,
    width=100,
    height=5,
    font=("Aqua Bold", 15),
    bg="#c2c2c2"
)
txt_input.insert(END, text_for_txt_input)

txt_saved = Text(
    master=frm,
    width=100,
    height=12,
    font=("Aqua Bold", 15),
    bg="#c2c2c2"
)


# ----------Функции----------
def clear():
    txt_input.delete("1.0", END)

counter = 1
def save_note():
    global counter
    if txt_input.get(1.0, END) != text_for_txt_input + "\n" and txt_input.get(1.0, END) != "\n" and txt_input.get(1.0, END) != " \n":
        txt_saved.insert(END, f"{counter}. {txt_input.get(1.0, END)}")
        id_notes.append(id(txt_input.get(1.0, END)))
        counter += 1

def del_all_notes():
    global counter
    counter = 1
    txt_saved.delete(1.0, END)


# ----------Кнопки----------
btn_clear = Button(
    master=frm,
    text="Очистить поле",
    font=("Aqua Bold", 15, "bold"),
    width=40,
    height=1,
    bg="white",
    command=clear
)

btn_save_notes = Button(
    master=frm,
    text="Сохранить заметку",
    font=("Aqua Bold", 15, "bold"),
    width=40,
    height=1,
    bg="white",
    command=save_note
)

btn_del_notes = Button(
    master=frm,
    text="Удалить заметки",
    font=("Aqua Bold", 15, "bold"),
    width=40,
    height=1,
    bg="white",
    command=del_all_notes
)


# ----------Отображение----------
frm.pack()

lbl_title.pack()

txt_input.pack()

btn_clear.pack()

lbl_space.pack()

btn_save_notes.pack()

txt_saved.pack()

btn_del_notes.pack()
