#pragma once
#include "Character.h"

class Enemy : public Character {
private:
	float _speed;
	float directionX;
	float directionY;

public:
	void update(double dt) override;
	Enemy();
	void render(sf::RenderWindow &window) const override;
};