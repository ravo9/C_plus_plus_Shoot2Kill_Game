#include "player.h"

using namespace sf;
using namespace std;

void Player::update(double dt) {

	// Handle movement
	float  directionX = 0.0f;
	float  directionY = 0.0f;

	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		directionX--;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		directionX++;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		directionY--;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		directionY++;
	}

	move({ directionX * 200.0f * float(dt), directionY * 200.0f * float(dt)});

	Entity::update(dt);
}

Player::Player() : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(-400.f, -300.f));
}

void Player::render(sf::RenderWindow &window) const {
		window.draw(*_shape);
}