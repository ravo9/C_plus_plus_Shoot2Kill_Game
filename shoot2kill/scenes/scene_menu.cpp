#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void MenuScene::Load() {
  cout << "Menu Load \n";
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>("\n\n\n\n			Shoot2Kill\n\n\n\n\n			Press Enter to start the game! \n\n\n\n\n\n\n\n\n\n			Ozog & Szumlanski Games Development 2018 ");
  }
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

  if (sf::Keyboard::isKeyPressed(Keyboard::Return)) {
    Engine::ChangeScene(&level1);
  }

  Scene::Update(dt);
}
