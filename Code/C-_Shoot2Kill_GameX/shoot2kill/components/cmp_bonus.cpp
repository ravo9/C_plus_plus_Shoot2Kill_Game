#include "cmp_bonus.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_character_attributes.h"
#include <engine.h>

using namespace std;
using namespace sf;

void BonusComponent::update(double dt) {

	if (length(_parent->scene->ents.list[1]->getPosition() - _parent->getPosition()) < 20.0) {
		_parent->setForDelete();

		if (_type == "Bonus Colt 1911")
			_parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->changeGun("Colt 1911");

		if (_type == "Bonus AR-15 Semiautomatic")
			_parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->changeGun("AR-15 Semiautomatic");

		if (_type == "Bonus Bazooka")
			_parent->scene->ents.list[1]->GetCompatibleComponent<CharacterAttributesComponent>()[0]->changeGun("Bazooka");
	}
}

BonusComponent::BonusComponent(Entity* p, std::string type, sf::Vector2f position)
	: Component(p) {
	_type = type;
	_parent->setPosition(position);

	if (_type == "Bonus Colt 1911") {

		if (!_spritesheet.loadFromFile("res/img/bonus_colt.png"))
			cerr << "Failed to load spritesheet!" << endl;
		else
			cout << "Texture loaded!";

		auto s2 = _parent->addComponent<SpriteComponent>();
		s2->getSprite().setTexture(_spritesheet);
		s2->getSprite().setTextureRect(IntRect(0, 0, 60, 60));
		s2->getSprite().setOrigin(30.f, 30.f);

	} else if (_type == "Bonus AR-15 Semiautomatic") {

		if (!_spritesheet.loadFromFile("res/img/bonus_ar15.png"))
			cerr << "Failed to load spritesheet!" << endl;
		else
			cout << "Texture loaded!";

		auto s2 = _parent->addComponent<SpriteComponent>();
		s2->getSprite().setTexture(_spritesheet);
		s2->getSprite().setTextureRect(IntRect(0, 0, 60, 60));
		s2->getSprite().setOrigin(30.f, 30.f);

	} else if (_type == "Bonus Bazooka") {

		if (!_spritesheet.loadFromFile("res/img/bonus_bazooka.png"))
			cerr << "Failed to load spritesheet!" << endl;
		else
			cout << "Texture loaded!";

		auto s2 = _parent->addComponent<SpriteComponent>();
		s2->getSprite().setTexture(_spritesheet);
		s2->getSprite().setTextureRect(IntRect(0, 0, 60, 60));
		s2->getSprite().setOrigin(30.f, 30.f);
	}
}
