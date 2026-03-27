#include "includes.h"

#define MAP_Y 34
#define MAP_X 57

#define VIEW_Y 11
#define VIEW_X 25

char map[30][51] = {
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
    "################ @      ##        ################",
    "################        ##   #  # ################",
    "################   ##   ##   #  # ################",
    "################   ##   ######  # ################",
    "################        ##      # ################",
    "################   ##           # ################",
    "################   ##   ######  # ################",
    "################        ######  # ################",
    "################   ##     #     # ################",
    "################   ##     #     # ################",
    "################            ##### ################",
    "##########################     ## ################",
    "##########################   #### ################",
    "################               ## ################",
    "################  ##########   ###################",
    "################           #    x ################",
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
    "##################################################",
};

short player_y = 7, player_x = 17;
short new_y, new_x;
char input;
bool separator = true;

short half_y = VIEW_Y / 2;
short half_x = VIEW_X / 2;

short my, mx;

void drawTile(char tile);
void show_map(void);
char getch1(void);
void move(void);


void easyStart(void) {
    printf("\033[?25l");
    while (separator) {
        show_map();
        move();
        printf("\033[H");
    }

    player_y = 7, player_x = 17;
    separator = true;
    map[22][32] = 'x';
}


void show_map(void) {
    for (int vy = 0; vy < VIEW_Y; vy++) {
        for (int vx = 0; vx < VIEW_X; vx++) {
            my = player_y - half_y + vy;
            mx = player_x - half_x + vx;

            if (vy == half_y && vx == half_x) {
                printf("@");
                continue;
            }

            if (my < 0 or my >= MAP_Y or mx < 0 or mx >= MAP_X) {
                printf(" ");
                continue;
            }

            drawTile(map[my][mx]);

        }
        printf("\n");
    }
}


void move(void) {
    input = tolower(getch1());

    new_y = player_y;
    new_x = player_x;

    switch (input) {
        case 'w': new_y--; break;
        case 'a': new_x--; break;
        case 's': new_y++; break;
        case 'd': new_x++; break;
    }

    if (map[new_y][new_x] == 'x') separator = false;

    if (map[new_y][new_x] != '#') {
        map[player_y][player_x] = ' ';
        player_y = new_y;
        player_x = new_x;
        map[player_y][player_x] = '@';
    }
}


void drawTile(char tile) {
    switch (tile) {
        case '#': printf("\033[100m\033[90m#\033[0m"); break;
        case '@': printf("\033[103m@\033[0m"); break;
        default:  printf("%c", tile);          break;
    }
}

char getch1(void) {
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
