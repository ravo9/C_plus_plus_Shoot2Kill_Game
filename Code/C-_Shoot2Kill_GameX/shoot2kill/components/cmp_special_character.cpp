#include "cmp_special_character.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_physics.h"
#include <LevelSystem.h>

using namespace std;
using namespace sf;

void SpecialCharacterComponent::update(double dt) {}

SpecialCharacterComponent::SpecialCharacterComponent(Entity* p, string type)
    : Component(p) {

	if (type == "Boss") {

		_parent->setPosition(Vector2f(0.f, 0.f));
		_spritesheet.loadFromFile("res/img/bossSprite.png");
			
		auto s2 = _parent->addComponent<SpriteComponent>();
		s2->getSprite().setTexture(_spritesheet);
		s2->getSprite().setTextureRect(IntRect(0, 0, 128, 120));
		s2->getSprite().setOrigin(64.f, 60.f);

		_parent->addTag("Boss");

	} else if (type == "Camilla") {

		_parent->setPosition(Vector2f(0.f, 0.f));
		_spritesheet.loadFromFile("res/img/camilla.png");

		auto s2 = _parent->addComponent<SpriteComponent>();
		s2->getSprite().setTexture(_spritesheet);
	
		_parent->addTag("Camilla");
	}
}