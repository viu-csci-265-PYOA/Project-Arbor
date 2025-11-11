#include "raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "raygui.h"


int main() {
    // Initialize window
    InitWindow(800, 600, "Raylib Button Example");
    InitAudioDevice();
    SetTargetFPS(60);

    Texture2D background = LoadTexture("resource/gamescreen.png");
    Texture2D title = LoadTexture("resource/title.png");
    Texture2D gameover = LoadTexture("resource/badending.png");
    Texture2D goodending = LoadTexture("resource/goodending.png");

    Music Soundtrack = LoadMusicStream("resource/soundtrack.mp3");
    PlayMusicStream(Soundtrack);

    
    int scene = 1; // Track current scene

    while (!WindowShouldClose()) {
        UpdateMusicStream(Soundtrack);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //title screen, welcome to project arbor
        if (scene == 1) {
            DrawTexture(title, 0, 0, WHITE);

            // Button: Start Game
            if (GuiButton((Rectangle){200, 400, 100, 50}, "Start Game")) {
                scene = 2; // Switch to next scene
            }
            // Button: Exit Game
            if (GuiButton((Rectangle){500, 400, 100, 50}, "Exit")) {
                break; // Close screen
            }
        


        } else if (scene == 2) {
            // Scene 2: Game screen 1, first option
            DrawTexture(background, 0, 0, WHITE);

            // Two options for the player
            if (GuiButton((Rectangle){200, 400, 100, 50}, "Option 1.")) {
                scene = 3; // go next scene, good ending
            }
            if (GuiButton((Rectangle){500, 400, 100, 50}, "Option 2.")) {
                 scene = 4; // go to next scene, bad ending
            }

        // Decision from Game screen 1.
        } else if (scene == 3) {

            // Scene 4: Good Ending
            DrawTexture(goodending, 0, 0, WHITE);
            if (GuiButton((Rectangle){350, 400, 100, 50}, "Exit")) {
                break; // Close screen
            }

        } else if (scene == 4) {
            // Scene 3: Bad Ending
            DrawTexture(gameover, 0, 0, WHITE);
            if (GuiButton((Rectangle){350, 400, 100, 50}, "Exit")) {
                break; // Close screen
            }
        }


        EndDrawing();
    }
    StopMusicStream(Soundtrack);
    UnloadMusicStream(Soundtrack);
    CloseAudioDevice();

    UnloadTexture(background);
    UnloadTexture(title);
    UnloadTexture(gameover);    
    UnloadTexture(goodending);
    CloseWindow();
    return 0;
}