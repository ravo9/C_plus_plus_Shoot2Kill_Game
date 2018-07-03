#include "scene_menu_options.h"
#include "../components/cmp_background.h"
#include "../components/cmp_menu_pointer.h"
#include "../components/cmp_sprite.h"
#include "../components/components_controls.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace sf;

void MenuOptionsScene::Load() {
  
  // Click freezer
  _clickFreezer = 150;

  // Background
  {
	  auto background = makeEntity();
	  background->addComponent<BackgroundComponent>("res/img/menu_options_background.png");
  }

  // Pointer
  {
	  auto pointer = makeEntity();
	  auto p1 = pointer->addComponent<MenuPointerComponent>();
	  p1->addPosition(Vector2f(900.f, 330.f));
	  p1->addPosition(Vector2f(900.f, 365.f));
	  p1->addPosition(Vector2f(900.f, 400.f));
	  p1->addPosition(Vector2f(900.f, 435.f));
	  p1->addPosition(Vector2f(895.f, 580.f));
  }

  // Buttons
  {
	  _spritesheetBtnCustom.loadFromFile("res/img/btnCustom.png");
  }
  {
	  auto btn = makeEntity();
	  btn->setPosition(Vector2f(600.f, 340.f));
	  _spritesheetBtn1.loadFromFile("res/img/btnLeftArrow.png");
	  auto b1 = btn->addComponent<SpriteComponent>();
	  if (keyLeft == 71)
		 b1->getSprite().setTexture(_spritesheetBtn1);
	  else
		 b1->getSprite().setTexture(_spritesheetBtnCustom);
  }
  {
	  auto btn = makeEntity();
	  btn->setPosition(Vector2f(600.f, 375.f));
	  _spritesheetBtn2.loadFromFile("res/img/btnRightArrow.png");
	  auto b1 = btn->addComponent<SpriteComponent>();
	  if (keyRight == 72)
		  b1->getSprite().setTexture(_spritesheetBtn2);
	  else
		  b1->getSprite().setTexture(_spritesheetBtnCustom);
  }
  {
	  auto btn = makeEntity();
	  btn->setPosition(Vector2f(600.f, 410.f));
	  _spritesheetBtn3.loadFromFile("res/img/btnUpArrow.png");
	  auto b1 = btn->addComponent<SpriteComponent>();
	  if (keyUp == 73)
		  b1->getSprite().setTexture(_spritesheetBtn3);
	  else
		  b1->getSprite().setTexture(_spritesheetBtnCustom);
  }
  {
	  auto btn = makeEntity();
	  btn->setPosition(Vector2f(600.f, 445.f));
	  _spritesheetBtn4.loadFromFile("res/img/btnLeftCtrl.png");
	  auto b1 = btn->addComponent<SpriteComponent>();
	  if (keyShoot == 37)
		  b1->getSprite().setTexture(_spritesheetBtn4);
	  else
		  b1->getSprite().setTexture(_spritesheetBtnCustom);
  }
  
  setLoaded(true);
}

void MenuOptionsScene::Update(const double& dt) {

	if (_clickFreezer == 0) {

		_chosenValue = ents.list[1]->GetCompatibleComponent<MenuPointerComponent>()[0]->getCurrentPosition();

		if ((_chosenValue == 0 || _chosenValue == 1 || _chosenValue == 2 || _chosenValue ==3) && sf::Keyboard::isKeyPressed(Keyboard::Return)) {

			_clickFreezer = 150;
			SetKey(_chosenValue);
			ents.list[_chosenValue + 2]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheetBtnCustom);
		}
		else if (_chosenValue == 4 && sf::Keyboard::isKeyPressed(Keyboard::Return)) {
			_clickFreezer = 150;
			Engine::ChangeScene(&menu);
		}
	}
	else if (_clickFreezer > 0)
		_clickFreezer--;

	// Restore default settings.
	if (sf::Keyboard::isKeyPressed(Keyboard::F5)) {

		Controls::SetDefaultControls();

		ents.list[2]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheetBtn1);
		ents.list[3]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheetBtn2);
		ents.list[4]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheetBtn3);
		ents.list[5]->GetCompatibleComponent<SpriteComponent>()[0]->getSprite().setTexture(_spritesheetBtn4);
	}

  Scene::Update(dt);
}

void MenuOptionsScene::SetKey(int value) {

	for (char i = 32; i < 127; i++) {
		if (GetAsyncKeyState(i)) {
			if (value == 0)
				keyLeft = Keyboard::Key(i - 65);
			else if (value == 1)
				keyRight = Keyboard::Key(i - 65);
			else if (value == 2)
				keyUp = Keyboard::Key(i - 65);
			else if (value == 3)
				keyShoot = Keyboard::Key(i - 65);
			break;
		}
	}

	Controls::SaveControls();
}