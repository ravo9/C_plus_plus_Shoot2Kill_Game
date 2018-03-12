#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Character.h"

using namespace sf;
using namespace std;

void Enemy::update(double dt) {

	if (this->getPosition().x > 500 || this->getPosition().x < 100)
		directionX *= -1;

	move({ directionX * _speed * float(dt), directionY * _speed * float(dt) });
	//Character::update(dt);
}

Enemy::Enemy() : _speed(2.0f), Character(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Red);

	_shape->setOrigin(Vector2f(-400.f, -300.f));

	directionX = (float)(1);
}

void Enemy::render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}