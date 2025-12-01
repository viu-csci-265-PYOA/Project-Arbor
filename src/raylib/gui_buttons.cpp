#include "../../include/rayGameManager.h"
#include <raylib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// GameManager Constructor
// Initializes game state, loads rooms and font
GameManager::GameManager() {
    currentState = MENU;
    currentRoom = 0;

    rooms.loadRooms("resource/room_dir.txt");

    font = LoadFont("resource/Alice.ttf");
   
}

// Draw the current game state
// Renders menu, gameplay, or end screen based on current state
void GameManager::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (currentState) {

        // -------- MENU SCREEN --------
        case GameState::MENU: {
            DrawTexture(menuBg, 0, 0, WHITE);
            break;
        }


        // -------- GAMEPLAY SCREEN --------
        case GameState::GAMEPLAY: {
            const Room* room = rooms.getRoom(currentRoom);
            if (!room) break;
            DrawTexture(gameplayScreen, 0, 0, WHITE);

            // Draw room text with manual scroll
            Vector2 textPos = {80, 105 + textScrollY};
            DrawTextEx(font, room->description.c_str(), textPos, 25, 2, BLACK);
            break;
        }

    
        // -------- END SCREEN --------
        case GameState::END: {
            DrawTexture(endScreen, 0, 0, WHITE);
            break;
        }
    }

    EndDrawing();
}


// Update the game state based on user input
// Handles menu navigation, room transitions, and text scrolling
void GameManager::Update() {

    switch (currentState) {

        // -------- MENU SCREEN INPUT --------
        case GameState::MENU: {

            ButtonManager::MenuOption opt = buttons.checkMenuInput();
            
            switch (opt) {
                case ButtonManager::MenuOption::START:
                    currentRoom = 0;
                    currentState = GAMEPLAY; 
                    break;

                case ButtonManager::MenuOption::CONTINUE:
                    currentState = GAMEPLAY; // continue from where you were
                    break;

                case ButtonManager::MenuOption::EXIT:
                    // exit game
                    CloseWindow();
                    break;

                default:
                    break;
            }
            break;
        }
        
        // -------- GAMEPLAY SCREEN INPUT --------
        case GameState::GAMEPLAY: {
            {
            const Room* room = rooms.getRoom(currentRoom);
            
            if (!room) break;

            // -----------------------
            // Handle text scrolling

            // Mouse wheel: invert direction
            float wheel = GetMouseWheelMove();
            textScrollY += wheel * scrollSpeed;

            // Keyboard scroll: invert
            if (IsKeyDown(KEY_DOWN)) textScrollY += scrollSpeed; // down moves text down
            if (IsKeyDown(KEY_UP)) textScrollY -= scrollSpeed;   // up moves text up

            // Clamp scrolling: top
            if (textScrollY > 0) textScrollY = 0;

            // Clamp scrolling: bottom
            float textHeight = MeasureTextEx(font, room->description.c_str(), 25, 2).y;
            float maxScroll = 600 - 105 - textHeight - 20;
            if (textScrollY < maxScroll) textScrollY = maxScroll;
            // -----------------------
            
            ButtonManager::GameOption opt = buttons.checkGameInput();

            // Handle gameplay options
            switch (opt) { 
                // -------- OPTION 1 --------
                case ButtonManager::GameOption::OPTION_A:
                    if (room->option1 != -1) {
                        currentRoom = room->option1;
                        textScrollY = 0.0f; // reset scroll on new room
                        
                    } else {
                        currentState = GameState::END; // go to end screen
                    }
                    
                    break;
            
                // -------- OPTION 2 --------
                case ButtonManager::GameOption::OPTION_B:
                    if (room->option2 != -1) {
                        currentRoom = room->option2;
                        textScrollY = 0.0f;
                    } else {
                        currentState = GameState::END; // go to end screen
                    }
                    
                    break;

                // -------- BACK TO MENU --------
                case ButtonManager::GameOption::BACK:
                    currentState = GameState::MENU;
                    textScrollY = 0.0f; // reset scroll on new room
                    break;

                default:
                    break;
                }
        }

        // -------- END SCREEN INPUT --------
        case GameState::END: {

            ButtonManager::EndScreenOption opt = buttons.checkEndInput();
            switch (opt) {

                case ButtonManager::EndScreenOption::BACK:
                    currentState = GameState::MENU;
                    break;

                case ButtonManager::EndScreenOption::EXIT:
                    CloseWindow(); // Exit game
                    break;

                    default:
                        break;
            }
        }}   
    }
}


// Load rooms from a file
void GameManager::LoadRoomsFromFile(const std::string& filename) {
    rooms.loadRooms(filename);
}



// Get the current room object
bool RoomManager::loadRooms(const std::string& filename) {
    // Implementation for loading rooms from a file
    std::ifstream file(filename);

    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        
        std::stringstream ss(line);
        Room r;
        std::string descPath;
        ss >> r.index >> r.name >> descPath >> r.option1 >> r.option2;
        
        std::ifstream descFile(descPath);
        r.description.clear();
            if (descFile.is_open()) {
                std::string textline;
                while (std::getline(descFile, textline)) {
                    r.description += textline + "\n";
                }
            }

            rooms.push_back(r);
        }
    return true;
}


// Get a pointer to a room by index
const Room* RoomManager::getRoom(int index) const {
    for (const Room& r : rooms) {
        if (r.index == index) return &r;
    }
    return nullptr;
}


// Get the texture for a room by index
Texture2D RoomManager::getRoomTexture(int index) const {
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].index == index) return textures[i];
    }
    return {};
}


// Destructor to unload textures
RoomManager::~RoomManager() {

    for (const Texture2D& tex : textures) {
        UnloadTexture(tex);
    }
}
