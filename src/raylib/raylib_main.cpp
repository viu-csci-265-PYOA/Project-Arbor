
#include "../../include/raylib.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "../../include/gui_buttons.h"

#define RAYGUI_IMPLEMENTATION

#include "../../include/raygui.h"

// Function to load text scenes from a file
// Super rough and need a real solution for larger scale 
std::vector<std::string> loadTextScenes(const std::string& filename) {
    
    std::ifstream file(filename);
    std::vector<std::string> scenes;
    std::stringstream temp;
    std::string line;

    while (std::getline(file, line)) {
        if (file.eof()) {
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
    InitWindow(1200, 675, "Raylib Prototype");
    SetTargetFPS(60);

    Font myFont = LoadFont("resource/arbor_font.ttf");

    // Load text scenes
    std::vector<std::string> scenes = loadTextScenes("resource/narrative/lvl2_tavern/rm13.txt");
    int currentScene = 0;

    // Load resources
    Textures t = LoadTextures();

    // Initialize Buttons
    Buttons b = InitButtons();

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
            DrawTexture(t.mainMenu, 0, 0, WHITE);

            // Button: Start Game
            if (CheckCollisionPointRec(mousePoint, b.menuStartGame)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = GAMEPLAY; // go to next scene
                }
            }

            // Button: Continue Quest
            if (CheckCollisionPointRec(mousePoint, b.menuContinueQuest)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = GAMEPLAY; // continue save eventually
                }
            }

            // Button: Exit Game
            if (CheckCollisionPointRec(mousePoint, b.menuExitGame)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    break; // exit game
                }
            }


        // -------------
        // PAUSE SCREEN
        // -------------
        } else if (currentScreen == PAUSE) {

            DrawTexture(t.pauseMenu, 0, 0, WHITE);

            if (CheckCollisionPointRec(mousePoint, b.pauseResume)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = GAMEPLAY; // resume game
                }
            }

            if (CheckCollisionPointRec(mousePoint, b.pauseExit)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    break; // exit game
                }
            }


        // ------------------
        // GAMEPLAY SCREEN
        // ------------------
        } else if (currentScreen == GAMEPLAY) {
          
            // Gameplay Screen
            DrawTexture(t.gameplayScreen, 0, 0, WHITE);

            // Only loop until scenes are exhausted
            if (currentScene < (int)scenes.size()) {

                DrawTextEx(myFont, scenes[currentScene].c_str(), {80, 120}, 22, 2, BLACK);

                // Two options for the player
                // First option button
                if (CheckCollisionPointRec(mousePoint, b.option1Button)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        currentScene += 2;; // go to next scene
                        currentScreen = GAMEPLAY;
                    }
                }

                // Second option button
                if (CheckCollisionPointRec(mousePoint, b.option2Button)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        currentScene += 3; // go to next scene
                        currentScreen = GAMEPLAY; 
                    }   
                }

                if (CheckCollisionPointRec(mousePoint, b.menuButton)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        currentScreen = PAUSE; // go to pause menu
                    }
                }

            // no more scenes left
            } else {
                currentScreen = END; // go to end screen
            }


        // -------------
        // END SCREEN
        // -------------
        } else if (currentScreen == END){
            // Scene 3: End Screen
            DrawTexture(t.endScreen, 0, 0, WHITE);

            if (CheckCollisionPointRec(mousePoint, b.menuButton)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentScreen = MENU; // go back to main menu
                }
            }

            if (CheckCollisionPointRec(mousePoint, b.endGameExit)) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    break; // exit game
                }
            }

        }
        EndDrawing();
    }

    // Unload resources and close window
    UnloadFont(myFont);
    UnloadTexture(t.pauseMenu);
    UnloadTexture(t.endScreen);
    UnloadTexture(t.mainMenu);
    UnloadTexture(t.gameplayScreen);
    CloseWindow();
    
    return 0;
}