#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

// глобальные переменные
const char tab[] = "\t     ";
const char space[] = "\n\n";
short difficulty, rnd;
short easy, average, difficult;

// прототипы функции
void error_text(void);
void game(void);

int main(void) {
    short choice; short * pC = &choice;
    fflush(stdout);
    while (1) {
        printf("%s\t     -УГАДАЙКА-%s%s%s", space, tab, space, space);
        printf("%s[1] Легкий%s%s[2] Средний%s%s[3] Сложный%s%s[4] Выход", tab, space, tab, space, tab, space, tab);
        printf("%s%s>>> ", space, tab);
        if (scanf("%hd", pC) != 1) 
            error_text();
        else if (choice > 0 && choice < 4)
            break;
        else if (choice == 4) {
            system("clear");
            exit(0);
        }
        else
            error_text();
    }
    system("clear");
    difficulty = choice;
    game();
    
    return 0;
}

// экран для вывода ошибки
void error_text(void) {
    system("clear");
    printf("%s%s%s%s !ошибка!\n", space, space, space, tab);
    while (getchar() != '\n');
    sleep(1);
    system("clear");
}

// текст победы
void victory(void) {
    system("clear");
    printf("%s%s%s%s !победа!\n", space, space, space, tab);
    sleep(1);
    system("clear");
}

// текст поражения
void loss(void) {
    system("clear");
    printf("%s%s%s%s !проигрыш!\n", space, space, space, tab);
    sleep(1);
    system("clear");
}

// логика игры
void game(void) {
    short choice; short * pC = &choice;
    srand(time(NULL));
    while (1) {
        switch (difficulty) {
            case 1: rnd = rand() % 3 + 1; break;
            case 2: rnd = rand() % 6 + 1; break;
            case 3: rnd = rand() % 10 + 1; break;
        }
        
        printf("%s\t%s%s%s", space,
        (difficulty == 1) ? "     -ЛЕГКИЙ-" :
        (difficulty == 2) ? "     -СРЕДНИЙ-" :
                            "     -СЛОЖНЫЙ-", tab, space);
        printf("\t%s%s%s",
        (difficulty == 1) ? "    |от 1 до 3|" :
        (difficulty == 2) ? "    |от 1 до 6|" :
                            "    |от 1 до 10|", tab, space);
        printf("\t    |победы:");
        printf(" %hd|%s",
        (difficulty == 1) ? easy :
        (difficulty == 2) ? average :
                            difficult, space);
        printf("\t    |0 – меню|");
        
        printf("%s%s>>> ", space, tab);
        if (scanf("%hd", pC) != 1) 
            error_text();
        else if (
        (difficulty == 1) ? *pC > 0 && *pC < 4 :
        (difficulty == 2) ? *pC > 0 && *pC < 7 :
                            *pC > 0 && *pC < 11)
            break;
        else if (*pC == 0) {
            system("clear");
            main();
        }
        else
            error_text();
    }
        
    switch (difficulty) {
        case 1:
            if (*pC == rnd) {
                victory();
                easy++;
                game();
            } else
                loss();
                game();
                break;
        case 2:
            if (*pC == rnd) {
                victory();
                average++;
                game();
            } else
                loss();
                game();
                break;
        case 3:
            if (*pC == rnd) {
                victory();
                difficult++;
                game();
            } else
                loss();
                game();
                break;
        }
    
}