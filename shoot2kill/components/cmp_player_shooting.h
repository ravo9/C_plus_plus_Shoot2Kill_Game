#pragma once

#include "ecm.h"
#include "cmp_bullet.h"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class ShootingComponent : public Component {
protected:
	void shootLeft() const;
	void shootRight() const;

public:
	void update(double dt) override;
	void render() override {}
	explicit ShootingComponent(Entity* p);
	ShootingComponent() = delete;
};