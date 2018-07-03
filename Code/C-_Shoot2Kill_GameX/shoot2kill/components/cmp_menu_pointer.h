#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>

class MenuPointerComponent : public Component {
protected:
  int _choosingFreezer;
  int _currentValue;
  sf::Texture _spritesheet;
  std::vector<sf::Vector2f> _positions;

public:
  void update(double dt) override;
  void render() override {}
  void addPosition(sf::Vector2f pos);
  sf::Vector2f getPosition(int number);
  int getCurrentPosition();
  int getPositionsAmount();
  explicit MenuPointerComponent(Entity* p);
  MenuPointerComponent() = delete;
};
