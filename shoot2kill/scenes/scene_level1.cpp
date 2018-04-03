#include "scene_level1.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_physics.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_player_shooting.h"
#include "../components/cmp_player_attributes.h"
#include "../components/cmp_text.h"
#include "../components/cmp_hurt_player.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

static shared_ptr<Entity> player;
static shared_ptr<Entity> enemy;
static shared_ptr<Entity> background;
static Texture background_texture;
static Texture spritesheet;
static Texture spritesheet_enemy;

// Variables used to display player information
int hp_value;
shared_ptr<PlayerAttributesComponent> sp;
shared_ptr<TextComponent> t;

void Level1Scene::Load() {
  cout << " Scene 1 Load" << endl;
  ls::loadLevelFile("res/level_1.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // Background
  {
	  background = makeEntity();
	  background->setPosition(Vector2f(0, 0));
	  if (!background_texture.loadFromFile("res/img/lvl01_background.png"))
		  cerr << "Failed to load spritesheet!" << endl;
	  else
		  cout << "Texture loaded!";
	  auto b1 = background->addComponent<SpriteComponent>();
	  b1->getSprite().setTexture(background_texture);
	  b1->getSprite().setTextureRect(IntRect(0, 0, 1366, 768));
  }

  // Create player
  {
	  player = makeEntity();
	  player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
	 
	  if (!spritesheet.loadFromFile("res/img/character_template_01.png"))
		  cerr << "Failed to load spritesheet!" << endl;
	  else
		  cout << "Texture loaded!";
	  auto s1 = player->addComponent<SpriteComponent>();
	  s1->getSprite().setTexture(spritesheet);
	  s1->getSprite().setTextureRect(IntRect(0, 0, 70, 140));
	  s1->getSprite().setOrigin(35.f, 70.f);
	 
	  player->addComponent<PlayerPhysicsComponent>(Vector2f(70.f, 140.f));
	  player->addComponent<ShootingComponent>();
	  player->addTag("player");
	  sp = player->addComponent<PlayerAttributesComponent>();
	  //player->addComponent<HurtComponent>();
  }

  // Create enemy
  {
	  enemy = makeEntity();
	  enemy->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[0]));

	  if (!spritesheet_enemy.loadFromFile("res/img/character_template_02.png"))
		  cerr << "Failed to load spritesheet!" << endl;
	  else
		  cout << "Texture loaded!";
	  auto s2 = enemy->addComponent<SpriteComponent>();
	  s2->getSprite().setTexture(spritesheet_enemy);
	  s2->getSprite().setTextureRect(IntRect(0, 0, 70, 140));
	  s2->getSprite().setOrigin(35.f, 70.f);

	  enemy->addComponent<PhysicsComponent>(true, Vector2f(70.f, 140.f));
	  enemy->addComponent<ActorMovementComponent>();
	  enemy->addComponent<EnemyAIComponent>();
	  enemy->addTag("enemy");
	 // enemy->addComponent<HurtComponentEnemy>();
	  
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

  // Add HP and weapon info display
  {
	  auto hp_text = makeEntity();
	  hp_value = sp->getHpValue();
	  t = hp_text->addComponent<TextComponent>("\n GUN: AR 15 Tactical Carabine\n HP: " + std::to_string(hp_value) + "%");
	  t->SetColor(sf::Color(36, 255, 20, 255));
  }

  //Simulate long loading times
  //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  cout << " Scene 1 Load Done" << endl;

  setLoaded(true);
}

void Level1Scene::UnLoad() {
  cout << "Scene 1 Unload" << endl;
  player.reset();
  background.reset();
  enemy.reset();
  sp.reset();
  t.reset();
  ls::unload();
  Scene::UnLoad();
}

void Level1Scene::Update(const double& dt) {

  if (ls::getTileAt(player->getPosition()) == ls::END) {
    Engine::ChangeScene((Scene*)&level2);
  }
  else {
	  Scene::Update(dt);

	  // Update HP and weapon info
	  hp_value = sp->getHpValue();
	  t->SetText("\n GUN: AR 15 Tactical Carabine\n HP: " + std::to_string(hp_value) + "%");
  }
}

void Level1Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
