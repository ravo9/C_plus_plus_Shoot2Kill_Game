#include "cmp_character_attributes.h"
#include "../components/cmp_text.h"
#include "cmp_shooting.h"
#include <string>
#include "engine.h"

using namespace std;
using namespace sf;

CharacterAttributesComponent::CharacterAttributesComponent(Entity* p) : Component(p), _hp(100), _ammo(9999), _currentGun("Colt Commander") {};

int CharacterAttributesComponent::getHpValue() { return _hp; };

void CharacterAttributesComponent::setHpValue(int newHp) { _hp = newHp; };

string CharacterAttributesComponent::getAmmoValue() { 
	
	if (_currentGun == "Default")
		return "Unlimited";
	else
		return std::to_string(_ammo); 
};

void CharacterAttributesComponent::setAmmoValue(int newAmmo) { _ammo = newAmmo; };

void CharacterAttributesComponent::decrementAmmoValue() { _ammo--; };

string CharacterAttributesComponent::getCurrentGun() { return _currentGun; };


void CharacterAttributesComponent::changeGun(string newGun) { 
	_currentGun = newGun; 

	if (_currentGun == "Colt 1911") {

		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->setWiderSpriteType(false);

		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setInjuryRate(10);
		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setFreezingMode(500);
		_ammo = 10;

		// Set proper character texture
		_spritesheet.loadFromFile("res/img/simonSpritesheetColts.png");
		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheet);

		// Set proper bullet texture
		_parent->scene->ents.list[1]->GetCompatibleComponent<ShootingComponent>()[0]->setBulletType("bullet_small");
	} 
	else if (_currentGun == "AR-15 Semiautomatic") {

		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->setWiderSpriteType(false);

		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setInjuryRate(5);
		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setFreezingMode(100);
		_ammo = 60;

		// Set proper character texture
		_spritesheet.loadFromFile("res/img/simonSpritesheetAr15.png");
		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheet);

		// Set proper bullet texture
		_parent->scene->ents.list[1]->GetCompatibleComponent<ShootingComponent>()[0]->setBulletType("bullet_long");
	} 
	else if (_currentGun == "Bazooka") {

		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->setWiderSpriteType(true);

		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setInjuryRate(100);
		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setFreezingMode(1000);
		_ammo = 1;

		// Set proper character texture
		_spritesheet.loadFromFile("res/img/simonSpritesheetBazooka.png");
		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheet);

		// Set proper bullet texture
		_parent->scene->ents.list[1]->GetCompatibleComponent<ShootingComponent>()[0]->setBulletType("bullet_bazooka");
	}
	else { 

		// Colt Commander

		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->setWiderSpriteType(false);
		
		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setInjuryRate(10);
		_parent->GetCompatibleComponent<ShootingComponent>()[0]->setFreezingMode(500);
		_ammo = 9999;

		// Set proper character texture
		_spritesheet.loadFromFile("res/img/simonSpritesheetColts.png");
		_parent->scene->ents.list[1]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheet);

		// Set proper bullet texture
		_parent->scene->ents.list[1]->GetCompatibleComponent<ShootingComponent>()[0]->setBulletType("bullet_small");
	}
};

void CharacterAttributesComponent::update(double dt) {

	if (_ammo <= 0)
		changeGun("Colt Commander"); // Default gun
};