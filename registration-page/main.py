from os import ftruncate

from flet.controls.border_radius import horizontal
import flet as ft


def main(page: ft.Page):
    page.title = "Регистрация"
    page.theme_mode = "black"

    text1 = ft.Text(value="ПРОЙТИ ", size=50, weight="bold", color="yellow")
    text2 = ft.Text(value="РЕГИСТРАЦИЮ", size=50, weight="bold", color="red")
    text3 = ft.Text(value="!", size=50, weight="bold", color="yellow")
    text4 = ft.Text(value="✕        ", size=20, color="orange")
    space = ft.Text(" ")

    login_field = ft.TextField(label="Логин или телефон *", color="grey", hint_text="pavel durov", hint_style=ft.TextStyle(color="grey"), width=300)
    password_field = ft.TextField(label="Пароль *", color="grey", hint_text="12345", hint_style=ft.TextStyle(color="grey"), width=300)
    password_help = ft.Text(value="Забыли пароль?", color="orange", size=13)

    button_log = ft.ElevatedButton("Войти", color="orange", width=300, height=45)

    page.add(
        ft.Row(
            controls=[
                text4
            ],
            alignment=ft.MainAxisAlignment.END
        ),
        ft.Row(
            controls=[
                text1, text2, text3
            ],
            alignment=ft.MainAxisAlignment.CENTER
        ),
        ft.Row(controls=[space], alignment=ft.MainAxisAlignment.CENTER),
        ft.Row(controls=[space], alignment=ft.MainAxisAlignment.CENTER),
        ft.Row(
            controls=[
                login_field
            ],
            alignment=ft.MainAxisAlignment.CENTER
        ),
        ft.Row(controls=[space], alignment=ft.MainAxisAlignment.CENTER),
        ft.Row(controls=[space], alignment=ft.MainAxisAlignment.CENTER),
        ft.Row(
            controls=[
                password_field
            ],
            alignment=ft.MainAxisAlignment.CENTER
        ),
        ft.Row(
            controls=[
                password_help
            ],
            alignment=ft.MainAxisAlignment.CENTER
        ),
        ft.Row(controls=[space], alignment=ft.MainAxisAlignment.CENTER),
        ft.Row(controls=[space], alignment=ft.MainAxisAlignment.CENTER),
        ft.Row(
            controls=[
                button_log
            ],
            alignment=ft.MainAxisAlignment.CENTER
        )
    )

    page.update()

if __name__ == "__main__":
    ft.run(main)