#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>


#define out printf
#define CLEAR_CONSOLE out("\033[2J\033[H");
#define CLEAR_INPUT CLEAR_CONSOLE; int c; while ((c = getchar()) != '\n' && c != EOF); renderPlayfield(cells, player, winCheck);

typedef unsigned short int usint;

void renderPlayfield(char *cells, char player, bool winCheck);
void playerMove(char *cells, char player, bool winCheck);
bool victoryCheck(char *cells, char player, bool winCheck);
char getch(void);

bool standoff = false;

int main(void) {
	char player = 'O';
	bool winCheck = false;

	usint winsO = 0;
	usint winsX = 0;

    char cells[] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'};

    out("\033[?25l");

    while (true) {
    	CLEAR_CONSOLE
     	player = (player == 'X') ? 'O' : 'X';

      	if (winCheck != true && standoff != true) {
      		renderPlayfield(cells, player, winCheck);
       		playerMove(cells, player, winCheck);
        	winCheck = victoryCheck(cells, player, winCheck);
       } else if (winCheck == true && standoff != true) {
       		renderPlayfield(cells, player, winCheck);
       	 	printf("\n\n\n       Игрок ");
          	switch (player) {
           		case 'X': printf("\033[32mO\033[0m"); break;
             	case 'O': printf("\033[31mX\033[0m");
           	}
           	printf(" победил!");
          	while (1) { char c; c = getch(); if (c == ' ') { break; } }
            for (int i = 0; i < 9; i++) { cells[i] = i + 1 + '0'; }
            winCheck = false;
       } else if (standoff == true && winCheck != true) {
       		renderPlayfield(cells, player, winCheck);
     	 	printf("\n\n\n\t    Ничья");
        	while (1) { char c; c = getch(); if (c == ' ') { break; } }
          	for (int i = 0; i < 9; i++) { cells[i] = i + 1 + '0'; }
           	standoff = false;
       }
    }

    return 0;
}


void renderPlayfield(char *cells, char player, bool winCheck) {
    out("\n\n     \033[1m\033[31mX\033[0m\033[1m КРЕСТИКИ-НОЛИКИ \033[32mO\033[0m\033[0m\n\n");

    for (int i = 0; i < 9; i++) {
        if ((i % 3) == 0) { out("\n\t "); }

        if (cells[i] == 'X') {
        	out("\033[31m  X\033[0m");
        } else if (cells[i] == 'O') {
        	out("\033[32m  O\033[0m");
        } else {
        	out("  %c", cells[i]);
        }
    }

    if (winCheck != true && standoff != true) {
    	out("\n\n\n\t   Ход: %c", player);
     	out("\n\t   Клетка: ");
    }
}


void playerMove(char *cells, char player, bool winCheck) {
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


bool victoryCheck(char *cells, char player, bool winCheck) {
	if (cells[0] == 'X' && cells[1] == 'X' && cells[2] == 'X') { winCheck = true; }
	if (cells[3] == 'X' && cells[4] == 'X' && cells[5] == 'X') { winCheck = true; }
	if (cells[6] == 'X' && cells[7] == 'X' && cells[8] == 'X') { winCheck = true; }

	if (cells[0] == 'X' && cells[3] == 'X' && cells[6] == 'X') { winCheck = true; }
	if (cells[1] == 'X' && cells[4] == 'X' && cells[7] == 'X') { winCheck = true; }
	if (cells[2] == 'X' && cells[5] == 'X' && cells[8] == 'X') { winCheck = true; }

	if (cells[0] == 'X' && cells[4] == 'X' && cells[8] == 'X') { winCheck = true; }
	if (cells[2] == 'X' && cells[4] == 'X' && cells[6] == 'X') { winCheck = true; }

	if (cells[0] == 'O' && cells[1] == 'O' && cells[2] == 'O') { winCheck = true; }
	if (cells[3] == 'O' && cells[4] == 'O' && cells[5] == 'O') { winCheck = true; }
	if (cells[6] == 'O' && cells[7] == 'O' && cells[8] == 'O') { winCheck = true; }

	if (cells[0] == 'O' && cells[3] == 'O' && cells[6] == 'O') { winCheck = true; }
	if (cells[1] == 'O' && cells[4] == 'O' && cells[7] == 'O') { winCheck = true; }
	if (cells[2] == 'O' && cells[5] == 'O' && cells[8] == 'O') { winCheck = true; }

	if (cells[0] == 'O' && cells[4] == 'O' && cells[8] == 'O') { winCheck = true; }
	if (cells[2] == 'O' && cells[4] == 'O' && cells[6] == 'O') { winCheck = true; }

	usint counter = 0;
	for (int i = 0; i < 9; i++) { if (cells[i] == 'X' || cells[i] == 'O') { counter++; } }
 	if (counter == 9 && winCheck != true) { standoff = true; }

	return winCheck;
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
