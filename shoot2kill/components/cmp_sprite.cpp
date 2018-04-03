#include "cmp_sprite.h"
#include "cmp_player_physics.h"
#include <SFML/Window/Keyboard.hpp>
#include "system_renderer.h"

using namespace std;
using namespace sf;

SpriteComponent::SpriteComponent(Entity* p)
    : Component(p), _sprite(make_shared<sf::Sprite>()) {}

void SpriteComponent::update(double dt) {
  _sprite->setPosition(_parent->getPosition());
  _sprite->setRotation(_parent->getRotation());

  // Check if the sprite belongs to the player character
  auto s = _parent->get_components<PlayerPhysicsComponent>();
  if (s.size() > 0) {

	  if (Keyboard::isKeyPressed(Keyboard::Right))
		  _sprite->setTextureRect(IntRect(70, 0, 70, 140));
	  else if (Keyboard::isKeyPressed(Keyboard::Left))
		  _sprite->setTextureRect(IntRect(140, 0, 70, 140));
	  else
		  _sprite->setTextureRect(IntRect(0, 0, 70, 140));
  }
}

void SpriteComponent::render() { Renderer::queue(_sprite.get()); }

void ShapeComponent::update(double dt) {
  _shape->setPosition(_parent->getPosition());
  _shape->setRotation(_parent->getRotation());
}

void ShapeComponent::render() { Renderer::queue(_shape.get()); }

sf::Shape& ShapeComponent::getShape() const { return *_shape; }

ShapeComponent::ShapeComponent(Entity* p)
    : Component(p), _shape(make_shared<sf::CircleShape>()) {}

sf::Sprite& SpriteComponent::getSprite() const { return *_sprite; }
