#include <stdio.h>
#include <stdbool.h>

#define out printf
#define CLEAR_CONSOLE out("\033[2J\033[H");
#define CLEAR_INPUT CLEAR_CONSOLE; int c; while ((c = getchar()) != '\n' && c != EOF); renderPlayfield(cells, player);

typedef unsigned short int usint;

void renderPlayfield(char *cells, char player);
void playerMove(char *cells, char player);
void victoryCheck(char *cells);


int main(void) {
	char player = 'O';
    char cells[] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'};

    out("\033[?25l");

    while (true) {
    	CLEAR_CONSOLE
     	player = (player == 'X') ? 'O' : 'X';
    	renderPlayfield(cells, player);
     	playerMove(cells, player);
      	victoryCheck(cells);
    }

    return 0;
}


void renderPlayfield(char *cells, char player) {
    out("\n\t  КРЕСТИКИ-НОЛИКИ\n\n");

    for (int i = 0; i < 9; i++) {
        if ((i % 3) == 0) { out("\n\t    "); }
        out("  %c", cells[i]);
    }

    out("\n\n\n\t      Ход: %c", player);
    out("\n\t      Клетка: ");
}


void playerMove(char *cells, char player) {
	usint cellNumber;

	while (true) {
		if (scanf("%hu", &cellNumber) == 1) {
			if (cellNumber > 0 && cellNumber < 10) {
				cellNumber--;
				if (cells[cellNumber] != 'X' && cells[cellNumber] != 'O' ) {
					cells[cellNumber] = player;
					break;
				} else { CLEAR_INPUT }
			} else { CLEAR_INPUT }
		} else { CLEAR_INPUT }
	}
}


void victoryCheck(char *cells) {

}
