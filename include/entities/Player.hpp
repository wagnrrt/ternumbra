#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
namespace entities {

class Player {

public:
  Player();
  ~Player();
  void Update(float dt);
  void Render();

private:
  float speed;
  Vector2 position;
  Vector2 direction;

  Texture2D texture;

  Rectangle frame;
  int currentFrame;
  float frameTimer;

  void Animation(float dt);
};

} // namespace entities

#endif // !PLAYER_HPP
