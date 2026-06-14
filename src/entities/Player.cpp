#include "../../include/entities/Player.hpp"
#include "raylib.h"
#include "raymath.h"
#define ASSETS "resources/"

namespace entities {
Player::Player() {
  position = {100, 100};
  speed = 300;

  texture = LoadTexture(ASSETS "player.png");

  currentFrame = 0;
  frameTimer = 0.0f;
  frame = {0, 0, 12, 14};
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

  if (input.x != 0 || input.y != 0) {
    frame.x = 12;
    if (input.x < 0) {
      frame.width = -12;
    } else if (input.x > 0) {
      frame.width = 12;
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
    frame.y = currentFrame * 14;
    if (currentFrame == 8) {
      currentFrame = 0;
    }

    frameTimer -= 0.1;
  }
}

void Player::Render() {

  Rectangle dest = {position.x, position.y, 12 * 4.0f, 14 * 4.0f};

  DrawTexturePro(texture, frame, dest, {0, 0}, 0.0f, WHITE);
}

} // namespace entities
