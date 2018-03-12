#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Character {

	protected:
		// It will be changed for our image (spritesheet).
		std::unique_ptr<sf::Shape> _shape;
		sf::Vector2f _position;
		Character(std::unique_ptr<sf::Shape> shp);
		
	public:
		Character() = delete;
		// Destructor.
		virtual ~Character() = default;
		virtual void update(const double dt);
		virtual void render(sf::RenderWindow &window) const = 0;
		const sf::Vector2f getPosition();
		void setPosition(const sf::Vector2f &pos);
		void move(const sf::Vector2f &pos);
};