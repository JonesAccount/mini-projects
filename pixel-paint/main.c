#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

#define LINE for (int i = 0; i < 30; i++) { printf("\033[1;90;47m—\033[0m"); }
#define CANVAS_SIZE 100

void render_canvas(int *canvas, char color);
char choice_color(void);
void drawing(int *canvas, char color);
char getch(void);
void clear_screen(void);

int main(void) {
    printf("\033[?25l");

    // создание холста
    int *canvas = (int *)malloc(CANVAS_SIZE);
    if (NULL == canvas) { return 1; }

    for (size_t i = 0; i < CANVAS_SIZE; i++) {
        canvas[i] = i;
    }

    // переменные
    char select_color = 113;

    // главный цикл
    while (1) {
        // рендер интерфейса
        render_canvas(canvas, select_color);

        // выбор цвета
        select_color = choice_color();

        // рисование
        drawing(canvas, select_color);

        // чистка экрана
        clear_screen();
    }

    return 0;
}

void render_canvas(int *canvas, char color) {
    // заголовок
    for (int i = 0; i < 22; i++) {
        if (i == 11) {
            printf("\033[1;90;47m\033[31mT\033[38;5;22mH\033[38;5;208mE \033[34mP\033[35mA\033[38;5;202mI\033[38;5;27mN\033[31mT\033[0m");
        } else {
            printf("\033[1;90;47m \033[0m");

        }
    }

    // холст:
    LINE
    for (size_t i = 0; i < CANVAS_SIZE; i++) {
        if (i == 0) { printf("\n"); }

        if (i == 13  i == 14  i == 15  i == 16  i == 23  i == 26  i == 22  i == 32  i == 27  i == 37  i == 31  i == 38 | i == 41  i == 51  i == 61  i == 48  i == 58  i == 68  i == 62  i == 63  i == 66  i == 67  i == 73  i == 83  i == 93  i == 76  i == 86  i == 96  i == 94  i == 95) {
            printf("\033[30;40m%d \033[0m", canvas[i]);
        } else if (i == 85  i == 84  i == 74 || i == 75) {
            printf("\033[33;43m%d \033[0m", canvas[i]);
        } else if (i == 46  i == 34  i == 43) {
            printf("\033[37;47m%d \033[0m", canvas[i]);
        } else if (i == 24  i == 25  i == 33  i == 35  i == 36  i == 47  i == 57  i == 42  i == 52  i == 44  i == 54  i == 64  i == 53  i == 45  i == 55  i == 65  i == 56) {
            printf("\033[31;41m%d \033[0m", canvas[i]);
        } else {
            printf("\033[30;47m%s%d \033[0m", (i < 10) ? "0" : "", canvas[i]);

        }

        if (((i + 1) % 10) == 0) { printf("\n"); }
    }
    LINE

    // заголовок тонов:
    for (int i = 0; i < 25; i++) {
        if (i == 12) {
            printf("\033[1;90;47mshades\033[0m");
        } else {
            printf("\033[1;90;47m \033[0m");
        }

        if (((i + 1) % 25) == 0) { printf("\n"); }
    }

    // пустое место
    for (int i = 0; i < 30; i++) {
        printf("\033[1;90;47m \033[0m");

    }

    // тоны
    for (int i = 0; i < 30; i++) {
        if (i == 2) {
            printf("\033[41m \033[0m");
        } else if (i == 6) {
            printf("\033[48;5;208m \033[0m");
        } else if (i == 10) {
            printf("\033[48;5;226m \033[0m");
        } else if (i == 14) {
            printf("\033[42m \033[0m");
        } else if (i == 18) {
            printf("\033[46m \033[0m");
        } else if (i == 22) {
            printf("\033[44m \033[0m");
        } else if (i == 26) {
            printf("\033[45m \033[0m");
        } else {
            printf("\033[1;90;47m \033[0m");
        }

    }

    // ключи тонов
    for (int i = 0; i < 30; i++) {
        if (i == 2) {
            printf("\033[1;%s;47mq\033[0m", (color == 'q') ? "34" : "90");
        } else if (i == 6) {
            printf("\033[1;%s;47mw\033[0m", (color == 'w') ? "34" : "90");
        } else if (i == 10) {
                    printf("\033[1;%s;47me\033[0m", (color == 'e') ? "34" : "90");
                } else if (i == 14) {
                    printf("\033[1;%s;47mr\033[0m", (color == 'r') ? "34" : "90");
                } else if (i == 18) {
                    printf("\033[1;%s;47mt\033[0m", (color == 't') ? "34" : "90");
                } else if (i == 22) {
                    printf("\033[1;%s;47my\033[0m", (color == 'y') ? "34" : "90");
                } else if (i == 26) {
                    printf("\033[1;%s;47mu\033[0m", (color == 'u') ? "34" : "90");
                } else {
                    printf("\033[1;90;47m \033[0m");
                }

            }

            // пустое место
            for (int i = 0; i < 30; i++) {
                printf("\033[1;90;47m \033[0m");

            }

        }

        char choice_color(void) {
            char ch = tolower(getch());

                switch (ch) {
                    case 'q': ch = 113; break;
                    case 'w': ch = 119; break;
                    case 'e': ch = 101; break;
                    case 'r': ch = 114; break;
                    case 't': ch = 116; break;
                    case 'y': ch = 121; break;
                    case 'u': ch = 117;
                }

            return ch;
        }

        void drawing(int *canvas, char color) {
            char ch = getch();
        }

        char getch(void) {
            struct termios oldt, newt;
            char ch;
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            ch = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            return ch;
        }

        void clear_screen(void) {
            fputs("\033[2J\033[H", stdout);
            fflush(stdout);
        }
