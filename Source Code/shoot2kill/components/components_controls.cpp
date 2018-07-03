#include "components_controls.h"
#include <fstream>
#include <string>
#include <SFML/Window/Keyboard.hpp>

using namespace std;
using namespace sf;

Keyboard::Key keyLeft;
Keyboard::Key keyRight;
Keyboard::Key keyUp;
Keyboard::Key keyShoot;

void Controls::SetDefaultControls() {

	keyLeft = Keyboard::Left;
	keyRight = Keyboard::Right;
	keyUp = Keyboard::Up;
	keyShoot = Keyboard::LControl;
}

void Controls::UploadSavedControls() {

	int acc = 0;
	string line;
	ifstream myfile("config.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line) && acc <= 3)
		{
			if (acc == 0) {

				stringstream geek(line);
				int x;
				geek >> x;
				keyLeft = Keyboard::Key(x);
			}
			else if (acc == 1) {

				stringstream geek(line);
				int x;
				geek >> x;
				keyRight = Keyboard::Key(x);
			}
			else if (acc == 2) {

				stringstream geek(line);
				int x;
				geek >> x;
				keyUp = Keyboard::Key(x);
			}
			else if (acc == 3) {

				stringstream geek(line);
				int x;
				geek >> x;
				keyShoot = Keyboard::Key(x);
			}
			acc++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
};

void Controls::SaveControls() {

	ofstream myfile("config.txt");
	if (myfile.is_open())
	{
		myfile << keyLeft << endl;
		myfile << keyRight << endl;
		myfile << keyUp << endl;
		myfile << keyShoot << endl;
		myfile.close();
	}
	else cout << "Unable to open file";
};
