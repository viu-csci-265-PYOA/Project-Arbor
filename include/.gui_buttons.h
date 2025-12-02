#ifndef BUTTONS_H
#define BUTTONS_H
#include "raylib.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

enum GameState {MENU, GAMEPLAY, OPTIONS, END};


struct Room {
    int index;
    std::string name;
    std::string descPath;
    std::string description;
    int option1;
    int option2;
};

class GameManager {
    private:
    GameState currentState;
    int currentRoom;

    RoomManager rooms;
    ButtonManager buttons;
    Font font;

    // Textures for different screens
    Texture2D menuBg;
    Texture2D gameplayScreen;
    Texture2D endScreen;
    //Texture2D nextScreen;

    public: 
    GameManager();

    void Update();
    void Draw();

    GameState getCurrentState() const { return currentState;}
    int GetRoomNo() const { return currentRoom; }

    void SetState(GameState state) { currentState = state; }
    void GoToRoom(int roomNo) { currentRoom = roomNo; }

    void CheckMenuButton();

    void LoadRoomsFromFile(const std::string& filename);
    Room& GetCurrentRoom();


};

class RoomManager {
private:
    std::vector<Room> rooms;
    std::vector<Texture2D> textures;

public:
    bool loadRooms(const std::string& filePath);
    const Room* getRoom(int index) const;
    Texture2D getRoomTexture(int index) const;
    ~RoomManager();
};


class ButtonManager {
private:
   // Buttons
    // Menu Screen Buttons
    Rectangle menuStartGame = {140, 523, 260, 58};
    Rectangle menuContinueQuest = {470, 523, 260, 58};
    Rectangle menuExitGame = {800, 523, 260, 58};;
    Rectangle endGameExit {481, 543, 222, 50};;

    
    // Gameplay Screen Buttons
    
    Rectangle option1Button = {71, 553, 424, 76};
    Rectangle option2Button = {705, 553, 424, 76};
    Rectangle menuButton = {70, 32, 220, 55};

    //nextButton = {908, 583, 222, 50};

    // Pause Screen Buttons
    //pauseResume = {346, 547, 222, 50};
    //pauseExit = {636, 547, 222, 50};

public:
    
    enum class GameOption { NONE, OPTION_A, OPTION_B, BACK};

    enum class MenuOption {NONE, START, CONTINUE, EXIT};
    

    MenuOption checkMenuInput() {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mouse, menuStartGame)) {
                return MenuOption::START;
            } else if (CheckCollisionPointRec(mouse, menuContinueQuest)) {
                return MenuOption::CONTINUE;
            } else if (CheckCollisionPointRec(mouse, menuExitGame)) {
                return MenuOption::EXIT;
            } else if (CheckCollisionPointRec(mouse, endGameExit)) {
                return MenuOption::EXIT;
            } 
        }
        return MenuOption::NONE;
    }
    
    GameOption checkGameInput() {
        Vector2 mousePoint = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, option1Button)) {
                return GameOption::OPTION_A;
            } else if (CheckCollisionPointRec(mousePoint, option2Button)) {
                return GameOption::OPTION_B;
            } else if (CheckCollisionPointRec(mousePoint, menuButton)) {
                return GameOption::BACK; // Menu button pressed
            }
        }
        return GameOption::NONE;
    }
};

#endif