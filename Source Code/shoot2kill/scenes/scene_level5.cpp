#include "scene_level5.h"
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


void Level5Scene::Load() {

  cout << "Scene 5 Load" << endl;
  ls::loadLevelFile("res/level_5.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));


  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/lvl05_background.png");
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

  // Create enemy
  {
	  auto enemy = makeEntity();
	  enemy->addComponent<EnemyComponent>(1, 0);
	  enemy->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();
	  enemy->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(30);
  }

  // Create bonus (bazooka)
  {
	  auto bonusBazooka = makeEntity();
	  bonusBazooka->addComponent<BonusComponent>("Bonus Bazooka", Vector2f(510.f, 655.f));
  }

  // Add the first lift (ladder)
  {
	  auto lift = makeEntity();
	  lift->addComponent<LiftComponent>(Vector2f(925, 485), Vector2f(100, 250));
  }

  // Add the second lift (ladder)
  {
	  auto lift = makeEntity();
	  lift->addComponent<LiftComponent>(Vector2f(150, 250), Vector2f(100, 250));
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

  cout << " Scene 5 Load Done" << endl;
  setLoaded(true);
}

void Level5Scene::UnLoad() {
  cout << "Scene 5 UnLoad" << endl;
  ls::unload();
  Scene::UnLoad();
}


void Level5Scene::Update(const double& dt) {

	if (ls::getTileAt(ents.list[1]->getPosition()) == ls::END)
		Engine::ChangeScene((Scene*)&finalLevel);
	else if (!ents.list[1]->isAlive())
		Engine::ChangeScene((Scene*)&level5);
	else
		Scene::Update(dt);
}

void Level5Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
