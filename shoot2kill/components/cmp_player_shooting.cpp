#include "cmp_bullet.h"
#include "cmp_hurt_player.h"
#include "cmp_player_shooting.h"
#include "engine.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace std;
using namespace sf;

void ShootingComponent::update(double dt) {

	if (Keyboard::isKeyPressed(Keyboard::LControl)) {
		shootLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::LAlt)) {
		shootRight();
	}
}

void ShootingComponent::shootLeft() const {

	auto bullet = _parent->scene->makeEntity();
	bullet->setPosition(Vector2f(_parent->getPosition().x - 20.f, _parent->getPosition().y));
	//bullet->addComponent<HurtComponent>();
	bullet->addComponent<BulletComponent>();

	auto s = bullet->addComponent<ShapeComponent>();
	s->setShape<sf::CircleShape>(1.f);
	s->getShape().setFillColor(Color::Red);
	s->getShape().setOrigin(1.f, 1.f);

	auto p = bullet->addComponent<PhysicsComponent>(true, Vector2f(1.f, 1.f));
	p->setRestitution(0.04f);
	p->setFriction(.005f);
	//p->impulse(sf::rotate(Vector2f(0, 15.f), -_parent->getRotation()));
	p->impulse(Vector2f(-30.f, -5.f));

	bullet->addComponent<HurtComponentEnemy>();
}

void ShootingComponent::shootRight() const {

	auto bullet = _parent->scene->makeEntity();
	bullet->setPosition(Vector2f(_parent->getPosition().x + 20.f, _parent->getPosition().y));
	//bullet->addComponent<HurtComponent>();
	bullet->addComponent<BulletComponent>();

	auto s = bullet->addComponent<ShapeComponent>();
	s->setShape<sf::CircleShape>(1.f);
	s->getShape().setFillColor(Color::Red);
	s->getShape().setOrigin(1.f, 1.f);

	auto p = bullet->addComponent<PhysicsComponent>(true, Vector2f(1.f, 1.f));
	p->setRestitution(.04f);
	p->setFriction(.005f);
	//p->impulse(sf::rotate(Vector2f(0, 15.f), -_parent->getRotation()));
	p->impulse(Vector2f(30.f, -5.f));

	bullet->addComponent<HurtComponentEnemy>();
}


ShootingComponent::ShootingComponent(Entity* p)
	: Component(p) {}
