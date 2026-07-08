#include <stdio.h>
#include <string.h>

#include "board.h"

void init_board(const char *file_path, struct Cell board[CELLS_Y][CELLS_X]) {
    FILE *fptr = fopen(file_path, "r");

    if (fptr == NULL) {
        fprintf(stderr, "Couldn't open file %s\n", file_path);
        return;
    }

    char line[CELLS_X + 10];

    for (int y = 0; y < CELLS_Y; y++) {
        if (fgets(line, sizeof(line), fptr) == NULL) {
            fprintf(stderr, "Error: Unexpected end of file at row %d\n", y);
            break;
        }

        for (int x = 0; x < CELLS_X; x++) {
            if (line[x] == '0') {
                board[y][x].value = 0;
            } else if (line[x] == '1') {
                board[y][x].value = 1;
            } else if (line[x] == '\n' || line[x] == '\0') {
                fprintf(stderr, "Warning: Row %d has fewer than %d columns\n", y, CELLS_X);
                board[y][x].value = 0;
            } else {
                fprintf(stderr, "Warning: Invalid character '%c' at row %d, col %d\n", line[x], y, x);
                board[y][x].value = 0; 
            }

            board[y][x].neighbors = 0;
        }
    }

    fclose(fptr);
}

void calculate_neighbors(struct Cell board[CELLS_Y][CELLS_X]) {
    int tmp_x[2] = {0, 0};
    int tmp_y[2] = {0, 0};

    for (int i = 0; i < CELLS_Y; i++) {
        for (int j = 0; j < CELLS_X; j++) {
            // This parser connects ends of board together
            if (i - 1 < 0) 
                tmp_y[0] = CELLS_Y - 1;
            else
                tmp_y[0] = i - 1;

            if (i + 1 == CELLS_Y)
                tmp_y[1] = 0;
            else
                tmp_y[1] = i + 1;

            if (j - 1 < 0) 
                tmp_x[0] = CELLS_X - 1;
            else
                tmp_x[0] = j - 1;

            if (j + 1 == CELLS_X)
                tmp_x[1] = 0;
            else
                tmp_x[1] = j + 1;

            if (board[tmp_y[0]][tmp_x[1]].value == 1) // NW
                board[i][j].neighbors++;

            if (board[i][tmp_x[1]].value == 1)   // N
                board[i][j].neighbors++;

            if (board[tmp_y[1]][tmp_x[1]].value == 1) // NE
                board[i][j].neighbors++;

            if (board[tmp_y[0]][j].value == 1)   // W
                board[i][j].neighbors++;

            if (board[tmp_y[1]][j].value == 1)   // E
                board[i][j].neighbors++;

            if (board[tmp_y[0]][tmp_x[0]].value == 1) // SW
                board[i][j].neighbors++;

            if (board[i][tmp_x[0]].value == 1)   // S
                board[i][j].neighbors++;

            if (board[tmp_y[1]][tmp_x[0]].value == 1) // SE
                board[i][j].neighbors++;
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
                else if (board[i][j].neighbors == 2)
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