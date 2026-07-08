#ifndef BOARD_H
#define BOARD_H

#define CELLS_SIZE 10
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 640
#define CELLS_X (WINDOW_WIDTH / CELLS_SIZE)
#define CELLS_Y (WINDOW_HEIGHT / CELLS_SIZE)

void init_board(struct Cell board[CELLS_Y][CELLS_X]);
void calculate_neighbors(struct Cell board[CELLS_Y][CELLS_X]);
void update_board(struct Cell board[CELLS_Y][CELLS_X]);
void draw_board(SDL_Renderer *renderer, struct Cell board[CELLS_Y][CELLS_X]);

#endif