#include "bullet.h"
#include "game.h"

using namespace sf;
using namespace std;

Bullet::Bullet() {};

Bullet::Bullet(const sf::Vector2f &pos, const bool mode) : Sprite() {
	setTexture(spritesheet);
	setTextureRect(IntRect(64, 32, 32, 32));
	setOrigin(200, 200);
	setPosition(pos);
	_mode = mode;
}

void Bullet::Render(sf::RenderWindow &window) {

	for (int i = 0; i < 255; ++i) {
		bullets[i] = new Bullet({ -100, -100 }, 1);
		//window.draw(*bul);
	}
}

void Bullet::Fire(const sf::Vector2f & pos, const bool mode) {
	//bullets[0].setPosition(pos);
}

void Bullet::Update(const float &dt) {
	//_Update(dt);
}


void Bullet::_Update(const float &dt) {
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
		// Off screen - do nothing
		return;
	}
	else {
		move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));

		//??
		//const FloatRect boundingBox = getGlobalBounds();

		for (auto s : ships) {
			;
			/*if (!_mode && s == player) {
				// Player bullets don't collide with player.
				continue;
			}
			if (_mode && s != player) {
				// Invader bullets don't collide with other invaders.
				continue;
			}
			if (!s->is_exploded() && s - getGlobalBounds().intersects(boundingBox)) {
				// Explode the ship.
				s->Explode();
				// Warp bullet off-screen.
				setPosition(-100, -100);
				return;
			}*/
		}
	}
}