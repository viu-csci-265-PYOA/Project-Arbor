
#include "../../include/rayGameManager.h"

#define RAYGUI_IMPLEMENTATION

#include "../../include/raygui.h"

int main() {

    // Initialize window
    const int screenWidth = 1200;
    const int screenHeight = 675;
    InitWindow(screenWidth, screenHeight, "Arbor");
    SetTargetFPS(60);

    // Create GameManager
    GameManager game;

    // Load textures
    game.menuBg = LoadTexture("resource/mainMenu.png");
    game.gameplayScreen = LoadTexture("resource/gameplayScreen.png");
    game.endScreen = LoadTexture("resource/endScreen.png");

    // Load font
    game.font = LoadFont("resource/Alice.ttf");

    // Load rooms from text file
    game.LoadRoomsFromFile("resource/narrative/room_dir.txt");


    // -------- MAIN GAME LOOP --------
    while (!WindowShouldClose()) {
        // Update game state based on input
        game.Update();

        // Draw everything
        game.Draw();
    }

    
    // Unload textures
    UnloadTexture(game.menuBg);
    UnloadTexture(game.gameplayScreen);
    UnloadTexture(game.endScreen);

    // Unload font
    UnloadFont(game.font);

    CloseWindow();
    return 0;
}