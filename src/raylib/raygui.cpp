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

    textBox = {80, 100, 930, 420};
   
}



// Wrap text to fit within the text box width
// Returns a vector of strings, each representing a line
std::vector<std::string> GameManager::WrapText(const std::string& text, float fontSize) {
    std::vector<std::string> wrappedLines;
    std::istringstream stream(text);
    std::string line;

    while (std::getline(stream, line)) {

        if (line.empty()) {
            // preserve an empty line if paragraph gap is intended
            wrappedLines.push_back("");
            continue;
        }

        // Process each word in the line
        std::string currentLine;
        std::istringstream wordStream(line);
        std::string word;

        // Build lines word by word
        while (wordStream >> word) {
            std::string testLine = currentLine.empty() ? word : currentLine + " " + word;
            float width = MeasureTextEx(font, testLine.c_str(), fontSize, 2).x;

            // If the test line fits, update current line
            if (width <= textBox.width) {
                currentLine = testLine;
            } else { // Otherwise, push current line and start a new one
                if (!currentLine.empty()) wrappedLines.push_back(currentLine);
                currentLine = word;
            }
        }

        // Push any remaining text in current line
        if (!currentLine.empty()) wrappedLines.push_back(currentLine);
    }

    return wrappedLines;
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

            // Handles text rendering with scrolling
            std::vector<std::string> lines = WrapText(room->description, 25);
            float yOffset = textBox.y + textScrollY;
            float lineHeight = 30.0f;

            BeginScissorMode(textBox.x, textBox.y, textBox.width, textBox.height);
            for (const std::string& line : lines) {
                if (yOffset + lineHeight < textBox.y) { yOffset += lineHeight; continue; }
                if (yOffset > textBox.y + textBox.height) break;
                DrawTextEx(font, line.c_str(), {textBox.x, yOffset}, 25, 2, BLACK);
                yOffset += lineHeight;
            }
            EndScissorMode();
            //--------------------------------------

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
                    currentRoom = 0; // reset to first room
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

            // ------- TEXT SCROLLING -------
            std::vector<std::string> lines = WrapText(room->description, 25);
            float lineHeight = 30.0f;
            float textHeight = lines.size() * lineHeight;

            // SCROLL WITH MOUSE WHEEL
            float mouseWheel = GetMouseWheelMove();
            if (mouseWheel != 0.0f) {
                textScrollY += mouseWheel * scrollSpeed;   // Multiply for speed
            }

            // SCROLL WITH KEYBOARD
            if (IsKeyDown(KEY_DOWN)) textScrollY -= 5.0f; // move text up
            if (IsKeyDown(KEY_UP)) textScrollY += 5.0f;   // move text down

            // Clamp scrolling
            if (textHeight > textBox.height) {
                if (textScrollY < textBox.height - textHeight) textScrollY = textBox.height - textHeight;
                if (textScrollY > 0) textScrollY = 0;
            } else {
                textScrollY = 0; // no scrolling needed
            }
        
            // -------- PROCESS GAMEPLAY OPTIONS --------
            ButtonManager::GameOption opt = buttons.checkGameInput();
            
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
                
                case ButtonManager::EndScreenOption::MENU:
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

    std::ifstream file(filename);

    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
    
        std::stringstream ss(line);
        Room r;
        std::string descPath;
        ss >> r.index >> r.name >> descPath >> r.option1 >> r.option2;
        
        // Load rooms description from file
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
