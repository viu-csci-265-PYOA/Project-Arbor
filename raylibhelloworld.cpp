#include "raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "raygui.h"


int main() {

    // Initialize window
    InitWindow(1200, 675, "Raylib Button Example");
    InitAudioDevice();
    SetTargetFPS(60);

    // Load resources
    Texture2D gameplayScreen = LoadTexture("resource/gameplayScreen.png");
    Texture2D mainMenu = LoadTexture("resource/mainMenu.png");

    Music Soundtrack = LoadMusicStream("resource/soundtrack.mp3");
    PlayMusicStream(Soundtrack);

    // Menu Screen Buttons
    Rectangle menuStartGame = {140, 523, 260, 58};
    Rectangle menuContinueQuest = {470, 523, 260, 58};
    Rectangle menuExitGame = {800, 523, 260, 58};

    // Game Screen Buttons
    Rectangle option1 = {72, 514, 260, 58};
    Rectangle option2 = {705, 514, 260, 58};   
    Rectangle menuButton = {70, 32, 289, 85}; 
    
    int scene = 1; // Track current scene

    while (!WindowShouldClose()) {

        Vector2 mousePoint = GetMousePosition();

        UpdateMusicStream(Soundtrack);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //title screen, welcome to project arbor
        if (scene == 1) {
            DrawTexture(mainMenu, 0, 0, WHITE);

            // Button: Start Game
            if (CheckCollisionPointRec(mousePoint, menuStartGame)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    scene = 2; // go to next scene
                }
            }

            // Button: Continue Quest
            if (CheckCollisionPointRec(mousePoint, menuContinueQuest)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    scene = 2; // continue save eventually
                }
            }

            // Button: Exit Game
            if (CheckCollisionPointRec(mousePoint, menuExitGame)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    break; // exit game
                }
            }
        


        } else if (scene == 2) {
            // Scene 2: Game screen 1, first option
            DrawTexture(gameplayScreen, 0, 0, WHITE);

            // Two options for the player
            // First option button
            if (CheckCollisionPointRec(mousePoint, option1)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    scene = 1; // go to next scene, good ending
                }
            }

            // Second option button
            if (CheckCollisionPointRec(mousePoint, option2)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    scene = 1; // go to next scene, bad ending
                }   
            }

            if (CheckCollisionPointRec(mousePoint, menuButton)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    scene = 1; // go back to main menu
                }
            }
        }
        EndDrawing();
    }
    StopMusicStream(Soundtrack);
    UnloadMusicStream(Soundtrack);
    CloseAudioDevice();

    UnloadTexture(mainMenu);
    UnloadTexture(gameplayScreen);
    CloseWindow();
    return 0;
}