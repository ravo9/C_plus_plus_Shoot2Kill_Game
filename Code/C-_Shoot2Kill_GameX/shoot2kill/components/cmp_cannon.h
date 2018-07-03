#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>

using namespace std;

class CannonComponent : public Component {
protected:
  sf::Texture _spritesheet;
  bool _workingStatus;
  bool _visibility;
  int _direction;
  int _shootingFreezer;

public:
  void update(double dt) override;
  void render() override {}
  void switchOn();
  void switchOff();
  void shoot();
  void setVisibility(bool vis);
  explicit CannonComponent(Entity* p, int direction);
  CannonComponent() = delete;
};
