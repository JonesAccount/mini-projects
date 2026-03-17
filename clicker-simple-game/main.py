from tkinter import *
from random import randint

window = Tk()

# ----------Page----------
window.title("Миллионер: Игра-кликер!")
window.config(bg="black")
window.geometry("600x800")
window.resizable(0, 0)


# ----------Variable----------
coin = 0
lvl_click = 1
up_click_price = 50
up_autoclick_price = 100
random_bonus = None
random_bonus_click = None
click_visual = 0


# ----------Function----------
def click():
    global coin, random_bonus, click_visual, random_bonus_click
    random_bonus = randint(1, 20)
    if random_bonus == 1:
        random_bonus_click = lvl_click + randint(1, 10)
        click_visual = random_bonus_click
        coin += random_bonus_click
        lbl_coin_counter.config(text=coin)
        lbl_click_visual.config(text=click_visual)
        lbl_click_visual.place(x=randint(200, 400), y=randint(180, 300))
    else:
        click_visual = lvl_click
        coin += click_visual
        lbl_coin_counter.config(text=coin)
        lbl_click_visual.config(text=click_visual)
        lbl_click_visual.place(x=randint(200, 400), y=randint(180, 300))

def up_click():
    global lvl_click, up_click_price, coin
    if coin >= up_click_price:
        lvl_click += 1
        coin -= up_click_price
        up_click_price *= 2
        lbl_coin_counter.config(text=coin)
        btn_up_click.config(text=f"цена: {up_click_price}")
        lbl_info_click.config(text=f"Клик: {lvl_click}")


# ----------Frame----------
frm_top = Frame(
    master=window,
    bg="#4B0082",
    width=600,
    height=100,
    relief=SUNKEN,
    bd=10)

frm_center = Frame(
    master=window,
    bg="#4B0082",
    width=600,
    height=500,
    relief = SUNKEN,
    bd = 10)

frm_bottom = Frame(
    master=window,
    bg="#4B0082",
    width=600,
    height=200,
    relief = SUNKEN,
    bd = 10)


# ----------Label----------
lbl_coin_counter = Label(
    master=frm_center,
    text=coin,
    font=("Arial", 45, "bold"),
    bg="#4B0082",
    fg="black")

lbl_coin_text = Label(
    master=frm_center,
    text="монеты",
    font=("Arial", 45, "bold"),
    fg="orange",
    bg="#4B0082")

lbl_up_click = Label(
    master=frm_bottom,
    text="Прокачать клик",
    font=("Arial", 20, "bold"),
    fg="white",
    bg="#4B0082")

lbl_up_autoclick = Label(
    master=frm_bottom,
    text="Прокачать автоклик",
    font=("Arial", 20, "bold"),
    fg="white",
    bg="#4B0082")

lbl_info_click = Label(
    master=frm_center,
    text=f"Клик: {lvl_click}",
    font=("Arial", 20, "bold"),
    fg="white",
    bg="#4B0082")

lbl_info_autoclick = Label(
    master=frm_center,
    text=f"Автоклик: 0",
    font=("Arial", 20, "bold"),
    fg="white",
    bg="#4B0082")

lbl_click_visual = Label(
    master=frm_center,
    text=click_visual,
    font=("Arial", 20, "bold"),
    fg="gray",
    bg="#4B0082")

lbl_title = Label(
    master=frm_top,
    text="!! КЛИКАЕМ !!",
    font=("Arial", 50, "bold"),
    fg="white",
    bg="#4B0082")


# ----------Entry----------


# ----------Text----------


# ----------Button----------
btn_click = Button(
    master=frm_center,
    text="клик",
    font=("Arial", 45, "bold"),
    relief = RIDGE,
    bd=7,
    bg="#6A5ACD",
    activebackground="#4B0082",
    command=click)

btn_up_click = Button(
    master=frm_bottom,
    text=f"цена: {up_click_price}",
    font=("Arial", 30, "bold"),
    relief=RIDGE,
    bd=7,
    bg="#6A5ACD",
    activebackground="#4B0082",
    command=up_click)

btn_up_autoclick = Button(
    master=frm_bottom,
    text=f"цена: {up_autoclick_price}",
    font=("Arial", 30, "bold"),
    relief=RIDGE,
    bd=7,
    bg="#6A5ACD",
    activebackground="#4B0082",)


# ----------Show widget----------
frm_top.place(x=0)
frm_center.place(y=100)
frm_bottom.place(y=600)

lbl_title.place(relx=0.5, rely=0.5, anchor="center")
lbl_coin_counter.place(relx=0.5, rely=0.5, anchor="center")
lbl_coin_text.place(relx=0.5, y=130, anchor="center")
lbl_up_click.place(x=150, y=150, anchor="center")
lbl_up_autoclick.place(x=400, y=150, anchor="center")
lbl_info_click.place(x=40, y=20, anchor="center")
lbl_info_autoclick.place(x=63, y=50, anchor="center")
lbl_click_visual.place(x=1000, y=1000, anchor="center")

btn_click.place(relx=0.5, y=350, anchor="center")
btn_up_click.place(x=150, rely=0.5, anchor="center")
btn_up_autoclick.place(x=400, rely=0.5, anchor="center")



window.mainloop()