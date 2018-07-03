#pragma once

#include "ecm.h"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteComponent : public Component {
protected:
  // 1 means 'right', -1 means 'left'
  float _characterDirection;
  std::shared_ptr<sf::Sprite> _sprite;
  int _animationAcc;
  int _animationFreezer;
  bool _widerSpriteType;

public:
  SpriteComponent() = delete;
  explicit SpriteComponent(Entity* p);
  void update(double dt) override;
  void render() override;
  void changeDirection();
  void setWiderSpriteType(bool type);
  bool getWiderSpriteType();
  int getDirection();
  sf::Sprite& getSprite() const;
  template <typename... Targs> void setSprite(Targs... params) {
    _sprite.reset(new sf::Sprite(params...));
  }
};

class ShapeComponent : public Component {
protected:
  std::shared_ptr<sf::Shape> _shape;

public:
  ShapeComponent() = delete;

  explicit ShapeComponent(Entity* p);

  void update(double dt) override;
  void render() override;
  sf::Shape& getShape() const;
  template <typename T, typename... Targs> void setShape(Targs... params) {
    _shape.reset(new T(params...));
  }
};