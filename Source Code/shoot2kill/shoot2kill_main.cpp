#include "engine.h"
#include "game.h"
#include "scenes/scene_menu.h"
#include "scenes/scene_text1.h"
#include <SFML/Window/Keyboard.hpp>
#include "components/components_controls.h"

using namespace std;
using namespace sf;

MenuScene menu;
MenuOptionsScene menuOptions;
MenuAboutScene menuAbout;
Text1Scene intro1;
Text2Scene epilogue;
Level1Scene level1;
Level2Scene level2;
Level3Scene level3;
Level4Scene level4;
Level5Scene level5;
LevelSceneFinal finalLevel;

int main() {

	Controls::SetDefaultControls();
	Controls::UploadSavedControls();

	Engine::Start(1366, 768, "Platformer",&menu);
}