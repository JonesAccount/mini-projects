#include <stdbool.h>
#include <termios.h>
#include <stdlib.h>
#include <iso646.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

typedef unsigned short int usint;

void render(char *sudoky);
void creatPlayField(int *backSudoky, char *frontSudoky);
int cellSelection(char *frontSudoky, int *pTemporary);
void choiceNumber(char *frontSudoky, int *backSudoky, int cellNumber, int *pTemporary);
void menu(void);
char getch(void);

bool once = true;
usint lifes = 5;
usint win = 0, lose = 0;

int main(void) {
    srand(time(NULL));
    fflush(stdout);
    printf("\033[?25l");

    char frontSudoky[9];
    int backSudoky[9];
    int cellNumber, temporaryVariable;
    int *pTemporary = &temporaryVariable;

    while (1) {
        creatPlayField(backSudoky, frontSudoky);
        lifes = 5; once = true;
        printf("\033[H\033[J");
        menu();
        while (lifes > 0) {
            usint checkWin = 0;
            render(frontSudoky);
            cellNumber = cellSelection(frontSudoky, pTemporary);
            if (lifes == 0) break;
            choiceNumber(frontSudoky, backSudoky, cellNumber, pTemporary);

            for (int i = 0; i < 9; i++) {
                if (frontSudoky[i] == ' ') checkWin++;
            }

            if (checkWin == 0) { win++; break; }

        }

        if (lifes == 0) lose++;
    }

    return 0;
}


void render(char *sudoky) {
    if (once) {
        int counter = 0, index;
        while (counter != 4) {
            index = rand() % 9;
            if (sudoky[index] != ' ') {
                sudoky[index] = ' '; counter++;
            }
        }
        once = false;
    }
    printf("жизни: %hd", lifes);
    printf("\n——————————————");
    for (int i = 0; i < 9; i++) {
        if ((i % 3) == 0) printf("\n  ");
        printf("%c%s", sudoky[i], (i == 0 or i == 1 or i == 3 or i == 4 or i == 6 or i == 7) ? " | " : "");
    }
    printf("\n——————————————");
}


void creatPlayField(int *backSudoky, char *frontSudoky) {
    bool inspector;
    int candidate;

    for (int i = 0; i < 9; i++) {
        while (1) {
            inspector = true;
            candidate = rand() % 9 + 1;
            for (int j = 0; j < 9; j++) if (candidate == backSudoky[j]) inspector = false;
            if (inspector) { backSudoky[i] = candidate; break; }
        }
    }
    for (int i = 0; i < 9; i++)
        switch (backSudoky[i]) {
            case 1: frontSudoky[i] = '1'; break;
            case 2: frontSudoky[i] = '2'; break;
            case 3: frontSudoky[i] = '3'; break;
            case 4: frontSudoky[i] = '4'; break;
            case 5: frontSudoky[i] = '5'; break;
            case 6: frontSudoky[i] = '6'; break;
            case 7: frontSudoky[i] = '7'; break;
            case 8: frontSudoky[i] = '8'; break;
            case 9: frontSudoky[i] = '9';
        }
}


int cellSelection(char *frontSudoky, int *pTemporary) {
    while (1) {
        if (lifes == 0) return -1;
        printf("\033[H\033[J");
        render(frontSudoky);
        printf("\n- клетка: ");

        if (scanf("%d", pTemporary) != 1) {
            printf("\033[H\033[J"); render(frontSudoky);

            int ch;
            //while (getchar() != '\n'); continue;
            while((ch = getchar()) != '\n' && ch != EOF) {}
        }

        if (*pTemporary >= 1 && *pTemporary <= 9) {
            if (frontSudoky[*pTemporary - 1] == ' ') {
                return *pTemporary;
            } else {
                printf("\033[H\033[J"); render(frontSudoky);
            }
        } else {
            printf("\033[H\033[J");
            render(frontSudoky);
        }

    }

}


void choiceNumber(char *frontSudoky, int *backSudoky, int cellNumber, int *pTemporary) {
    while (1) {
        if (lifes == 0) break;
        printf("\033[H\033[J");
        render(frontSudoky);
                printf("\n- клетка: %d\n", cellNumber);
                printf("- число: ");

                if (scanf("%d", pTemporary) != 1) {
                    while (getchar() != '\n');
                    continue;
                }

                if (backSudoky[cellNumber - 1] == *pTemporary) {
                    switch (*pTemporary) {
                        case 1: frontSudoky[cellNumber - 1] = '1'; break;
                        case 2: frontSudoky[cellNumber - 1] = '2'; break;
                        case 3: frontSudoky[cellNumber - 1] = '3'; break;
                        case 4: frontSudoky[cellNumber - 1] = '4'; break;
                        case 5: frontSudoky[cellNumber - 1] = '5'; break;
                        case 6: frontSudoky[cellNumber - 1] = '6'; break;
                        case 7: frontSudoky[cellNumber - 1] = '7'; break;
                        case 8: frontSudoky[cellNumber - 1] = '8'; break;
                        case 9: frontSudoky[cellNumber - 1] = '9';
                    }
                    printf("\033[H\033[J");
                    printf("\033[32m");
                    render(frontSudoky);
                    printf("\n- клетка: %d\n", cellNumber);
                    printf("- число: %d", *pTemporary);
                    fflush(stdout);
                    usleep(195000);
                    printf("\033[0m");
                    printf("\033[H\033[J");
                    break;
                } else {
                    lifes--;
                    printf("\033[H\033[J");
                    printf("\033[31m");
                    render(frontSudoky);
                    printf("\n- клетка: %d\n", cellNumber);
                    printf("- число: ");
                    fflush(stdout);
                    usleep(195000);
                    printf("\033[0m");
                    printf("\033[H\033[J");
                    if (lifes == 0) break;
                    render(frontSudoky);

                }
            }
        }


void menu(void) {
	usint input;
    printf("\033[33m\033[1mСтатистика\033[0m\n");
    printf("- Победы: %hd\n- Поражения: %hd\n", win, lose);
    printf("\n- - - - - - - - - - - -\n");
    printf("[1] новая игра\n");
    printf("[0] выход");

    fflush(stdout);

    while (1) {
    	input = getch();
        if (input == '1') break;
        else if (input == '0') {printf("\033[H\033[J"); exit(1); }
        }
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
