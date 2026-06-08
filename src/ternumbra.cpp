#include "../include/entities/Player.hpp"
#include <raylib.h>

int main() {
  // Janela
  InitWindow(800, 600, "Ternumbra");
  SetTargetFPS(60);

  entities::Player player;

  // Game loop
  while (!WindowShouldClose()) {
    // Update
    float deltatime = GetFrameTime();
    player.Update(deltatime);

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);

    player.Render();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
