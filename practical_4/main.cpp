#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Ghost.h"
#include "pacman.h"
#include "scene.h"
#include "system_renderer.h"

using  namespace  sf;
using  namespace  std;

void  Load() {

	srand(time(NULL));

	// Load Scene-Local Assets
	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->load();
	menuScene->load();

	// Start ad main menu
	activeScene = menuScene;
}

void  Update(RenderWindow &window) {

	//  Reset  clock , recalculate  deltatime
	static  Clock  clock;
	float  dt = clock.restart().asSeconds ();

	// New approach
	activeScene->update(dt);
}

void  Render(RenderWindow &window) {

	// Add everything to be drawn to sprites.
	activeScene->render();
	// Draw all sprites.
	Renderer::render();
}

int  main() {
	
	RenderWindow window(VideoMode(800, 600), "Pacman Game");
	Renderer::initialise(window);
	Load();

	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	
	return  0;
}