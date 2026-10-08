#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"
#include <stdint.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define TARGET_FPS 30
#define BACKGROUND_CLR WHITE

#define GRID_COLS 64
#define GRID_ROWS 32
#define CELL_SIZE 16
#define GRID_CLR LIGHTGRAY

void graphics_draw_grid(void);

#endif