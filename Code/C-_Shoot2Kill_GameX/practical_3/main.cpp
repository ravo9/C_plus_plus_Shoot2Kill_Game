#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream> 
#include "Entity.h"
#include "Player.h"
#include "levelsystem.h"

using  namespace  sf;
using  namespace  std;

Player* player;

void  Load() {

	player = new Player();

	ls::loadLevelFile("res/maze_2.txt");

}

void  Update(RenderWindow &window) {
	//  Reset  clock , recalculate  deltatime
	static  Clock  clock;
	float  dt = clock.restart ().asSeconds ();

	//  check  and  consume  events
	Event  event;

	while (window.pollEvent(event)) {
		if (event.type ==  Event:: Closed) {
			window.close();
			return;
		}
	}

	// Quit  Via  ESC  Key
	if (Keyboard :: isKeyPressed(Keyboard :: Escape)) {
		window.close ();
	}

	// Player update
	player->update(dt);

}

void  Render(RenderWindow &window) {

	player->render(window);
	//window.draw(*player);
	ls::render(window);
}

int  main() {
	RenderWindow  window(VideoMode(800, 600), "Maze Game");

	Load();

	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	
	return  0;
}