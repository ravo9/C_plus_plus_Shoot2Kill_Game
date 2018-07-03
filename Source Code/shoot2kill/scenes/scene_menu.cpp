#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_background.h"
#include "../components/cmp_menu_pointer.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void MenuScene::Load() {
  cout << "Menu Load \n";

  // Click freezer
  _clickFreezer = 150;

  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/menu_background.png");
  }

  // Pointer
  {
	  auto pointer = makeEntity();
	  auto p1 = pointer->addComponent<MenuPointerComponent>();
	  p1->addPosition(Vector2f(1110.f, 300.f));
	  p1->addPosition(Vector2f(1110.f, 405.f));
	  p1->addPosition(Vector2f(1110.f, 500.f));
	  p1->addPosition(Vector2f(1110.f, 595.f));
  }

  setLoaded(true);
}

void MenuScene::Update(const double& dt) {

  if (_clickFreezer == 0) {

	  _chosenValue = ents.list[1]->GetCompatibleComponent<MenuPointerComponent>()[0]->getCurrentPosition();

	  if (_chosenValue == 0 && sf::Keyboard::isKeyPressed(Keyboard::Return)) {
		  _clickFreezer = 150;
		  Engine::ChangeScene(&intro1);
	  }
	  else if (_chosenValue == 1 && sf::Keyboard::isKeyPressed(Keyboard::Return)) {
		  _clickFreezer = 150;
		  Engine::ChangeScene(&menuOptions);
	  }
	  else if (_chosenValue == 2 && sf::Keyboard::isKeyPressed(Keyboard::Return)) {
		  _clickFreezer = 150;
		  Engine::ChangeScene(&menuAbout);
	  }
	  else if (_chosenValue == 3 && sf::Keyboard::isKeyPressed(Keyboard::Return)) {
		  _clickFreezer = 150;
		  Engine::GetWindow().close();
	  }
  }
  else if (_clickFreezer > 0)
	  _clickFreezer--;

 
  Scene::Update(dt);
}
