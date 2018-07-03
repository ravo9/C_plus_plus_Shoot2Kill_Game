#pragma once
#include "engine.h"
#include <ecm.h>
#include <SFML/Graphics.hpp>

class MenuOptionsScene : public Scene {
protected:
	int _chosenValue;
	int _clickFreezer;
	sf::Texture _spritesheetBtn1;
	sf::Texture _spritesheetBtn2;
	sf::Texture _spritesheetBtn3;
	sf::Texture _spritesheetBtn4;
	sf::Texture _spritesheetBtnCustom;

public:
  MenuOptionsScene() = default;
  ~MenuOptionsScene() override = default;
  void Load() override;
  void SetKey(int value);
  void Update(const double& dt) override;
};