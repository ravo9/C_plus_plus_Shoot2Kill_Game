#include "scene_menu_about.h"
#include "../components/cmp_background.h"
#include "../components/cmp_menu_pointer.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void MenuAboutScene::Load() {

  // Click freezer
  _clickFreezer = 150;

   // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/menu_about_background.png");
  }

  /*// Pointer
  {
	  auto pointer = makeEntity();
	  auto p1 = pointer->addComponent<MenuPointerComponent>();
	  p1->addPosition(Vector2f(880.f, 565.f));
  }*/

  setLoaded(true);
}

void MenuAboutScene::Update(const double& dt) {

	if (_clickFreezer == 0) {

		if (sf::Keyboard::isKeyPressed(Keyboard::Return)) {
			_clickFreezer = 150;
			Engine::ChangeScene(&menu);
		}
	}
	else if (_clickFreezer > 0)
		_clickFreezer--;

	Scene::Update(dt);
}
