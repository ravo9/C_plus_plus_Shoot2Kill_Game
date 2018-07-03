#include "cmp_enemy_ai.h"
#include "cmp_physics.h"
#include "system_physics.h"
#include "cmp_shooting.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>

using namespace std;
using namespace sf;

void EnemyAIComponent::update(double dt) {

	_direction.x = _parent->GetCompatibleComponent<SpriteComponent>()[0]->getDirection();

	// Jump
	if (_jumpFreezer <= 0) {
		_parent->GetCompatibleComponent<PhysicsComponent>()[0]->impulse({ (float)(dt * _direction.x * _speed), -6 });
		_jumpFreezer = 4000;
	}
	if (_jumpFreezer >= 0)
		_jumpFreezer--;

	// Direction change
	if (_changeDirectionFreezer <= 0) {
		_parent->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();
		_changeDirectionFreezer = 2500;
	}
	if (_changeDirectionFreezer >= 0)
		_changeDirectionFreezer--;

	// Impulse
	if (_parent->GetCompatibleComponent<PhysicsComponent>()[0]->getVelocity().x < 100 && _parent->GetCompatibleComponent<PhysicsComponent>()[0]->getVelocity().x > -100)
		_parent->GetCompatibleComponent<PhysicsComponent>()[0]->impulse({ (float)(dt * _direction.x * 70), 0});

	// Attack
	if (abs(length(_parent->getPosition() - _parent->scene->ents.list[1]->getPosition())) < 300) {

		// Enemy on left-hand (player) side.
		if ((_parent->scene->ents.list[1]->getPosition().x < _parent->getPosition().x) && _parent->GetCompatibleComponent<SpriteComponent>()[0]->getDirection() == -1)
			_parent->GetCompatibleComponent<ShootingComponent>()[0]->shoot();
		// Enemy on right-hand (player) side.
		else if ((_parent->scene->ents.list[1]->getPosition().x >= _parent->getPosition().x) && _parent->GetCompatibleComponent<SpriteComponent>()[0]->getDirection() == 1)
			_parent->GetCompatibleComponent<ShootingComponent>()[0]->shoot();
	}
}

void EnemyAIComponent::setSpeed(float speed) { _speed = speed; }

EnemyAIComponent::EnemyAIComponent(Entity* p) : Component(p) {
  _originPosition = _parent->getPosition();
  _direction = Vector2f(1.0f, 0);
  _changeDirectionFreezer = 0;
  _jumpFreezer = 4000;
  _attackFreezer = 0;
  _speed = 60.f;
}
