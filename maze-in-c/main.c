#include "includes.h"
#include "maze1.h"
#include "maze2.h"
#include "maze3.h"

// --------------------------Страницы---------------------------
char menu_page[16][40] = {"                                       ",
                          "                  MAZE                 ",
                          "                                       ",
                          "                                       ",
                          "                                        ",
                          "                                       ",
                          "                                       ",
                          "                [P] Play               ",
                          "                                       ",
                          "                [Q] Quit               ",
                          "                                       ",
                          "                                       ",
                          "                                       ",
                          "                                       ",
                          "                                       ",
                          "v 0.1                                  "

};

char levels_page[16][40] = {"                                       ",
                            "                 LEVELS                ",
                            "                                       ",
                            "                                       ",
                            "                                       ",
                            "                                       ",
                            "           [1] Difficulty: Easy        ",
                            "                                       ",
                            "                                       ",
                            "           [2] Difficulty: Medium      ",
                            "                                       ",
                            "                                       ",
                            "           [3] Difficulty: Hard        ",
                            "                                       ",
                            "                                       ",
                            "                                       "};

// --------------------------Переменные---------------------------
char choice;

// ----------------------Прототипы функции------------------------
void menu(void);
void levels(void);
char getch(void);

// ----------------------Главная функция--------------------------
int main(void) {
  printf("\033[?25l");
  while (1) menu();
  return 0;
}

// --------------------------Функции------------------------------
void menu(void) {
  for (int i = 0; i < 16; i++) printf("%s\n", menu_page[i]);

  while (1) {
  		choice = tolower(getch());
    	if (choice == 'p' or choice == 'q') break;
  }

  switch (choice) {
  	case 'p':
    	system("clear");
     	levels();
      	break;
    case 'q':
    	system("clear");
     	exit(0);
  }

}

void levels(void) {
  for (int i = 0; i < 16; i++) printf("%s\n", levels_page[i]);

  while (1) {
		choice = getch();
    	if (choice == '1' or choice == '2' or choice == '3') break;
  }

  switch (choice) {
  	case '1':
    	system("clear");
     	easyStart();
      	break;
    case '2':
    	system("clear");
     	mediumStart();
      	break;
    case '3':
    	system("clear");
     	hardStart();
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
