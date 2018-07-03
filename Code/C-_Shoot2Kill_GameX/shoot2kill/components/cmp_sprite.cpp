#include "cmp_sprite.h"
#include "cmp_enemy_ai.h"
#include "cmp_character_attributes.h"
#include "cmp_player_physics.h"
#include "components_controls.h"
#include <SFML/Window/Keyboard.hpp>
#include "system_renderer.h"

using namespace std;
using namespace sf;

SpriteComponent::SpriteComponent(Entity* p)
	: Component(p), _sprite(make_shared<sf::Sprite>()), _animationAcc(0), _characterDirection(1.f), _animationFreezer(0), _widerSpriteType(false) {}

void SpriteComponent::update(double dt) {
	_sprite->setPosition(_parent->getPosition());
	_sprite->setRotation(_parent->getRotation());

	// Check if the sprite belongs to the player character
	auto s = _parent->get_components<PlayerPhysicsComponent>();
	if (s.size() > 0) {

		if (Keyboard::isKeyPressed(keyRight)) {

			if (_animationFreezer < 0) {
				_characterDirection = 1;

				if (getWiderSpriteType() == true) {

					if (_animationAcc % 3 == 0)
						_sprite->setTextureRect(IntRect(92, 0, 92, 140));
					else if (_animationAcc % 3 == 1)
						_sprite->setTextureRect(IntRect(184, 0, 92, 140));
					else
						_sprite->setTextureRect(IntRect(276, 0, 92, 140));
				} else {

					if (_animationAcc % 3 == 0)
						_sprite->setTextureRect(IntRect(70, 0, 70, 140));
					else if (_animationAcc % 3 == 1)
						_sprite->setTextureRect(IntRect(140, 0, 70, 140));
					else
						_sprite->setTextureRect(IntRect(210, 0, 70, 140));
				}

				_animationAcc++;
				_animationFreezer = 85;
			}
		}
		else if (Keyboard::isKeyPressed(keyLeft)) {

			if (getWiderSpriteType() == true) {

				if (_animationFreezer < 0) {
					_characterDirection = -1;
					if (_animationAcc % 3 == 0)
						_sprite->setTextureRect(IntRect(92, 140, 92, 140));
					else if (_animationAcc % 3 == 1)
						_sprite->setTextureRect(IntRect(184, 140, 92, 140));
					else
						_sprite->setTextureRect(IntRect(276, 140, 92, 140));
					_animationAcc++;
					_animationFreezer = 85;
				}
			} else {

				if (_animationFreezer < 0) {
					_characterDirection = -1;
					if (_animationAcc % 3 == 0)
						_sprite->setTextureRect(IntRect(70, 140, 70, 140));
					else if (_animationAcc % 3 == 1)
						_sprite->setTextureRect(IntRect(140, 140, 70, 140));
					else
						_sprite->setTextureRect(IntRect(210, 140, 70, 140));
					_animationAcc++;
					_animationFreezer = 85;
				}
			}
			
		}
		else {

			if (getWiderSpriteType() == true) {

				if (_characterDirection == 1)
					_sprite->setTextureRect(IntRect(0, 0, 92, 140));
				else
					_sprite->setTextureRect(IntRect(0, 140, 92, 140));

			} else {

				if (_characterDirection == 1)
					_sprite->setTextureRect(IntRect(0, 0, 70, 140));
				else
					_sprite->setTextureRect(IntRect(0, 140, 70, 140));
			}

			_animationAcc = 0;
		}

		if (_animationFreezer > -5)
			_animationFreezer--;
	}
	else if (_parent->get_components<EnemyAIComponent>().size() > 0) {

		// If the sprite belongs to the enemy character

		if (_characterDirection == 1) {
			if (_animationFreezer < 0) {
				//_characterDirection = 1;
				if (_animationAcc % 3 == 0)
					_sprite->setTextureRect(IntRect(70, 0, 70, 140));
				else if (_animationAcc % 3 == 1)
					_sprite->setTextureRect(IntRect(140, 0, 70, 140));
				else
					_sprite->setTextureRect(IntRect(210, 0, 70, 140));
				_animationAcc++;
				_animationFreezer = 85;
			}
		}
		else if (_characterDirection == -1) {
			if (_animationFreezer < 0) {
				//_characterDirection = 1;
				if (_animationAcc % 3 == 0)
					_sprite->setTextureRect(IntRect(70, 140, 70, 140));
				else if (_animationAcc % 3 == 1)
					_sprite->setTextureRect(IntRect(140, 140, 70, 140));
				else
					_sprite->setTextureRect(IntRect(210, 140, 70, 140));
				_animationAcc++;
				_animationFreezer = 85;
			}
		}

		if (_animationFreezer > -5)
			_animationFreezer--;
	}
}


int SpriteComponent::getDirection() { return _characterDirection; }

void SpriteComponent::changeDirection() { _characterDirection *= -1; }

void SpriteComponent::render() { Renderer::queue(_sprite.get()); }

void SpriteComponent::setWiderSpriteType(bool type) { _widerSpriteType = type; }

bool SpriteComponent::getWiderSpriteType() { return _widerSpriteType; }

void ShapeComponent::update(double dt) {
  _shape->setPosition(_parent->getPosition());
  _shape->setRotation(_parent->getRotation());
}

void ShapeComponent::render() { Renderer::queue(_shape.get()); }

sf::Shape& ShapeComponent::getShape() const { return *_shape; }

ShapeComponent::ShapeComponent(Entity* p)
    : Component(p), _shape(make_shared<sf::CircleShape>()) {}

sf::Sprite& SpriteComponent::getSprite() const { return *_sprite; }
