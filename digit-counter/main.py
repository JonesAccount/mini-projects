from tkinter.ttk import Progressbar
import flet as ft

def main(page: ft.Page):
    page.title = "Программа счетчик"
    page.vertical_alignment = ft.MainAxisAlignment.CENTER
    page.horizontal_alignment = ft.CrossAxisAlignment.CENTER


    def click_minus():
        nonlocal counter, progress
        if counter != 0:
            counter -= 1
            progress.value -= 0.1
        counter_display.value = str(counter)


    def click_plus():
        nonlocal counter, progress
        if counter != 10:
            counter += 1
            progress.value += 0.1
        counter_display.value = str(counter)


    progress = ft.ProgressBar(width=500, height=5, value=0, bgcolor=ft.Colors.GREY_700, color=ft.Colors.YELLOW_700)
    counter = 0
    counter_display = ft.Text(value=str(counter), size=20)
    space = ft.Text(" ")


    text_container = ft.Container(
        content=ft.Text("СЧЕТЧИК ЦИФР", color="yellow", weight="bold"),
        bgcolor=ft.Colors.GREY_900,
        width=600,
        height=65,
        padding=20,
        margin=1,
        border_radius=10,
        border=ft.border.all(
            width=3,
            color=ft.Colors.GREY_700,
        ),
        alignment=ft.alignment.Alignment.CENTER
    )


    logic = ft.Container(
        content=ft.Column(
            controls=[
                ft.Row(
                    controls=[
                        ft.ElevatedButton("-", style=ft.ButtonStyle(text_style=ft.TextStyle(size=30)), color="white",
                                          width=150, height=100, on_click=click_minus),
                        ft.Container(
                            content=counter_display,
                            bgcolor=ft.Colors.GREY_900,
                            width=230,
                            height=80,
                            padding=20,
                            margin=1,
                            border_radius=10,
                            border=ft.border.all(
                                width=3,
                                color=ft.Colors.GREY_700
                            ),
                            alignment=ft.alignment.Alignment.CENTER
                        ),
                        ft.ElevatedButton("+", style=ft.ButtonStyle(text_style=ft.TextStyle(size=30)), color="white",
                                          width=150, height=100, on_click=click_plus)
                    ]
                ),
                ft.Row(
                    controls=[
                        space
                    ]
                ),
                ft.Row(
                    controls=[
                        ft.Divider(thickness=6, color=ft.Colors.GREY_700, radius=5, expand=True)
                    ]
                ),
                ft.Row(
                    controls=[
                        space
                    ]
                ),
                ft.Row(
                    alignment=ft.MainAxisAlignment.CENTER,
                    controls=[progress]
                )
            ]
        ),
        bgcolor=ft.Colors.GREY_900,
        width=600,
        height=300,
        padding=20,
        margin=1,
        border_radius=10,
        border=ft.border.all(
            width=3,
            color=ft.Colors.GREY_700
        ),
        alignment=ft.alignment.Alignment.CENTER
    )


    page.add(
        ft.Column(
            alignment=ft.MainAxisAlignment.CENTER,
            horizontal_alignment=ft.CrossAxisAlignment.CENTER,
            controls=[
                text_container,
                logic
            ]
        )
    )

if __name__ == "__main__":
    ft.run(main)