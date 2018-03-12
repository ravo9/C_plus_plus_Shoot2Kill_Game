#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Enemy.h"

using  namespace  sf;
using  namespace  std;

Enemy* e1;

void  Load() {
	e1 = new Enemy();
	e1->setPosition(Vector2f(300.f, 300.f));
}

void  Update(RenderWindow &window) {

	// Reset  clock , recalculate  deltatime
	static  Clock  clock;
	float  dt = clock.restart().asSeconds();

	// Check and consume events
	Event  event;

	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	// Quit via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	// Enemies update
	e1->update(dt);
}

void  Render(RenderWindow &window) {
	e1->render(window);
}

int  main() {
	
	RenderWindow window(VideoMode(800, 600), "Shoot2Kill");
	Load();

	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	
	return  0;
}