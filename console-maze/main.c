#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 6
#define COLS 12


char map[ROWS][COLS] = {
        "###########",
        "#      #  #",
        "# #  @    #",
        "#       # #",
        "#         #",
        "###########"
    };

char input;
short player_step = 0;
short player_x = 5;
short player_y = 2;
short new_x, new_y;

void show_map(void) {
    printf("\t       ·MAZE·\n");
    
    for (int i = 0; i < 37; i++)
        printf("—");
    
    printf("\n\n%s", map[0]);
    printf("    • move: WASD\n");
    
    printf("%s", map[1]);
    printf("\n");
    
    printf("%s", map[2]);
    printf("    • position: X-%hd, Y-%hd\n", player_x, player_y);
    
    printf("%s", map[3]);
    printf("\n");
    
    printf("%s", map[4]);
    printf("    • step: %hd\n", player_step);
    
    for (short i = 5; i < 6; i++)
        printf("%s\n", map[i]);
    
    printf("\n");
    for (int i = 0; i < 37; i++)
        printf("—");
}


int main(void) {
    fflush(stdout);
    while (1) {
        while (1) {
            show_map();
            printf("\n[?]: ");
            scanf(" %c", &input);
            if (input == 'w'  || input == 'a' || input == 's'  || input == 'd' 
                || input == 'W' || input == 'A' || input == 'S' || input == 'D')
                break;
            else {
                system("clear");
                show_map();
                printf("\n[?]: ");
                printf("error\n");
                int c; while ((c = getchar()) != '\n' && c != EOF);
                sleep(1);
                system("clear");
            }
        }
        
        new_x = player_x;
        new_y = player_y;
        
        if (input == 'w' || input == 'W') new_y--;
        if (input == 's' || input == 'S') new_y++;
        if (input == 'a' || input == 'A') new_x--;
        if (input == 'd' || input == 'D') new_x++;
        
        if (map[new_y][new_x] != '#') {
            map[player_y][player_x] = ' ';
            player_x = new_x;
            player_y = new_y;
            map[player_y][player_x] = '@';
            player_step++;
        }
        
        system("clear");
    }
    
    return 0;
}