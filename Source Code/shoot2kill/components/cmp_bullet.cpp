#include "cmp_bullet.h"
#include "cmp_shooting.h"
#include <LevelSystem.h>
#include <SFML/Graphics/Sprite.hpp>
#include <string>

using namespace std;
using namespace sf;

void BulletComponent::update(double dt) {
  _lifetime -= dt;

  if (_parent->getPosition().x < 50 || (_parent->getPosition().x > 1280))
      _parent->setForDelete();

  if (_lifetime <= 0.f) 
	  _parent->setForDelete();
}

BulletComponent::BulletComponent(Entity* p, int direction, string bulletType, float lifetime)
    : Component(p), _lifetime(lifetime) {

	auto s = _parent->addComponent<SpriteComponent>();

	if (bulletType == "bullet_small") {

		_bulletSpritesheet.loadFromFile("res/img/bullet_small.png");
		s->getSprite().setTexture(_bulletSpritesheet);
		if (direction == 1)
			s->getSprite().setTextureRect(IntRect(0, 0, 10, 5));
		else
			s->getSprite().setTextureRect(IntRect(0, 5, 10, 5));
		s->getSprite().setOrigin(5.f, 2.5f);
	}
	else if (bulletType == "bullet_long") {

		_bulletSpritesheet.loadFromFile("res/img/bullet_small.png");
		s->getSprite().setTexture(_bulletSpritesheet);
		if (direction == 1)
			s->getSprite().setTextureRect(IntRect(0, 0, 20, 5));
		else
			s->getSprite().setTextureRect(IntRect(0, 5, 20, 5));
		s->getSprite().setOrigin(10.f, 2.5f);
	}
	else if (bulletType == "bullet_bazooka") {

		_bulletSpritesheet.loadFromFile("res/img/bazookaBullet.png");
		s->getSprite().setTexture(_bulletSpritesheet);
		if (direction == 1)
			s->getSprite().setTextureRect(IntRect(0, 0, 32, 14));
		else
			s->getSprite().setTextureRect(IntRect(0, 14, 32, 14));
		s->getSprite().setOrigin(16.f, 7.f);
	}
	else if (bulletType == "bullet_cannon") {

		_bulletSpritesheet.loadFromFile("res/img/bazookaBullet.png");
		s->getSprite().setTexture(_bulletSpritesheet);
		if (direction == 1)
			s->getSprite().setTextureRect(IntRect(0, 0, 32, 14));
		else
			s->getSprite().setTextureRect(IntRect(0, 14, 32, 14));
		s->getSprite().setOrigin(16.f, 7.f);
	}
	else {

		_bulletSpritesheet.loadFromFile("res/img/bullet_small.png");
		s->getSprite().setTexture(_bulletSpritesheet);
		if (direction == 1)
			s->getSprite().setTextureRect(IntRect(0, 0, 10, 5));
		else
			s->getSprite().setTextureRect(IntRect(0, 5, 10, 5));
		s->getSprite().setOrigin(5.f, 2.5f);
	}
}
