#pragma once
#include "cmp_physics.h"
#include <ecm.h>
#include <SFML/Graphics.hpp>
#include <string>

class BulletComponent : public Component {
protected:
  float _lifetime;
  sf::Texture _bulletSpritesheet;

public:
  void update(double dt) override;
  void render() override {}
  //explicit BulletComponent(Entity* p, float lifetime = 3.f);
  explicit BulletComponent(Entity* p, int direction, std::string bulletType, float lifetime = 1.f);
  BulletComponent() = delete;
};
