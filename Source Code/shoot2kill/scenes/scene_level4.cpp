#include "scene_level4.h"
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


void Level4Scene::Load() {

  cout << "Scene 4 Load" << endl;
  ls::loadLevelFile("res/level_4.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/lvl04_background.png");
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
	  enemy->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(40);
  }

  // Create enemy
  {
	  auto enemy = makeEntity();
	  enemy->addComponent<EnemyComponent>(1, 0);
	  enemy->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();
	  enemy->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(20);
  }

  // Create enemy
  {
	  auto enemy = makeEntity();
	  enemy->addComponent<EnemyComponent>(2, 0);
	  enemy->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(70);
  }

  // Create bonus (ar-15)
  {
	  auto bonusBazooka = makeEntity();
	  bonusBazooka->addComponent<BonusComponent>("Bonus AR-15 Semiautomatic", Vector2f(880.f, 405.f));
  }

  // Add the first lift (ladder)
  {
	  auto lift = makeEntity();
	  lift->addComponent<LiftComponent>(Vector2f(1235, 250), Vector2f(100, 768));
  }

  // Add the second lift (ladder)
  {
	  auto lift = makeEntity();
	  lift->addComponent<LiftComponent>(Vector2f(705, 0), Vector2f(100, 250));
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

  cout << " Scene 4 Load Done" << endl;
  setLoaded(true);
}

void Level4Scene::UnLoad() {
  cout << "Scene 4 UnLoad" << endl;
  ls::unload();
  Scene::UnLoad();
}


void Level4Scene::Update(const double& dt) {

	if (ls::getTileAt(ents.list[1]->getPosition()) == ls::END)
		Engine::ChangeScene((Scene*)&level5);
	else if (!ents.list[1]->isAlive())
		Engine::ChangeScene((Scene*)&level4);
	else
		Scene::Update(dt);
}

void Level4Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
