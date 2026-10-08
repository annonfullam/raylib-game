#include "graphics.h"

void graphics_draw_grid()
{
    for (uint16_t y = 0; y < GRID_ROWS; y++)
    {
        for (uint16_t x = 0; x < GRID_COLS; x++)
        {
            DrawCircle(x * CELL_SIZE, y * CELL_SIZE, 1, GRID_CLR);
        }
    }
}
