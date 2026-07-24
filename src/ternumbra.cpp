#include "../include/entities/Player.hpp"
#include "../include/world/Tilemap.hpp"
#include <raylib.h>

int main() {
  // Janela
  InitWindow(1280, 720, "Ternumbra");
  SetTargetFPS(60);

  entities::Player player;
  world::Tilemap tilemap;

  Camera2D camera;
  camera.target = {player.pos.x + player.WIDTH * player.SCALE / 2.0f,
                   player.pos.y + player.HEIGHT * player.SCALE / 2.0f};
  camera.offset = (Vector2){1280.0f / 2.0f, 720.0f / 2.0f};
  camera.zoom = 1;
  camera.rotation = 0;

  // Game loop
  while (!WindowShouldClose()) {
    // Update
    float deltatime = GetFrameTime();
    player.Update(deltatime);

    camera.target = {player.pos.x + player.WIDTH * player.SCALE / 2.0f,
                     player.pos.y + player.HEIGHT * player.SCALE / 2.0f};

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode2D(camera);

    tilemap.Render();
    player.Render();

    EndMode2D();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
