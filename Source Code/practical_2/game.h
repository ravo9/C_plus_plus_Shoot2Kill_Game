#pragma once
#include "Ship.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>

constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;
constexpr uint16_t invaders_rows = 5;
constexpr uint16_t invaders_columns = 12;

const  sf::Keyboard::Key  controls[3] = {
	sf::Keyboard::Left,
	sf::Keyboard::Right,
	sf::Keyboard::Space,
};

extern sf::Texture spritesheet;
extern std::vector <Ship *> ships;
extern std::vector <Bullet *> bullets;