#include <engine.h>
#include <LevelSystem.h>
#include "../components/cmp_player.h"
#include "../components/cmp_character_attributes.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_shooting.h"
#include "../components/cmp_sprite.h"

using namespace std;
using namespace sf;

void PlayerComponent::update(double dt) {}

PlayerComponent::PlayerComponent(Entity* e)
    : Component(e) {

	_parent->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));

	if (!_spritesheet.loadFromFile("res/img/simonSpritesheetColts.png"))
		cerr << "Failed to load spritesheet!" << endl;
	else
		cout << "Texture loaded!";

	auto s1 = _parent->addComponent<SpriteComponent>();
	s1->getSprite().setTexture(_spritesheet);
	s1->getSprite().setTextureRect(IntRect(0, 0, 70, 140));
	s1->getSprite().setOrigin(35.f, 70.f);

	_parent->addComponent<PlayerPhysicsComponent>(Vector2f(70.f, 140.f));

	_parent->addTag("player");
	_parent->addComponent<CharacterAttributesComponent>();
	_parent->addComponent<ShootingComponent>();	
}

