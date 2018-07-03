
#include <ecm.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
//#include "game.h"

extern sf::Keyboard::Key keyLeft;
extern sf::Keyboard::Key keyRight;
extern sf::Keyboard::Key keyUp;
extern sf::Keyboard::Key keyShoot;

class Controls {
public:
	static void SetDefaultControls();
	static void UploadSavedControls();
	static void SaveControls();
};