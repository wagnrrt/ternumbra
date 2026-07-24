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
  Vector2 pos;

  static constexpr float WIDTH = 12.0f;
  static constexpr float HEIGHT = 14.0f;
  static constexpr float SCALE = 4.0f;

private:
  float speed;
  Vector2 direction = {0, 0};

  Texture2D texture;

  Rectangle frame;
  int currentFrame;
  float frameTimer;

  void Animation(float dt);
};

} // namespace entities

#endif // !PLAYER_HPP
