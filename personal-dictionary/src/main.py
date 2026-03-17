from dictinary import Functions


class Start:
    _command_user = None

    def __init__(self):
        print("\n🔸 ВАШ СОБСТВЕННЫЙ СЛОВАРЬ 🔸")

    def menu(self):
        print("-" * 35)
        print("""[1] Показать все слова
[2] Показать слово
[3] Добавить случайное слово
[4] Добавить слово
[5] Удалить слово
[6] Удалить все слова
[7] Добавить значение к слову
[8] Посмотреть значение
[9] Выйти""")
        print("-" * 35)
        self.commands()


    def commands(self):
        command_is_have = 0
        while True:
            self._command_user = input("[⚙️] Действие: ")
            try:
                self._command_user = int(self._command_user)
                if self._command_user == 1:
                    functions.show_all_words()
                    start.menu()
                elif self._command_user == 2:
                    functions.show_one_word()
                    start.menu()
                elif self._command_user == 3:
                    functions.generate_random_word()
                    start.menu()
                elif self._command_user == 4:
                    functions.add_word()
                elif self._command_user == 5:
                    functions.delete_word()
                    start.menu()
                elif self._command_user == 6:
                    functions.clear_dictionary()
                    start.menu()
                elif self._command_user == 7:
                    functions.add_description()
                    start.menu()
                elif self._command_user == 8:
                    functions.show_description()
                    start.menu()
                elif self._command_user == 9:
                    functions.exit_program()
                    break
                else:
                    command_is_have += 1

            except ValueError:
                if self._command_user.lower() == "показать все слова":
                    functions.show_all_words()
                    start.menu()
                elif self._command_user.lower() == "показать слово":
                    functions.show_one_word()
                    start.menu()
                elif self._command_user.lower() == "добавить слово":
                    functions.add_word()
                    start.menu()
                elif self._command_user.lower() == "удалить слово":
                    functions.delete_word()
                elif self._command_user.lower() == "удалить все слова":
                    functions.clear_dictionary()
                    start.menu()
                elif self._command_user.lower() == "добавить случайное слово":
                    functions.generate_random_word()
                    start.menu()
                elif self._command_user.lower() == "добавить значение к слову":
                    functions.add_description()
                    start.menu()
                elif self._command_user.lower() == "посмотреть значение":
                    functions.show_description()
                    start.menu()
                elif self._command_user.lower() == "выйти":
                    functions.exit_program()
                    break
                else:
                    command_is_have += 1

            if command_is_have != 0:
                print("[❌] Такой команды не существует")


functions = Functions()
start = Start()
start.menu()