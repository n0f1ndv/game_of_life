#include <stdio.h>

#define BOARD_SIZE 10

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0 ,1, 0, 1, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}