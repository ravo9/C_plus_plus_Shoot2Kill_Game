// What is invader, what is sprite here? 21 and 22
// What is the difference between 2 and 3 option in "3.3.1 Runtime Resources Done Right"?

#include  <SFML/Graphics.hpp>
#include <string> 
#include <iostream> 
#include "Ship.h"
#include "bullet.h"
#include "game.h"

using  namespace  sf;
using  namespace  std;

Texture spritesheet;
vector <Ship *> ships;
//vector <Bullet *> bullets;
Ship* player;

void  Load() {

	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << endl;
	}

	for (int r = 0; r < invaders_rows; ++r) {
		auto rect = IntRect(0, 0, 32, 32);

		for (int c = 0; c < invaders_columns; ++c) {
			Vector2f position = { 100 + 50 * float(c), 100 + 20 * float(r)};
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
		}
	}

	/*for (int i = 0; i < 255; ++i) {
		auto bul = new Bullet({ -100, -100 }, 1);
		Bullet::bullets.add(bul);
	}*/

	player = new Player();

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

	// Ships update
	for (auto &s : ships) {
		// Arrow as we want to call a function inside of this object.
		s->Update(dt);
	}

	// Player update
	player->Update(dt);

}

void  Render(RenderWindow &window) {
	// Why is there 'const'?
	for (const auto s : ships) {
		// Star as we want to send this to drawing function.
		window.draw(*s);
	}

	/*for (const auto b : bullets) {
		window.draw(*b);
	}*/

	window.draw(*player);

	
}

int  main() {
	RenderWindow  window(VideoMode(gameWidth, gameHeight), "INVADER");

	Load();

	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	
	return  0;
}