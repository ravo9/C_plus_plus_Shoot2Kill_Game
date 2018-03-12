#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ghost.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

void Ghost::update(double dt) {

	if (this->getPosition().x < -400 || this->getPosition().x > 400)
		directionX *= -1;
	if (this->getPosition().y < -400 || this->getPosition().y > 400)
		directionY *= -1;

	move({ directionX * _speed * float(dt), directionY * _speed * float(dt)});
	Entity::update(dt);
}

Ghost::Ghost() : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Red);
	_shape->setOrigin(Vector2f(-400.f, -300.f));

	directionX = (float)(rand() % 3 - 1);
	directionY = (float)(rand() % 3 - 1);
}

void Ghost::render(sf::RenderWindow &window) const {
	//window.draw(*_shape);
	Renderer::queue(&(*_shape));
}