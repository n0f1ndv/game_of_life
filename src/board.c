#include <stdio.h>

#include <SDL3/SDL.h>

#include "board.h"
#include "cell.h"

void init_board(struct Cell board[CELLS_Y][CELLS_X]) {
    for (int i = 0; i < CELLS_Y; i++) {
        for (int j = 0; j < CELLS_X; j++) {
            if ((i + j) % 2 == 0)
                board[i][j].value = 0;
            else 
                board[i][j].value = 1;
        }
    }
}

void calculate_neighbors(struct Cell board[CELLS_Y][CELLS_X]) {
    for (int i = 0; i < CELLS_Y; i++) {
        for (int j = 0; j < CELLS_X; j++) {

        }
    }
}

void update_board(struct Cell board[CELLS_Y][CELLS_X]) {
    for (int i = 0; i < CELLS_Y; i++) {
        for (int j = 0; j < CELLS_X; j++) {
            // Calculations for living cells
            if (board[i][j].value == 1) {
                if (board[i][j].neighbors < 2 || board[i][j].neighbors > 3)
                    board[i][j].value = 0;
                else
                    board[i][j].value = 1;
            }
            // Calculations for dead cells
            else { 
                if (board[i][j].neighbors == 3)
                    board[i][j].value = 1;
            }
        }
    }
}

void draw_board(SDL_Renderer *renderer, struct Cell board[CELLS_Y][CELLS_X]) {
    // TODO: Move it somewhere where it's not repeated for no reason
    SDL_FRect rect;
    rect.w = rect.h = CELLS_SIZE;

    for (int i = 0; i < CELLS_Y; i++) {
        for (int j = 0; j < CELLS_X; j++) {
            if (board[i][j].value == 0)
                SDL_SetRenderDrawColor(renderer, 234, 118, 203, SDL_ALPHA_OPAQUE_FLOAT);
            else
                SDL_SetRenderDrawColor(renderer, 30, 102, 245, SDL_ALPHA_OPAQUE_FLOAT);

            rect.x = CELLS_SIZE * j;
            rect.y = CELLS_SIZE * i;
            SDL_RenderFillRect(renderer, &rect);
    
        }
    }
}