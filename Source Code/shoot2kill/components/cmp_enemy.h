#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>

using namespace std;

class EnemyComponent : public Component {
protected:
  static int _enemyNumber;
  sf::Texture _spritesheet;

public:
  void update(double dt) override;
  void render() override {}
  explicit EnemyComponent(Entity* p, int enemyNumber, int enemyType);
  EnemyComponent() = delete;
};
