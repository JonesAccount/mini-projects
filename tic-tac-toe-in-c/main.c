#include <stdio.h>

void renderPlayfield(char *cells);


int main(void) {
    printf("\033[?25l");

    char cells[] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'};

    renderPlayfield(cells);

    return 0;
}


void renderPlayfield(char *cells) {
    printf("\n\t  КРЕСТИКИ-НОЛИКИ\n\n");

    for (int i = 0; i < 9; i++) {
        if ((i % 3) == 0) { printf("\n\t    "); }
        printf("  %c", cells[i]);
    }
}
