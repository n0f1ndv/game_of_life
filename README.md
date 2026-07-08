## Game of Life
In this project I am trying to replicate Conway's Game of Life using C and SDL.

GoL Rules (I copied it from wikipedia):
 - Any live cell with fewer than two live neighbours dies, as if by underpopulation.
 - Any live cell with two or three live neighbours lives on to the next generation.
 - Any live cell with more than three live neighbours dies, as if by overpopulation.
 - Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Sources:
 - [wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Installation & Compliation
Get the repository:
``` bash
git clone https://github.com/n0f1ndv/game_of_life.git
```

Create build directories:
``` bash
mkdir build
cmake -S . -B build
```

Build the project:
``` bash
cmake --build build
```

Run the app, it will display available options:
``` bash
./build/Debug/app
```

## Usage
Press *a* key to go to next generation, hold *a* to let simulation go.