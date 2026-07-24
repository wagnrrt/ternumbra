#include "../../include/world/Tilemap.hpp"
#include "raylib.h"
#define ASSETS "resources/"

namespace world {
Tilemap::Tilemap() { tileset = LoadTexture(ASSETS "tileset.png"); }

Tilemap::~Tilemap() { UnloadTexture(tileset); }

void Tilemap::Render() {
  for (int i = 0; i < 5; i++) {
    for (int t = 0; t < 5; t++) {
      DrawTexturePro(
          tileset, GetTileRect(mapData[i][t]),
          {100 + (16 * 4.0f * t), 100 + (16 * 4.0f * i), 16 * 4.0f, 16 * 4.0f},
          {0, 0}, 0.0f, WHITE);
    }
  }
}

Rectangle Tilemap::GetTileRect(int tileId) const {
  int row, col;

  row = tileId / 4;
  col = tileId % 4;

  return {col * 16.0f, row * 16.0f, 16, 16};
}

} // namespace world
