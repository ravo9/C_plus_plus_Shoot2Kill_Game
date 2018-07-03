#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>

using namespace std;

class SpecialCharacterComponent : public Component {
protected:
  sf::Texture _spritesheet;

public:
  void update(double dt) override;
  void render() override {}
  explicit SpecialCharacterComponent(Entity* p, string type);
  SpecialCharacterComponent() = delete;
};
