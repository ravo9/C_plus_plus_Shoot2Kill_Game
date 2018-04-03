#pragma once

#include "ecm.h"

class PlayerAttributesComponent : public Component {
protected:
  int _hp;

public:
	void update(double dt) override;
	void render() override {}
	int getHpValue();
	explicit PlayerAttributesComponent(Entity* p);
	PlayerAttributesComponent() = delete;
};
