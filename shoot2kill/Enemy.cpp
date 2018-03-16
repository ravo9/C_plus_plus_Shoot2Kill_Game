#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Character.h"

using namespace sf;
using namespace std;

void Enemy::update(double dt) {

	if (this->getPosition().x < -10 || this->getPosition().x > 10)
		directionX *= -1;

	move({ directionX * _speed * float(dt), 0 });

	std::cout << "UPDATED POS X: " << this->getPosition().x << endl;
	std::cout << "UPDATED POS Y: " << this->getPosition().y << endl;

	Character::update(dt);
}

Enemy::Enemy() : _speed(2.0f), Character(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Red);

	_shape->setOrigin(Vector2f(-100.f, -100.f));

	std::cout << "BEGINNING POS X: " << this->getPosition().x << endl;
	std::cout << "BEGINNING POS Y: " << this->getPosition().y << endl;


	directionX = (float)(-1);
}

void Enemy::render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}