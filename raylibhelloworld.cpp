#include "raylib.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define RAYGUI_IMPLEMENTATION

#include "raygui.h"

// Function to load text scenes from a file
// Super rough and need a real solution for larger scale 
std::vector<std::string> loadTextScenes(const std::string& filename) {
    
    std::ifstream file(filename);
    std::vector<std::string> scenes;
    std::stringstream temp;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            scenes.push_back(temp.str());
            temp.str("");
            temp.clear();
        } else {
            temp << line << "\n";
        }
    }
    if (!temp.str().empty()) {
        scenes.push_back(temp.str());
    }

    return scenes;
}

// ---------
// MAIN
// ---------
int main() {

    // Initialize window
    InitWindow(1200, 675, "Raylib Button Example");
    SetTargetFPS(60);

    // Load text scenes
    std::vector<std::string> scenes = loadTextScenes("resource/scenes.txt");
    int currentScene = 0;

    // Load resources
    Texture2D gameplayScreen = LoadTexture("resource/gameplayScreen.png");
    Texture2D mainMenu = LoadTexture("resource/mainMenu.png");
    Texture2D endScreen = LoadTexture("resource/endScreen.png");
    Texture2D pauseMenu = LoadTexture("resource/pauseMenu.png");

    // Menu Screen Buttons
    Rectangle menuStartGame = {140, 523, 260, 58};
    Rectangle menuContinueQuest = {470, 523, 260, 58};
    Rectangle menuExitGame = {800, 523, 260, 58};
    Rectangle endGameExit = {481, 543, 222, 50};

    //Pause Screen Buttons
    Rectangle pauseResume = {346, 547, 222, 50};
    Rectangle pauseExit = {636, 547, 222, 50};

    // Game Screen Buttons
    Rectangle option1 = {72, 514, 423, 75};
    Rectangle option2 = {705, 514, 423, 75};   
    Rectangle menuButton = {70, 32, 220, 55}; 

    // Game Screen Management
    enum Screen { MENU, PAUSE, GAMEPLAY, END };
    Screen currentScreen = MENU;

    // -----------------------------
    // ACTUAL LOOP FOR GAME WINDOW 
    // -----------------------------
    while (!WindowShouldClose()) {

        Vector2 mousePoint = GetMousePosition();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // -------------
        // MENU SCREEN
        // -------------
        if (currentScreen == MENU) {
            DrawTexture(mainMenu, 0, 0, WHITE);

            // Button: Start Game
            if (CheckCollisionPointRec(mousePoint, menuStartGame)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = GAMEPLAY; // go to next scene
                }
            }

            // Button: Continue Quest
            if (CheckCollisionPointRec(mousePoint, menuContinueQuest)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = GAMEPLAY; // continue save eventually
                }
            }

            // Button: Exit Game
            if (CheckCollisionPointRec(mousePoint, menuExitGame)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    break; // exit game
                }
            }


        // -------------
        // PAUSE SCREEN
        // -------------
        } else if (currentScreen == PAUSE) {

            DrawTexture(pauseMenu, 0, 0, WHITE);

            if (CheckCollisionPointRec(mousePoint, pauseResume)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = GAMEPLAY; // resume game
                }
            }

            if (CheckCollisionPointRec(mousePoint, pauseExit)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    break; // exit game
                }
            }


        // ------------------
        // GAMEPLAY SCREEN
        // ------------------
        } else if (currentScreen == GAMEPLAY) {
          
            // Gameplay Screen
            DrawTexture(gameplayScreen, 0, 0, WHITE);

            // Only loop until scenes are exhausted
            if (currentScene < (int)scenes.size()) {

                DrawText(scenes[currentScene].c_str(), 80, 120, 24, BLACK);

                // Two options for the player
                // First option button
                if (CheckCollisionPointRec(mousePoint, option1)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        currentScene += 2;; // go to next scene
                        currentScreen = GAMEPLAY;
                    }
                }

                // Second option button
                if (CheckCollisionPointRec(mousePoint, option2)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        currentScene += 3; // go to next scene
                        currentScreen = GAMEPLAY; 
                    }   
                }

                if (CheckCollisionPointRec(mousePoint, menuButton)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        currentScreen = PAUSE; // go to pause menu
                    }
                }

            // no more scenes left, go to end screen
            } else {
                currentScreen = END; // go to end screen
            }


        // -------------
        // END SCREEN
        // -------------
        } else if (currentScreen == END){
            // Scene 3: End Screen
            DrawTexture(endScreen, 0, 0, WHITE);

            if (CheckCollisionPointRec(mousePoint, menuButton)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = MENU; // go back to main menu
                }
            }

            if (CheckCollisionPointRec(mousePoint, endGameExit)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    break; // exit game
                }
            }

        }
        EndDrawing();
    }

    // Unload resources and close window
    UnloadTexture(pauseMenu);
    UnloadTexture(endScreen);
    UnloadTexture(mainMenu);
    UnloadTexture(gameplayScreen);
    CloseWindow();
    
    return 0;
}