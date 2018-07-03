#include "scene_text2.h"
#include "../game.h"
#include "../components/cmp_sprite.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

static shared_ptr<Entity> background;
static Texture background_texture;
static int acc;
static int delay;
static shared_ptr<SpriteComponent> b1;

void Text2Scene::Load() {
  cout << "Text Scene 02 Load \n";
  
  acc = 0;
  delay = 500;

  // Background
  {
	  background = makeEntity();
	  background->setPosition(Vector2f(0, 0));
	  if (!background_texture.loadFromFile("res/img/textBackground_02_01.png"))
		  cerr << "Failed to load spritesheet!" << endl;
	  else
		  cout << "Texture loaded!";
	  b1 = background->addComponent<SpriteComponent>();
	  b1->getSprite().setTexture(background_texture);
	  b1->getSprite().setTextureRect(IntRect(0, 0, 1366, 768));
  }

  setLoaded(true);
}

void Text2Scene::Update(const double& dt) {

  delay--;

  if ((delay < 0) && (sf::Keyboard::isKeyPressed(Keyboard::Return) || sf::Keyboard::isKeyPressed(Keyboard::Space))) {

	  acc++;
	  delay = 500;
  }

  if (acc == 1) {

	  if (!background_texture.loadFromFile("res/img/textBackground_02_02.png"))
		  cerr << "Failed to load spritesheet!" << endl;
	  else
		  cout << "Texture loaded!";

	  b1->getSprite().setTexture(background_texture);
	  acc++;

	  cout << "DT: " << dt << endl;
  }

  if (acc == 3) {

	  if (!background_texture.loadFromFile("res/img/textBackground_02_03.png"))
		  cerr << "Failed to load spritesheet!" << endl;
	  else
		  cout << "Texture loaded!";

	  b1->getSprite().setTexture(background_texture);
	  acc++;
  }

  if (acc == 5)
	  Engine::ChangeScene(&menu);

  Scene::Update(dt);
}
