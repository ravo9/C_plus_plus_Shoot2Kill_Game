#include "scene.h"
#include "system_renderer.h"
#include <string> 
#include <SFML/Graphics.hpp>
#include <iostream>

using  namespace  sf;
using  namespace  std;

void Scene::update(double dt) {


	_ents->update(dt);

	//  check  and  consume  events
	Event  event;

	while (Renderer::getWindow().pollEvent(event)) {
		if (event.type == Event::Closed) {
			Renderer::getWindow().close();
			return;
		}
	}

	// Quit  Via  ESC  Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		Renderer::getWindow().close();
	}

}

void Scene::render() {}

std::vector<Entity*> &Scene::getEnts() {
	return _ents->list;
}