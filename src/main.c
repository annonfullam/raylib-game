#include "raylib.h"
#include <stdio.h> // Required for: printf()
#include <stdint.h>
#include <time.h> // required for time()
#include <math.h> // required for floorf()

#include "helpers.h"
#include "graphics.h"
#include "line.h"
#include "node.h"

// #define DEBUG_MODE
#define SUPPORT_LOG_INFO
#if defined(SUPPORT_LOG_INFO)
#define LOG(...) fprintf(stderr, __VA_ARGS__)
#else
#define LOG(...)
#endif

static void UpdateDrawFrame(void);

// Global Variables
static bool g_drawing = false;
static Vector2_t g_drawing_anchor;

static line_t g_lines[10];
static uint16_t g_lines_count = 0;

static node_t g_nodes[50];
static uint16_t g_nodes_count = 0;

// Program entry point
int main(void)
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib game template");
  SetTargetFPS(TARGET_FPS);

  SetRandomSeed(time(NULL));

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    UpdateDrawFrame();
  }

  CloseWindow();

  return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
  // Update
  //----------------------------------------------------------------------------------

  // if (helpers_cmd_key_down() && IsKeyPressed(KEY_Z))
  // {
  //   if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))
  //   {
  //     LOG("Redo");
  //   }
  //   else
  //   {
  //     LOG("Undo");
  //   }
  // }

  // Convert mouse position to snapped grid position
  float offset = CELL_SIZE * -0.5f;
  uint16_t mouse_x = floorf((GetMouseX() - offset) / CELL_SIZE) * CELL_SIZE;
  uint16_t mouse_y = floorf((GetMouseY() - offset) / CELL_SIZE) * CELL_SIZE;

  if (g_lines_count < 10 && g_nodes_count < 50 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    g_drawing = true;
    g_drawing_anchor = (Vector2_t){mouse_x, mouse_y};
  }

  if (g_drawing)
  {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
      line_t n_line = {g_drawing_anchor.x, g_drawing_anchor.y, mouse_x, mouse_y};

      for (uint16_t i = 0; i < g_lines_count; i++)
      {
        Vector2_t intersects_at;
        if (line_intersects(n_line, g_lines[i], &intersects_at))
        {
          g_nodes[g_nodes_count++] = (node_t){intersects_at.x, intersects_at.y};
        }
      }

      g_lines[g_lines_count++] = n_line;
      g_drawing = false;
    }
  }

  // Draw
  //----------------------------------------------------------------------------------
  BeginDrawing();
  ClearBackground(BACKGROUND_CLR);

  graphics_draw_grid();

  for (uint16_t i = 0; i < g_lines_count; i++)
  {
    line_draw(g_lines[i]);
  }

  for (uint16_t i = 0; i < g_nodes_count; i++)
  {
    node_draw(g_nodes[i]);
  }

  if (g_drawing)
  {
    DrawLineEx(g_drawing_anchor, (Vector2_t){mouse_x, mouse_y}, 2, BLUE); // draw line cursor
  }
  else
  {
    DrawCircle(mouse_x, mouse_y, 2, RED); // draw mouse cursor
  }

#if defined(DEBUG_MODE)
  DrawFPS(10, 10);
#endif

  EndDrawing();
}
