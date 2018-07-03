#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Entity {

	protected:
		//std::unique_ptr<sf::Shape> _shape;
		sf::Vector2f _position;
		Entity(std::unique_ptr<sf::Shape> shp);
		
	public:
		Entity() = delete;
		std::unique_ptr<sf::Shape> _shape;
		virtual ~Entity() = default;
		virtual void update(const double dt);
		virtual void render(sf::RenderWindow &window) const = 0;
		const sf::Vector2f getPosition();
		void setPosition(const sf::Vector2f &pos);
		void move(const sf::Vector2f &pos);
};

struct EntityManager {
	// I have changed the code from workbook into this line 24 and it works!
	std::vector<Entity*> list;
	void update(double dt);
	void render(sf::RenderWindow &window);
};