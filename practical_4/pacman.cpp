#include "pacman.h"
#include "Player.h"
#include "Ghost.h"
#include "system_renderer.h"

using  namespace  sf;
using  namespace  std;

// Externs are defined here
std::shared_ptr<Scene> gameScene;
std::shared_ptr<Scene> menuScene;
std::shared_ptr<Scene> activeScene;

void MenuScene::update(double dt) {

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}
	Scene::update(dt);
}

void MenuScene::render() {
	Renderer::queue(&text);
}

void MenuScene::load() {

	_ents = new EntityManager();

	text.setString("Almost Pacman");
	text.setColor(sf::Color::Red);
	font.loadFromFile("res/fonts/RobotoMono-Regular.ttf");
	text.setFont(font);
}

void GameScene::respawn() {

}

void GameScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		activeScene = menuScene;
	}
	Scene::update(dt);
}

void GameScene::render() {

	_ents->render(Renderer::getWindow());
}

void GameScene::load() {

	_ents = new EntityManager();
	_ents->list.push_back(new Player());
	_ents->list.push_back(new Ghost());
	_ents->list.push_back(new Ghost());
}




