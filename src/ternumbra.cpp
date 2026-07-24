#include "../include/entities/Player.hpp"
#include "../include/world/Tilemap.hpp"
#include <raylib.h>

int main() {
  // Janela
  InitWindow(1280, 720, "Ternumbra");
  SetTargetFPS(60);

  entities::Player player;
  world::Tilemap tilemap;

  // Game loop
  while (!WindowShouldClose()) {
    // Update
    float deltatime = GetFrameTime();
    player.Update(deltatime);

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);

    tilemap.Render();
    player.Render();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
