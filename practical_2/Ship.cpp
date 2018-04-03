#include "Ship.h"
#include "game.h"
#include "bullet.h"

using namespace sf;
using namespace std;

bool Invader::direction = -1.0;
float Invader::speed = 20.f;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

// Define the ship deconstructor
// Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;


Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gameWidth - 16) ||
		(!direction && getPosition().x < 16)) {
			direction = !direction;
			for (int i = 0; i < ships.size(); ++i) {
				ships[i]->move(0, 24);
			}
	}
}


Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
	setPosition({ gameHeight * .5f + 80, gameHeight - 32.f });
}

void Player::Update(const float &dt) {
	//???
	Ship::Update(dt);

	// Handle  player  control
	float  direction = 0.0f;

	if (Keyboard::isKeyPressed(controls[0])) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		direction++;
	}

	move(direction * 200.0f * dt, 0);

	// Bullets update
	static vector<Bullet*> bullets;

	if (Keyboard::isKeyPressed(controls[2])) {
		Bullet::Fire(getPosition(), 1);
	}

	for (const auto s : bullets) {
		s->Update(dt);
	}
}