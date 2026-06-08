#include "../../include/entities/Player.hpp"
#include "raylib.h"
#include "raymath.h"
#define ASSETS "resources/"

namespace entities {
Player::Player() {
  position = {100, 100};
  speed = 200;
  texture = LoadTexture(ASSETS "player.png");
}

Player::~Player() { UnloadTexture(texture); }

void Player::Update(float dt) {
  Vector2 input = {0, 0};

  if (IsKeyDown(KEY_W))
    input.y -= 1;
  if (IsKeyDown(KEY_S))
    input.y += 1;
  if (IsKeyDown(KEY_A))
    input.x -= 1;
  if (IsKeyDown(KEY_D))
    input.x += 1;

  if (Vector2Length(input) > 0)
    input = Vector2Normalize(input);

  direction = Vector2Lerp(direction, input, 10 * dt);
  position += direction * speed * dt;
}

void Player::Render() { DrawTextureV(texture, position, WHITE); }

} // namespace entities
