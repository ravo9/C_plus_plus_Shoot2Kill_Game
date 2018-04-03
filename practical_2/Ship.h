// If I understood tht well - we are hiding the default constructor
// and prevent from being used by 'explicit' word, because we want
// to make it unaccessible. We want to make only the second one 
// possible to be used?

#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
protected:
	sf::IntRect _sprite;
	// Default constructor is hidden
	Ship();
	
public:
	// Constructor that takes a sprite
	explicit Ship(sf::IntRect ir);
	// Pure virtual deconstructor -- makes this an abstract class
	virtual ~Ship() = 0;
	// Update, virtual so can be overrided, but no pure virtual
	virtual void Update(const float &dt);
};


class Invader : public Ship {
public:
	static bool direction;
	static float speed;
	Invader(sf::IntRect ir, sf::Vector2f pos);
	Invader();
	void Update(const float &dt) override;
};

class Player : public Ship {
public:
	Player();
	void Update(const float &dt) override;
};