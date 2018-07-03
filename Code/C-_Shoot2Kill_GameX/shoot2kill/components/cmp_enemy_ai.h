#pragma once
#include "cmp_player_physics.h"
#include "cmp_physics.h"
#include <ecm.h>

class EnemyAIComponent : public Component {
protected:
  sf::Vector2f _direction;
  sf::Vector2f _originPosition;
  int _changeDirectionFreezer;
  int _jumpFreezer;
  int _attackFreezer;
  float _speed;

public:
  void update(double dt) override;
  void setSpeed(float speed);
  void render() override {}
  explicit EnemyAIComponent(Entity* p);
  EnemyAIComponent() = delete;
};
