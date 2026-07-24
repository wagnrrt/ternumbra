#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "raylib.h"
namespace world {

class Tilemap {

public:
  Tilemap();
  ~Tilemap();
  void Render();

private:
  Texture2D tileset;

  int mapData[5][5] = {{0, 2, 1, 1, 0},
                       {1, 1, 3, 2, 0},
                       {2, 0, 1, 1, 1},
                       {1, 2, 0, 1, 2},
                       {1, 3, 2, 0, 1}};
  Rectangle GetTileRect(int tileId) const;
};

} // namespace world

#endif // !TILEMAP_HPP
