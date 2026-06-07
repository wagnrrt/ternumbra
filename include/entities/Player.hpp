#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
namespace entities {

class Player {

public:
  Player();
  void Update(float dt);
  void Render();

private:
  float speed;
  Vector2 position;
  Vector2 direction;
};

} // namespace entities

#endif // !PLAYER_HPP
