#include <raylib.h>

int main() {
  // Janela
  InitWindow(800, 600, "Ternumbra");
  SetTargetFPS(60);

  // Game loop
  while (!WindowShouldClose()) {
    // Update

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Hello Raylib!", 190, 200, 20, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
