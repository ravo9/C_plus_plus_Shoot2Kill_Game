#include "scene_level1.h"
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
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


void Level1Scene::Load() {

  cout << " Scene 1 Load" << endl;
  ls::loadLevelFile("res/level_1.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/lvl01_background.png");
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
  }

  // Create bonus (colt)
  {
	  auto bonusGun1 = makeEntity();
	  bonusGun1->addComponent<BonusComponent>("Bonus Colt 1911", Vector2f(80.f, 310.f));
  }

  // Add the first lift (ladder)
  {
	  auto lift = makeEntity();
	  lift->addComponent<LiftComponent>(Vector2f(235, 365), Vector2f(100, 360));
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

  cout << " Scene 1 Load Done" << endl;
  setLoaded(true);
}

void Level1Scene::UnLoad() {
  cout << "Scene 1 Unload" << endl;
  ls::unload();
  Scene::UnLoad();
}

void Level1Scene::Update(const double& dt) {

	if (ls::getTileAt(ents.list[1]->getPosition()) == ls::END)
		Engine::ChangeScene((Scene*)&level2);
	else if (!ents.list[1]->isAlive())
		Engine::ChangeScene((Scene*)&level1);
	else
		Scene::Update(dt);
}

void Level1Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
