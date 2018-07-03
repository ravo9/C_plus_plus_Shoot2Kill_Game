#include <engine.h>
#include "../components/cmp_player.h"
#include "../components/cmp_character_attributes.h"
#include "cmp_game_info_display.h"

using namespace std;
using namespace sf;

void GameInfoDisplayComponent::update(double dt) {

	hpValue = _parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getHpValue();
	currentGun = _parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getCurrentGun();
	ammoValue = _parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getAmmoValue();
	infoTextDisplay->SetText("\n GUN: " + currentGun + "\n Ammo: " + ammoValue + "\n HP: " + std::to_string(hpValue) + "%");
}

GameInfoDisplayComponent::GameInfoDisplayComponent(Entity* p)
	: Component(p) {

	hpValue = _parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getHpValue();
	currentGun = _parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->getCurrentGun();
	infoTextDisplay = _parent->addComponent<TextComponent>("\n GUN: " + currentGun + "\n HP: " + std::to_string(hpValue) + "%");
    infoTextDisplay->SetColor(sf::Color(36, 255, 20, 255));
}
