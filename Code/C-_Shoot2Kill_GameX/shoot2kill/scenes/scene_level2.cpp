#include "scene_level2.h"
#include "../components/cmp_lift.h"
#include "../components/cmp_background.h"
#include "../components/cmp_physics.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_bonus.h"
#include "../components/cmp_player.h"
#include "../components/cmp_enemy.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_shooting.h"
#include "../components/cmp_character_attributes.h"
#include "../components/cmp_text.h"
#include "../components/cmp_hurt_player.h"
#include "../components/cmp_game_info_display.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>

using namespace std;
using namespace sf;


void Level2Scene::Load() {

  cout << "Scene 2 Load" << endl;
  ls::loadLevelFile("res/level_2.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/lvl02_background.png");
  }

  // Create player
  {
	  auto player = makeEntity();
	  player->addComponent<PlayerComponent>();
  }

  // Create enemy
  {
	  auto enemy = makeEntity();
	  enemy->addComponent<EnemyComponent>(0, 0);
	  enemy->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();
	  enemy->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(40);
  }

  // Create enemy
  {
	  auto enemy = makeEntity();
	  enemy->addComponent<EnemyComponent>(1, 0);
  }

  // Create bonus (ar-15)
  {
	  auto bonusGun2 = makeEntity();
	  bonusGun2->addComponent<BonusComponent>("Bonus AR-15 Semiautomatic", Vector2f(490.f, 405.f));
  }

  // Add HP and weapon info display
  {
	  auto hp_text = makeEntity();
	  hp_text->addComponent<GameInfoDisplayComponent>();
  }

  // Add physics colliders to level tiles.
  {
	  auto walls = ls::findTiles(ls::WALL);
	  for (auto w : walls) {
		  auto pos = ls::getTilePosition(w);
		  pos += Vector2f(20.f, 20.f); //offset to center
		  auto e = makeEntity();
		  e->setPosition(pos);
		  e->addComponent<PhysicsComponent>(false, Vector2f(40.f, 40.f));
	  }
  }

  cout << " Scene 2 Load Done" << endl;
  setLoaded(true);
}

void Level2Scene::UnLoad() {
  cout << "Scene 2 UnLoad" << endl;
  ls::unload();
  Scene::UnLoad();
}

void Level2Scene::Update(const double& dt) {

	if (ls::getTileAt(ents.list[1]->getPosition()) == ls::END)
		Engine::ChangeScene((Scene*)&level3);
	else if (!ents.list[1]->isAlive())
		Engine::ChangeScene((Scene*)&level2);
	else
		Scene::Update(dt);
}

void Level2Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
