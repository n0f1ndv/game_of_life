#ifndef CELL_H
#define CELL_H

struct Cell {
    int value; // 0 - dead, 1 - alive
    int neighbors; // value from [0, 8] range
};

#endif