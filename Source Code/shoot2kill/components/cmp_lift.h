#pragma once
#include <ecm.h>

class LiftComponent : public Component {
protected:
  bool liftArea(const sf::Vector2f&);
  sf::Vector2f _localization;
  sf::Vector2f _size;

public:
  void update(double dt) override;
  void render() override {}
  explicit LiftComponent(Entity* p, sf::Vector2f loc, sf::Vector2f size);
  LiftComponent() = delete;
};
