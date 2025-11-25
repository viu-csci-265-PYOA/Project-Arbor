#include "../../include/raylib.h"
#include "../../include/gui_buttons.h"

Buttons InitButtons() {
    Buttons b;
    
    // Menu Screen Buttons
    b.menuStartGame = {140, 523, 260, 58};
    b.menuContinueQuest = {470, 523, 260, 58};
    b.menuExitGame = {800, 523, 260, 58};
    b.endGameExit = {481, 543, 222, 50};

    // Gameplay Screen Buttons
    b.option1Button = {71, 553, 424, 76};
    b.option2Button = {705, 553, 424, 76};
    b.menuButton = {70, 32, 220, 55};

    b.nextButton = {908, 583, 222, 50};

    // Pause Screen Buttons
    b.pauseResume = {346, 547, 222, 50};
    b.pauseExit = {636, 547, 222, 50};

    return b;
}

Textures LoadTextures() {
    Textures t;
    t.mainMenu = LoadTexture("resource/mainMenu.png");
    t.gameplayScreen = LoadTexture("resource/gameplayScreen.png");
    t.pauseMenu = LoadTexture("resource/pauseMenu.png");
    t.nextScreen = LoadTexture("resource/nextScreen.png");
    t.endScreen = LoadTexture("resource/endScreen.png");
    return t;
}

