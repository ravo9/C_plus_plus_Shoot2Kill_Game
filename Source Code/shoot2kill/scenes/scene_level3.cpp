#include "scene_level3.h"
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


void Level3Scene::Load() {

  cout << "Scene 3 Load" << endl;
  ls::loadLevelFile("res/level_3.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/lvl03_background.png");
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

  // Create bonus (bazooka)
  {
	  auto bonusBazooka = makeEntity();
	  bonusBazooka->addComponent<BonusComponent>("Bonus Bazooka", Vector2f(540.f, 655.f));
  }

  // Add the first lift (ladder)
  {
	  auto lift = makeEntity();
	  lift->addComponent<LiftComponent>(Vector2f(450, 250), Vector2f(100, 230));
  }

  // Add the second lift (ladder)
  {
	  auto lift = makeEntity();
	  lift->addComponent<LiftComponent>(Vector2f(1130, 490), Vector2f(100, 230));
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

  cout << " Scene 3 Load Done" << endl;
  setLoaded(true);
}

void Level3Scene::UnLoad() {
  cout << "Scene 3 UnLoad" << endl;
  ls::unload();
  Scene::UnLoad();
}


void Level3Scene::Update(const double& dt) {

	if (ls::getTileAt(ents.list[1]->getPosition()) == ls::END)
		Engine::ChangeScene((Scene*)&level4);
	else if (!ents.list[1]->isAlive())
		Engine::ChangeScene((Scene*)&level3);
	else
		Scene::Update(dt);
}

void Level3Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
