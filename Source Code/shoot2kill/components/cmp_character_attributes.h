#pragma once
#include <string>
#include "ecm.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CharacterAttributesComponent : public Component {
protected:
  int _hp;
  int _ammo;
  string _currentGun;
  sf::Texture _spritesheet;

public:
	void update(double dt) override;
	void render() override {};
	void changeGun(string newGun);
	void setAmmoValue(int newAmmo);
	void decrementAmmoValue();
	void setHpValue(int newHp);
	string getCurrentGun();
	string getAmmoValue();
	int getHpValue();
	explicit CharacterAttributesComponent(Entity* p);
	CharacterAttributesComponent() = delete;
};
