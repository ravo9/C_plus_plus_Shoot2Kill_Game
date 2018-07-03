#include "cmp_cannon.h"
#include "cmp_sprite.h"
#include "cmp_physics.h"
#include "cmp_shooting.h"
#include "cmp_hurt_player.h"
#include <LevelSystem.h>
#include "engine.h"

using namespace std;
using namespace sf;

void CannonComponent::update(double dt) {

	shoot();
}

CannonComponent::CannonComponent(Entity* p, int direction)
    : Component(p), _direction(direction) {

	_spritesheet.loadFromFile("res/img/cannon.png");

	auto s2 = _parent->addComponent<SpriteComponent>();
	s2->getSprite().setTexture(_spritesheet);

	if (_direction == 1)
		s2->getSprite().setTextureRect(IntRect(250, 0, 125, 160));
	else
		s2->getSprite().setTextureRect(IntRect(0, 160, 125, 160));

	s2->getSprite().setOrigin(62.f, 80.f);

	_parent->addTag("cannon");
	_parent->addComponent<ShootingComponent>();

	_workingStatus = false;

	_shootingFreezer = 1000;
}

void CannonComponent::switchOn() { _workingStatus = true; }

void CannonComponent::switchOff() { _workingStatus = false; }

void CannonComponent::setVisibility(bool vis) {
	_visibility = vis;
}

void CannonComponent::shoot() {

	if (_shootingFreezer == 0) {

		//PlaySound(TEXT("res/sound/coltSound.wav"), NULL, SND_FILENAME | SND_ASYNC);

		auto bullet = _parent->scene->makeEntity();

		if (_direction == 1)
			bullet->setPosition(Vector2f(_parent->getPosition().x + 52.f, _parent->getPosition().y + 65.f));
		else
			bullet->setPosition(Vector2f(_parent->getPosition().x - 52.f, _parent->getPosition().y + 65.f));

		bullet->addComponent<BulletComponent>(_direction, "bullet_cannon");

		auto p = bullet->addComponent<PhysicsComponent>(true, Vector2f(4.0f, 4.0f));
		p->setRestitution(0.04f);
		p->setFriction(.005f);
		//p->impulse(sf::rotate(Vector2f(0, 15.f), -_parent->getRotation()));

		if (_direction == 1)
			p->impulse(Vector2f(10.f, 10.f));
		else
			p->impulse(Vector2f(-10.f, 10.f));

		bullet->addComponent<HurtComponent>();

		_shootingFreezer = 200;
	}
	else if (_shootingFreezer > 0)
		_shootingFreezer--;
}