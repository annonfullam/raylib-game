#include "node.h"

void node_draw(node_t n)
{
    DrawCircle(n.x, n.y, NODE_RADIUS, NODE_COLOR);
}