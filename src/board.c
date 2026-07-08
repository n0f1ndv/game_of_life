#include <stdio.h>

#include <SDL3/SDL.h>

#include "board.h"

void init_board(int board[WINDOW_HEIGHT / CELLS_SIZE][WINDOW_WIDTH / CELLS_SIZE]) {
    for (int i = 0; i < WINDOW_HEIGHT / CELLS_SIZE; i++) {
        for (int j = 0; j < WINDOW_WIDTH / CELLS_SIZE; j++) {
            if ((i + j) % 2 == 0)
                board[i][j] = 0;
            else 
                board[i][j] = 1;
        }
    }
}

void update_board(int board[WINDOW_HEIGHT / CELLS_SIZE][WINDOW_WIDTH / CELLS_SIZE]) {
    for (int i = 0; i < WINDOW_HEIGHT / CELLS_SIZE; i++) {
        for (int j = 0; j < WINDOW_WIDTH / CELLS_SIZE; j++) {
            if (board[i][j] == 0)
                board[i][j] = 1;
            else 
                board[i][j] = 0;
        }
    }
}

void draw_board(SDL_Renderer *renderer, int board[WINDOW_HEIGHT / CELLS_SIZE][WINDOW_WIDTH / CELLS_SIZE]) {
    // TODO: Move it somewhere where it's not repeated for no reason
    SDL_FRect rect;
    rect.w = rect.h = CELLS_SIZE;

    for (int i = 0; i < WINDOW_HEIGHT / CELLS_SIZE; i++) {
        for (int j = 0; j < WINDOW_WIDTH / CELLS_SIZE; j++) {
            if (board[i][j] == 0)
                SDL_SetRenderDrawColor(renderer, 234, 118, 203, SDL_ALPHA_OPAQUE_FLOAT);
            else
                SDL_SetRenderDrawColor(renderer, 30, 102, 245, SDL_ALPHA_OPAQUE_FLOAT);

            rect.x = CELLS_SIZE * j;
            rect.y = CELLS_SIZE * i;
            SDL_RenderFillRect(renderer, &rect);
    
        }
    }
}