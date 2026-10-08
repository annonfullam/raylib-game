#ifndef LINE_H
#define LINE_H

#include "raylib.h"
#include <stdint.h>

#define LINE_THICKNESS 2
#define LINE_COLOR GRAY

typedef struct line
{
  uint16_t x1;
  uint16_t y1;

  uint16_t x2;
  uint16_t y2;
} line_t;

void line_draw(line_t l);

bool line_intersects(line_t l1, line_t l2, Vector2 *at);

#endif