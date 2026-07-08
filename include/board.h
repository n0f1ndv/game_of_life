#ifndef BOARD_H
#define BOARD_H

#define CELLS_SIZE 10
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 640
#define CELLS_X (WINDOW_WIDTH / CELLS_SIZE)
#define CELLS_Y (WINDOW_HEIGHT / CELLS_SIZE)

void calculate_neighbors();
void init_board();
void update_board();
void draw_board();

#endif