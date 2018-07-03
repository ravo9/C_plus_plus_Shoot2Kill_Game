#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "scenes/scene_text1.h"
#include "scenes/scene_text2.h"
#include "scenes/scene_level1.h"
#include "scenes/scene_level2.h"
#include "scenes/scene_level3.h"
#include "scenes/scene_level4.h"
#include "scenes/scene_level5.h"
#include "scenes/scene_level_final.h"
#include "scenes/scene_menu.h"
#include "scenes/scene_menu_about.h"
#include "scenes/scene_menu_options.h"

extern MenuScene menu;
extern MenuAboutScene menuAbout;
extern MenuOptionsScene menuOptions;
extern Text1Scene intro1;
extern Text2Scene epilogue;
extern Level1Scene level1;
extern Level2Scene level2;
extern Level3Scene level3;
extern Level4Scene level4;
extern Level5Scene level5;
extern LevelSceneFinal finalLevel;


