#pragma once
#include "Entity.h"

class Ghost : public Entity {
	private:
		float _speed;
		float directionX;
		float directionY;
		
	public:
		void update(double dt) override;
		Ghost();
		void render(sf::RenderWindow &window) const override;
};