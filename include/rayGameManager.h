#pragma once
#include <raylib.h>
#include "RoomManager.h"
#include "ButtonsManager.h"

// GAME STATES
enum GameState {MENU, GAMEPLAY, OPTIONS, END};

struct TextBox {
    float x, y, width, height;
};

// Game Manager Class
// Manages game state, rooms, buttons, and rendering
class GameManager {

    private:
    GameState currentState;
    int currentRoom;

    RoomManager rooms;
    ButtonManager buttons;

    float textScrollY = 0.0f;   // Scroll offset for manual scrolling
    float scrollSpeed = 15.0f;   // Speed of scrolling
   
    // Text box for displaying room descriptions
    TextBox textBox;

    public: 
    Font font;

    // Utility function to wrap text into lines based on a given size
    std::vector<std::string> WrapText(const std::string& text, float fontSize);

    // Textures for different screens
    Texture2D menuBg;
    Texture2D gameplayScreen;
    Texture2D endScreen;


    public: 
    GameManager();

    void Update(); // Update game state based on input
    void Draw(); // Render current game state


    GameState getCurrentState() const { return currentState;} // Get current game state

    int GetRoomNo() const { return currentRoom; } // Get current room index

    void SetState(GameState state) { currentState = state; } // Set current game state

    void GoToRoom(int roomNo) { currentRoom = roomNo; } // Go to specific room

    void LoadRoomsFromFile(const std::string& filename); // Load rooms from a file

    Room& GetCurrentRoom(); // Get the current room object


};

