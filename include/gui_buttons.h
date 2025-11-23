#ifndef BUTTONS_H
#define BUTTONS_H
#include "raylib.h"

struct Buttons {

    // Menu Screen Buttons
    Rectangle menuStartGame;
    Rectangle menuContinueQuest;
    Rectangle menuExitGame;
    Rectangle endGameExit;

    // Gameplay Screen Buttons
    Rectangle option1Button;
    Rectangle option2Button;
    Rectangle menuButton;

    // Pause Screen Buttons
    Rectangle pauseResume;
    Rectangle pauseExit;

};

struct Textures {
    Texture2D mainMenu;
    Texture2D gameplayScreen;
    Texture2D pauseMenu;
    Texture2D endScreen;
};

Buttons InitButtons();
Textures LoadTextures();


   
#endif