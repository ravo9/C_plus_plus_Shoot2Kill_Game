#include "cmp_hurt_player.h"
#include "cmp_character_attributes.h"
#include "cmp_shooting.h"
#include <engine.h>

using namespace std;
using namespace sf;



void HurtComponent::update(double dt) {

  if (auto pl = _player) {
	// There was 25;
	// Later 50
    if (length(pl->getPosition() - _parent->getPosition()) < 50.0) {
      
	  int newHp = pl->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getHpValue() - 5;
	  pl->GetCompatibleComponent<CharacterAttributesComponent>()[0]->setHpValue(newHp);
	  
	  if (newHp <= 0)
		  pl->setAlive(false);
		  //pl->setForDelete();

      _parent->setForDelete();
    }
  }

  for (auto _enemy : _enemies) {

	  if (auto pl = _enemy.lock()) {
		  // There was 25
		  if (length(pl->getPosition() - _parent->getPosition()) < 74.0) {

			  /*int newHp = pl->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getHpValue() - _player->GetCompatibleComponent<ShootingComponent>()[0]->getInjuryRate();
			  pl->GetCompatibleComponent<CharacterAttributesComponent>()[0]->setHpValue(newHp);
			  if(newHp <= 0)
					pl->setForDelete();*/
			
			  /*int newHp = pl->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getHpValue() - 40;
			  pl->GetCompatibleComponent<CharacterAttributesComponent>()[0]->setHpValue(newHp);
			  if (newHp <= 0)
				  pl->setForDelete();*/

			  pl->setForDelete();
			  _parent->setForDelete();
		  }
	  }
  }
}

HurtComponent::HurtComponent(Entity* p)
    : Component(p), _player(_parent->scene->ents.list[1]) {

	auto enemies = _parent->scene->ents.find("enemy");
	for (auto e : enemies) {
		_enemies.push_back(e);
	}
}
