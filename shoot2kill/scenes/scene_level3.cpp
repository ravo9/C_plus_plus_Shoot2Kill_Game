#include "scene_level3.h"
#include "../components/cmp_physics.h"
#include "../components/cmp_player_physics.h"
#include "../game.h"
#include "../components/cmp_bullet.h"
#include <LevelSystem.h>
#include <iostream>
using namespace std;
using namespace sf;

static shared_ptr<Entity> player;
static shared_ptr<Entity> background;
static Texture background_texture;
static Texture spritesheet;

void Level3Scene::Load() {
  cout << "Scene 3 Load" << endl;
  ls::loadLevelFile("res/level_3.txt", 40.0f);
  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));


  // Background
  {
	  background = makeEntity();
	  background->setPosition(Vector2f(0, 0));
	  if (!background_texture.loadFromFile("res/img/lvl03_background.png"))
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
  player.reset();
  ls::unload();
  Scene::UnLoad();
}


void Level3Scene::Update(const double& dt) {
  Scene::Update(dt);
  const auto pp = player->getPosition();
  if (ls::getTileAt(pp) == ls::END) {
    Engine::ChangeScene((Scene*)&level1);
  } else if (!player->isAlive()) {
    Engine::ChangeScene((Scene*)&level3);
  }
  
}

void Level3Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
