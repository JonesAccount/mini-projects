#include "includes.h"

#define MAP_Y2 32
#define MAP_X2 59

#define VIEW_Y2 11
#define VIEW_X2 25

char map2[MAP_Y2][MAP_X2] = {
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "################# @            #   #     #################",
    "#####################  ######  #   #     #################",
    "#################   #       #  #   #  ####################",
    "#################   ####### #            #################",
    "#################    #   #  ##### ###    #################",
    "#################    #      #     #      #################",
    "#################    ###### ###   #      #################",
    "#################         #  ###  #   ####################",
    "#################  #  ##     ###  #      #################",
    "#################  #      #  ###  #      #################",
    "###########################       #      #################",
    "#################   ##   ##########  ## ##################",
    "##################                   ##  #################",
    "#################   ###################  #################",
    "#################   ####    ##           #################",
    "#################   #    ## ## ####### ###################",
    "#####################  #### ## #####     #################",
    "################# x      ##    #####     #################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
    "##########################################################",
};

short player_y2 = 7, player_x2 = 18;
short new_y2, new_x2;
char input2;
bool separator2 = true;

short half_y2 = VIEW_Y2 / 2;
short half_x2 = VIEW_X2 / 2;

short my2, mx2;

void drawTile2(char tile);
void show_map2(void);
char getch2(void);
void move2(void);


void mediumStart(void) {
    printf("\033[?25l");
    while (separator2) {
        show_map2();
        move2();
        printf("\033[H");
    }

    player_y2 = 7, player_x2 = 17;
    separator2 = true;
    map2[24][18] = 'x';
}


void show_map2(void) {
    for (int vy = 0; vy < VIEW_Y2; vy++) {
        for (int vx = 0; vx < VIEW_X2; vx++) {
            my2 = player_y2 - half_y2 + vy;
            mx2 = player_x2 - half_x2 + vx;

            if (vy == half_y2 && vx == half_x2) {
                printf("@");
                continue;
            }

            if (my2 < 0 or my2 >= MAP_Y2 or mx2 < 0 or mx2 >= MAP_X2) {
                printf(" ");
                continue;
            }

            drawTile2(map2[my2][mx2]);

        }
        printf("\n");
    }
}


void move2(void) {
    input2 = tolower(getch2());

    new_y2 = player_y2;
    new_x2 = player_x2;

    switch (input2) {
        case 'w': new_y2--; break;
        case 'a': new_x2--; break;
        case 's': new_y2++; break;
        case 'd': new_x2++; break;
    }

    if (map2[new_y2][new_x2] == 'x') separator2 = false;

    if (map2[new_y2][new_x2] != '#') {
        map2[player_y2][player_x2] = ' ';
        player_y2 = new_y2;
        player_x2 = new_x2;
        map2[player_y2][player_x2] = '@';
    }
}


void drawTile2(char tile) {
    switch (tile) {
        case '#': printf("\033[100m\033[90m#\033[0m"); break;
        case '@': printf("\033[103m@\033[0m"); break;
        default:  printf("%c", tile);          break;
    }
}

char getch2(void) {
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