#pragma once

#include "ecm.h"
#include "cmp_bullet.h"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <string>

class ShootingComponent : public Component {
protected:
	int _shootingFreezer;
	int _recoilForce;
	int _freezingMode;
	int _injuryRate;
	std::string _bulletType;
	//sf::Sound _shotSound;
	//sf::SoundBuffer _soundBuffer;

public:
	void shoot();
	void update(double dt) override;
	void render() override {}
	void setInjuryRate(int newInjuryRate);
	int getInjuryRate();
	void setFreezingMode(int newFreezingMode);
	void setBulletType(std::string newBulletType);
	std::string getBulletType();
	explicit ShootingComponent(Entity* p);
	ShootingComponent() = delete;
};