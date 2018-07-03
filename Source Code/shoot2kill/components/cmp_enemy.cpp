#include "cmp_enemy.h"
#include "cmp_sprite.h"
#include "cmp_physics.h"
#include "cmp_enemy_ai.h"
#include "cmp_shooting.h"
#include "cmp_character_attributes.h"
#include <LevelSystem.h>

using namespace std;
using namespace sf;

void EnemyComponent::update(double dt) {}

// Enemy Types: 0, 1, 2
EnemyComponent::EnemyComponent(Entity* p, int enemyNumber, int enemyType)
    : Component(p) {

	_parent->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[enemyNumber]));

	if (!_spritesheet.loadFromFile("res/img/enemySpritesheetColts.png"))
		cerr << "Failed to load spritesheet!" << endl;
	else
		cout << "Texture loaded!";

	auto s2 = _parent->addComponent<SpriteComponent>();
	s2->getSprite().setTexture(_spritesheet);
	s2->getSprite().setTextureRect(IntRect(0, 0, 70, 140));
	s2->getSprite().setOrigin(35.f, 70.f);

	_parent->addComponent<PhysicsComponent>(true, Vector2f(70.f, 140.f));
	_parent->addComponent<EnemyAIComponent>();
	_parent->addTag("enemy");
	_parent->addComponent<CharacterAttributesComponent>();
	_parent->addComponent<ShootingComponent>();
}
