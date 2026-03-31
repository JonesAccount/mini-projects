#include <stdio.h>
#include <stdbool.h>

#define CLEAR printf("\033[2J\033[H");

typedef unsigned short int usint;

void renderPlayfield(char *cells, char player);
void playerMove(char *cells, char player);


int main(void) {
	char player = 'X';
    char cells[] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'};

    printf("\033[?25l");

    while (true) {
    	CLEAR
    	renderPlayfield(cells, player);
     	playerMove(cells, player);
    }

    return 0;
}


void renderPlayfield(char *cells, char player) {
    printf("\n\t  КРЕСТИКИ-НОЛИКИ\n\n");

    for (int i = 0; i < 9; i++) {
        if ((i % 3) == 0) { printf("\n\t    "); }
        printf("  %c", cells[i]);
    }

    printf("\n\n\n\t      Ход: %c", player);
    printf("\n\t      Клетка: ");
}


void playerMove(char *cells, char player) {
	usint cellNumber;

	while (true) {
		if (scanf("%hd", &cellNumber) == 1) {
			cellNumber--;
			if (cells[cellNumber] != 'X' && cells[cellNumber] != 'O' ) {
				cells[cellNumber] = player;
				break;
			}
		} else {
			int c; while ((c = getchar()) != '\n' && c != EOF);
			CLEAR
			renderPlayfield(char *cells, char player)
			printf("\033[1A");
			printf("\033[2K");
		}
	}

}
