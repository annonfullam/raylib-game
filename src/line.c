#include "line.h"

void line_draw(line_t l)
{
    DrawLineEx((Vector2){l.x1, l.y1}, (Vector2){l.x2, l.y2}, LINE_THICKNESS, LINE_COLOR);
}

bool line_intersects(line_t l1, line_t l2, Vector2 *at)
{
    Vector2 startPos1 = {l1.x1, l1.y1}, endPos1 = {l1.x2, l1.y2};
    Vector2 startPos2 = {l2.x1, l2.y1}, endPos2 = {l2.x2, l2.y2};
    return CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, at);
}