#include "cmp_actor_movement.h"
#include <LevelSystem.h>
#include <engine.h>
#include <iostream>
using namespace sf;
using namespace std;

void ActorMovementComponent::update(double dt) {}

ActorMovementComponent::ActorMovementComponent(Entity* p)
    : _speed(100.0f), Component(p) {}

bool ActorMovementComponent::validMove(const sf::Vector2f& pos) {
  return (LevelSystem::getTileAt(pos) != LevelSystem::WALL);
  // return true;
}

void ActorMovementComponent::move(const sf::Vector2f& p) {
  auto pp = _parent->getPosition() + p;

  // It was already
  /*if (validMove(pp)) {
    _parent->setPosition(pp);
	_parent->setPosition(Vector2f(0, 0));
  }*/

  // It is mine
  _parent->setPosition(Vector2f(_parent->getPosition().x + 5.f, _parent->getPosition().y - 3.f));
  
}

void ActorMovementComponent::move(float x, float y) {
  move(Vector2f(x, y));
}
