#include "cmp_lift.h"
#include <LevelSystem.h>
#include "cmp_player_physics.h"
#include "components_controls.h"
#include <engine.h>
#include <iostream>

using namespace sf;
using namespace std;


LiftComponent::LiftComponent(Entity* p, Vector2f loc, Vector2f size) : Component(p) {

	_localization = loc;
	_size = size;
}

void LiftComponent::update(double dt) {

	if (Keyboard::isKeyPressed(keyUp)) {
		if (liftArea(_parent->scene->ents.list[1]->getPosition())) {

			_parent->scene->ents.list[1]->GetCompatibleComponent<PlayerPhysicsComponent>()[0]->impulse(Vector2f(0, -0.5f));
		}
	}
}


bool LiftComponent::liftArea(const sf::Vector2f& pos) {

	if (pos.x >= _localization.x && pos.x <= (_localization.x + _size.x)) {
		if (pos.y >= _localization.y && pos.y <= (_localization.y + _size.y)) {

			return true;
		}
	}

	return false;
}


