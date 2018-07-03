#include "scene_level_final.h"
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
#include "../components/cmp_special_character.h"
#include "../components/cmp_conversation.h"
#include "../components/cmp_flag.h"
#include "../components/cmp_cannon.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


void LevelSceneFinal::Load() {

  cout << " Scene Final Load" << endl;
  ls::loadLevelFile("res/level_final.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/lvl_final_background.png");
  }

  // Create player
  {
	  auto player = makeEntity();
	  player->addComponent<PlayerComponent>();
  }

  // Create Camilla
  {
	  auto camilla = makeEntity();
	  camilla->addComponent<SpecialCharacterComponent>("Camilla");
	  camilla->setPosition(Vector2f(1150.f, 470.f));
  }

  // Create boss
  {
	  auto boss = makeEntity();
	  boss->addComponent<SpecialCharacterComponent>("Boss");
	  boss->setPosition(Vector2f(950.f, 550.f));
  }

  // Add conversation
  {
	  auto converation = makeEntity();
	  auto c1 = converation->addComponent<ConversationComponent>();
	  c1->addLeftSidePhrase("res/img/dialog0.png", "Camilla");
	  c1->addRightSidePhrase("res/img/dialog1.png", "player");
	  c1->addRightSidePhrase("res/img/dialog2.png", "Boss");
	  c1->setPostDialogueAction("Final");

	  auto plotFlags = makeEntity();
	  auto f1 = plotFlags->addComponent<FlagsComponent>();
	  // First flag.
	  f1->addFlag("waiting");
	  // Second flag.
	  f1->addFlag("waiting");
  }

  // Set cannon freezer
  _cannonFreezer = 1300;

  // Set enemiesAttack freezer
  _enemiesAttackFreezer = -999;

  // Add first cannon
  {
	  auto cannon = makeEntity();
	  cannon->addComponent<CannonComponent>(1);
	  cannon->setPosition(Vector2f(-266.f, 0.f));
	  cannon->setVisible(false);
  }

  // Add second cannon
  {
	  auto cannon = makeEntity();
	  cannon->addComponent<CannonComponent>(-1);
	  cannon->setPosition(Vector2f(2066.f, 0.f));
	  cannon->setVisible(false);
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

void LevelSceneFinal::UnLoad() {
  cout << "Scene 1 Unload" << endl;
  ls::unload();
  Scene::UnLoad();
}

void LevelSceneFinal::Update(const double& dt) {

  if (!ents.list[1]->isAlive())
	Engine::ChangeScene((Scene*)&finalLevel);
  else {

	  // Plot flow - 1. end of conversation (first bunch of enemies)
	  if (ents.list[5]->GetCompatibleComponent<FlagsComponent>()[0]->getFlagStatus(0) == "activateNow") {

		  // Change boss sprite.
		  ents.list[3]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTextureRect(IntRect(128, 0, 128, 120));

		  // New enemies
		  auto s1 = makeEntity();
		  s1->addComponent<EnemyComponent>(0, 0);
		  s1->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();
		  s1->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(0);

		  auto s2 = makeEntity();
		  s2->addComponent<EnemyComponent>(1, 0);
		  s2->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();

		  auto s3 = makeEntity();
		  s3->addComponent<EnemyComponent>(2, 0);
		  s3->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(30);

		  ents.list[5]->GetCompatibleComponent<FlagsComponent>()[0]->changeFlagStatus(0, "closed");

	  }

	  // Plot flow - 2. waiting for cannons
	  if (ents.list[5]->GetCompatibleComponent<FlagsComponent>()[0]->getFlagStatus(0) == "closed" && _cannonFreezer > 0)
		  _cannonFreezer--;

	  // Plot flow - 3. cannons appear
	  if (ents.list[5]->GetCompatibleComponent<FlagsComponent>()[0]->getFlagStatus(0) == "closed" && _cannonFreezer == 0) {

		  if (!ents.find("cannon")[0]->isVisible())
			  ents.find("cannon")[0]->setPosition(Vector2f(2400.f, 0.f));
		  ents.find("cannon")[0]->setVisible(true);

		  if (!ents.find("cannon")[1]->isVisible())
			  ents.find("cannon")[1]->setPosition(Vector2f(-1050.f, 0.f));
		  ents.find("cannon")[1]->setVisible(true);
	  }

	  // Plot flow - 4. cannons movement
	  Vector2f cannon01Pos = ents.find("cannon")[0]->getPosition();
	  if (cannon01Pos.x > 160) {
		  cannon01Pos.x -= 1;
		  ents.find("cannon")[0]->setPosition(cannon01Pos);
	  }
	  Vector2f cannon02Pos = ents.find("cannon")[1]->getPosition();
	  if (cannon02Pos.x <1200) {
		  cannon02Pos.x += 1;
		  ents.find("cannon")[1]->setPosition(cannon02Pos);
	  }

	  if (cannon01Pos.x == 160 && _enemiesAttackFreezer == -999)
		  _enemiesAttackFreezer = 500;

	  if (_enemiesAttackFreezer > 0)
		  _enemiesAttackFreezer--;

	  // Plot flow - 5. second bunch of enemies
	  if (_enemiesAttackFreezer == 0) {

		  auto s1 = makeEntity();
		  s1->addComponent<EnemyComponent>(0, 0);
		  s1->setPosition(Vector2f(s1->getPosition().x + 800, s1->getPosition().y));
		  s1->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();
		  s1->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(0);

		  auto s2 = makeEntity();
		  s2->addComponent<EnemyComponent>(1, 0);
		  s1->setPosition(Vector2f(s1->getPosition().x + 700, s1->getPosition().y));
		  s2->GetCompatibleComponent<SpriteComponent>()[0]->changeDirection();

		  auto s3 = makeEntity();
		  s3->addComponent<EnemyComponent>(2, 0);
		  s3->GetCompatibleComponent<EnemyAIComponent>()[0]->setSpeed(30);

		  _enemiesAttackFreezer = -1;
	  }

	  // Plot flow - 6. epilogue
	  if (_enemiesAttackFreezer == -1 && ents.find("enemy").size() == 0)
		  Engine::ChangeScene((Scene*)&epilogue);

	  Scene::Update(dt);
  }
}

void LevelSceneFinal::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}

