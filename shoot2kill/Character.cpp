#include "Character.h"

using namespace sf;
using namespace std;

const Vector2f Character::getPosition() { return _position; }

void Character::setPosition(const Vector2f &pos) { _position = pos; }

void Character::move(const Vector2f &pos) { _position += pos; }

void Character::update(const double dt) {
	_shape->setPosition(_position);
}

Character::Character(unique_ptr<Shape> s) : _shape(std::move(s)) {}