#include "cmp_bullet.h"
#include "cmp_hurt_player.h"
#include "cmp_player.h"
#include "cmp_shooting.h"
#include "cmp_character_attributes.h"
#include "components_controls.h"
#include "engine.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>

using namespace std;
using namespace sf;

void ShootingComponent::update(double dt) {

	if (Keyboard::isKeyPressed(keyShoot)) {
		if (_parent->GetCompatibleComponent<PlayerComponent>().size() > 0)
			shoot();
	}

	if (_shootingFreezer > 0)
	_shootingFreezer--;
}

void ShootingComponent::shoot() {

	int direction = _parent->GetCompatibleComponent<SpriteComponent>()[0]->getDirection();

	if (_shootingFreezer <= 0) {

		PlaySound(TEXT("res/sound/coltSound.wav"), NULL, SND_FILENAME | SND_ASYNC);

		auto bullet = _parent->scene->makeEntity();

		if (direction == 1) 
			bullet->setPosition(Vector2f(_parent->getPosition().x + 70.f, _parent->getPosition().y - 25.f));
		else
			bullet->setPosition(Vector2f(_parent->getPosition().x - 70.f, _parent->getPosition().y - 25.f));

		bullet->addComponent<BulletComponent>(direction, _bulletType);

		auto p = bullet->addComponent<PhysicsComponent>(true, Vector2f(1.0f, 1.0f));
		p->setRestitution(0.04f);
		p->setFriction(.005f);
		//p->impulse(sf::rotate(Vector2f(0, 15.f), -_parent->getRotation()));

		if (direction == 1)
			p->impulse(Vector2f(200.f, -1.f));
		else 
			p->impulse(Vector2f(-200.f, -1.f));

		bullet->addComponent<HurtComponent>();

	    _shootingFreezer = _freezingMode;

		if (_parent->GetCompatibleComponent<PlayerComponent>().size() > 0)
			_parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->decrementAmmoValue();
	}
}

void ShootingComponent::setInjuryRate(int newInjuryRate) {
	_injuryRate = newInjuryRate;
}
int ShootingComponent::getInjuryRate() {
	return _injuryRate;
}

void ShootingComponent::setFreezingMode(int newFreezingMode) {
	_freezingMode = newFreezingMode;
}

void ShootingComponent::setBulletType(string newBulletType) {
	_bulletType = newBulletType;
}

std::string ShootingComponent::getBulletType() {
	return _bulletType;
}

ShootingComponent::ShootingComponent(Entity* p)
	: Component(p) {

	//Default values - Colt Commander
	setInjuryRate(10);
	setFreezingMode(150);
	_bulletType = "bullet_small";
}
