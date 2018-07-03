#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>

class BonusComponent : public Component {
protected:
  std::string _type;
  sf::Texture _spritesheet;

public:
  void update(double dt) override;
  void render() override {}
  explicit BonusComponent(Entity* p, std::string type, sf::Vector2f position);
  BonusComponent() = delete;
};
