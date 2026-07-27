#include "entities/Player.hpp"
#include "raylib.h"
#include "raymath.h"
#include "utils/AssetPath.hpp"

namespace entities {
Player::Player() {
  pos = {100, 100};
  speed = 300;

  texture = LoadTexture(Assets::GetPath("player.png"));

  currentFrame = 0;
  frameTimer = 0.0f;
  frame = {0, 0, WIDTH, HEIGHT};
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
  pos += direction * speed * dt;

  if (input.x != 0 || input.y != 0) {
    frame.x = WIDTH;
    if (input.x < 0) {
      frame.width = -WIDTH;
    } else if (input.x > 0) {
      frame.width = WIDTH;
    }
  } else {
    frame.x = 0;
  }

  Animation(dt);
}

void Player::Animation(float dt) {
  frameTimer += dt;
  if (frameTimer >= 0.1) {
    currentFrame++;
    frame.y = currentFrame * HEIGHT;
    if (currentFrame == 8) {
      currentFrame = 0;
    }

    frameTimer -= 0.1;
  }
}

void Player::Render() {

  Rectangle dest = {pos.x, pos.y, WIDTH * SCALE, HEIGHT * SCALE};

  DrawTexturePro(texture, frame, dest, {0, 0}, 0.0f, WHITE);
}

} // namespace entities
