#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>
#include "../components/cmp_text.h"

class GameInfoDisplayComponent : public Component {
protected:
	int hpValue;
	string ammoValue;
	string currentGun;
	shared_ptr<TextComponent> infoTextDisplay;

public:
  void update(double dt) override;
  void render() override {}
  explicit GameInfoDisplayComponent(Entity* p);
  GameInfoDisplayComponent() = delete;
};
