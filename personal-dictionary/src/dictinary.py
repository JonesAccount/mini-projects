from utils import AdditionalFunctions
from random import choice


class Functions:
    _dictionary = []
    _description_word = {}


    def show_all_words(self):
        if additionalfunctions.check_length(self._dictionary):
            print("-" * 35)
            print("📒 Ваш словарь:")
            for count in range(len(self._dictionary)):
                if count + 1 in self._description_word.keys():
                    print(f"{count + 1}. {self._dictionary[count].ljust(len(self._dictionary[count]) + 1, "+")}")
                else:
                    print(f"{count + 1}. {self._dictionary[count]}")
            if len(self._description_word) != 0:
                print("\n'+' означает что у слова есть описание")
        else:
            print("[😟] Ваш словарь пуст")



    def show_one_word(self):
        if additionalfunctions.check_length(self._dictionary):
            choice_word = input("[📖] Укажите индекс или слово: ")
            additionalfunctions.func_lower(choice_word.lower())
            try:
                if additionalfunctions.check_type(choice_word):
                    choice_word = int(choice_word)
                    if self._dictionary[choice_word - 1] in self._dictionary:
                        if choice_word in self._description_word.keys():
                            print(f"[✅] Ваше слово: {self._dictionary[choice_word - 1].ljust(len(self._dictionary[choice_word - 1]) + 1, "+")}")
                        else:
                            print(f"[✅] Ваше слово: {self._dictionary[choice_word - 1]}")
            except ValueError:
                if choice_word in self._dictionary:
                    word_index = self._dictionary.index(choice_word) + 1
                    if word_index in self._description_word.keys():
                        print(f"[✅] Ваше слово: {choice_word} +")
                    else:
                        print(f"[✅] Ваше слово: {choice_word}")
                else:
                    print("[🚫] Такое слово в словаре нет")
        else:
            print("[😟] Ваш словарь пуст")



    def add_word(self):
        while True:
            new_word = input("[✏️] Введите новое слово: ")
            if new_word.isalpha():
                self._dictionary.append(new_word)
                print("[✅] Новое слово добавлено: {new_word}".format(new_word=new_word))
                break
            else:
                print("[❌] Цифры использовать нельзя")



    def delete_word(self):
        if additionalfunctions.check_length(self._dictionary):
            choice_word = input("[📖] Укажите индекс или слово: ")
            additionalfunctions.func_lower(choice_word.lower())
            try:
                if additionalfunctions.check_type(choice_word):
                    choice_word = int(choice_word)
                    if self._dictionary[choice_word - 1] in self._dictionary:
                        print(f"[🗑️] Слово удалено: {self._dictionary[choice_word - 1]}")
                        self._dictionary.remove(self._dictionary[choice_word - 1])
            except ValueError:
                if choice_word in self._dictionary:
                    print("[🗑️] Слово удалено: {0}".format(choice_word))
                    self._dictionary.remove(choice_word)
                else:
                    print("[🚫] Такое слово в словаре нет")
        else:
            print("[😟] Удалить нечего")



    def clear_dictionary(self):
        if additionalfunctions.check_length(self._dictionary):
            self._dictionary.clear()
            print(f"[✅] Словарь полностью очищен")
        else:
            print("[😟] Удалять нечего")



    def generate_random_word(self):
        file = open("words.txt", "r", encoding="UTF-8")
        words = [line.strip() for line in file]
        new_word = choice(words)
        self._dictionary.append(new_word)
        file.close()
        print("[✅] Случайное слово добавлено: {var}".format(var=new_word))



    def add_description(self):
        if additionalfunctions.check_length(self._dictionary):
            choice_word = input("[📖] Куда добавим описание: ")
            additionalfunctions.func_lower(choice_word.lower())
            try:
                if additionalfunctions.check_type(choice_word):
                    choice_word = int(choice_word)
                    if self._dictionary[choice_word - 1] in self._dictionary:
                        value_word = input("[📝] Описание к слову: ")
                        self._description_word[choice_word] = value_word
            except ValueError:
                if choice_word in self._dictionary:
                    value_word = input("[📝] Описание к слову: ")
                    self._description_word[choice_word] = value_word
                else:
                    print("[🚫] Такое слово в словаре нет")
        else:
            print("[😟] Словарь пуст")



    def show_description(self):
        if additionalfunctions.check_length(self._dictionary):
            choice_word = input("[🗂️] Значение какого слово: ")
            additionalfunctions.func_lower(choice_word.lower())
            try:
                choice_word = int(choice_word)
                if additionalfunctions.check_type(choice_word):
                    if choice_word in self._description_word.keys():
                        print(f"[📁] Описание: {self._description_word[choice_word]}")
                    elif choice_word not in self._description_word.keys():
                        try:
                            if self._dictionary[choice_word - 1] in self._dictionary:
                                print("[☹️] Описание к этому слову нет")
                        except IndexError:
                            print("[❌] Не существующий индекс")
            except ValueError:
                choice_word = additionalfunctions.func_lower(choice_word.lower())
                word_index = self._dictionary.index(choice_word) + 1
                if choice_word in self._dictionary:
                    if word_index in self._description_word.keys():
                        print(f"[📁] Описание: {self._description_word[word_index]}")
                    else:
                        print("[☹️] Описание к этому слову нет")
                else:
                    print("[🚫] Такое слово в словаре нет")
        else:
            print("[😟] Словарь пуст")




    def exit_program(self):
        print("[❤️] Мне будет очень приятно если поставишь звезду ⭐️ на этот мини-проект. Пока)")


additionalfunctions = AdditionalFunctions()