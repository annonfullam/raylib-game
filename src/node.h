#ifndef NODE_H
#define NODE_H

#include "raylib.h"
#include <stdint.h>

#define NODE_RADIUS 10
#define NODE_COLOR BLACK

typedef struct node
{
    uint16_t x;
    uint16_t y;
    struct node *conns[8];
} node_t;

void node_draw(node_t n);

#endif