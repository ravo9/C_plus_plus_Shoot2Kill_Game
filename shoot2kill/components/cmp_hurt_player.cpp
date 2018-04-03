#include "cmp_hurt_player.h"
#include <engine.h>

using namespace std;
using namespace sf;

void HurtComponent::update(double dt) {
  if (auto pl = _player.lock()) {
	// There was 25;
    if (length(pl->getPosition() - _parent->getPosition()) < 50.0) {
      pl->setForDelete();
      _parent->setForDelete();
    }
  }
}

HurtComponent::HurtComponent(Entity* p)
    : Component(p), _player(_parent->scene->ents.find("player")[0]) {}


void HurtComponentEnemy::update(double dt) {
	if (auto pl = _enemy.lock()) {
		// There was 25
		if (length(pl->getPosition() - _parent->getPosition()) < 50.0) {
			pl->setForDelete();
			_parent->setForDelete();
		}
	}
}

HurtComponentEnemy::HurtComponentEnemy(Entity* p)
	: Component(p), _enemy(_parent->scene->ents.find("enemy")[0]) {}
