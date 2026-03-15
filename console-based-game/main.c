#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define ROWS 10
#define COLS 20 + 1

// карта
char map[ROWS][COLS] = {"####################", "#                  #",
                        "#   ####       #   #", "#      #           #",
                        "#      #  @        #", "#                  #",
                        "#####              #", "#          ####    #",
                        "#                  #", "####################"};

// переменные
short player_y = 4;
short player_x = 10;
short new_x, new_y;

short limit_gold = 3;
short gold_x, gold_y;
short gold = 0;

char input;

// показать карту
void show_map(void);

// отрисовка золота
void add_gold(void);

// отрисовка линии
void line(void);

// движение
void move(void);

// raw mode (читать команды без нажатия enter)
char getch(void);

int main(void) {
  srand(time(NULL));
  add_gold();
  while (1) {
    system("clear");
    show_map();
    move();
  }
}

void show_map(void) {
  line();
  printf("\n Gold: %hd\n\n", gold);
  for (int i = 0; i < 10; i++)
    printf("\t %s\n", map[i]);
  printf("\n");
  line();
  printf("\n move: WASD");
  printf("\n exit: Q\n");
}

void add_gold(void) {
  while (limit_gold > 0) {
    for (int i = 0; i < limit_gold; i++) {
      gold_x = rand() % 18 + 1;
      gold_y = rand() % 9;

      if (map[gold_y][gold_x] != '#' && map[gold_y][gold_x] != '$' &&
          map[gold_y][gold_x] != '@') {
        map[gold_y][gold_x] = '$';
        limit_gold--;
        system("clear");
        show_map();
      }
    }
  }
}

void line(void) {
  for (int i = 0; i < 37; i++)
    printf("—");
}

void move(void) {
  while (true) {
    input = getch();

    if (input == 'w' || input == 'a' || input == 's' || input == 'd' ||
        input == 'q' || input == 'W' || input == 'A' || input == 'S' ||
        input == 'D' || input == 'Q')
      break;
    else {
      system("clear");
      show_map();
    }
  }

  new_y = player_y;
  new_x = player_x;

  if (input == 'w' || input == 'W')
    new_y--;
  if (input == 'a' || input == 'A')
    new_x--;
  if (input == 's' || input == 'S')
    new_y++;
  if (input == 'd' || input == 'D')
    new_x++;
  if (input == 'q' || input == 'Q') {
    system("clear");
    exit(1);
  }

  if (map[new_y][new_x] != '#') {
    if (map[new_y][new_x] == '$') {
      gold++;
      limit_gold++;
    }
    add_gold();
    map[player_y][player_x] = ' ';
    player_y = new_y;
    player_x = new_x;
    map[player_y][player_x] = '@';
  }
}

char getch(void) {
  struct termios oldt, newt;
  char ch;

  tcgetattr(STDIN_FILENO, &oldt); // сохранить настройки
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO); // отключить буфер и эхо
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // восстановить настройки
  return ch;
}
