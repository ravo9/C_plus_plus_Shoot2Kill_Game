#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>

using namespace std;

class PlayerComponent : public Component {
protected:
  sf::Texture _spritesheet;

public:
  void update(double dt) override;
  void render() override {}
  explicit PlayerComponent(Entity* p);
  PlayerComponent() = delete;
};
