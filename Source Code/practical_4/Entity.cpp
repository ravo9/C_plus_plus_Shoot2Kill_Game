#include "Entity.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f &pos) { _position = pos; }

void Entity::move(const Vector2f &pos) { _position += pos; }

void Entity::update(const double dt) {
	_shape->setPosition(_position);
}

void EntityManager::update(const double dt) {

	for (int i = 0; i < list.size(); i++)
		list[i]->update(dt);
}

void EntityManager::render(sf::RenderWindow &window) {
	for (int i = 0; i < list.size(); i++)
		list[i]->render(window);
}

// It's not a constructor. There is a parameter set after the colon.
Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}