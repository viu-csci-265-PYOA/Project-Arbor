#pragma once
#include <raylib.h>

class ButtonManager {
public:
    // ---- BUTTONS ----
    // Menu Screen Buttons
    Rectangle menuStartGame = {140, 523, 260, 58};
    Rectangle menuContinueQuest = {470, 523, 260, 58};
    Rectangle menuExitGame = {800, 523, 260, 58};;
    Rectangle endGameExit {481, 543, 222, 50};;

    
    // Gameplay Screen Buttons
    Rectangle option1Button = {71, 553, 424, 76};
    Rectangle option2Button = {705, 553, 424, 76};
    Rectangle menuButton = {70, 32, 220, 55};

public:
    // ----- GAMEPLAY OPTIONS ----
    enum class GameOption {NONE, OPTION_A, OPTION_B, BACK};

    // ----- MENU OPTIONS ----
    enum class MenuOption {NONE, START, CONTINUE, EXIT};

    // ----- END SCREEN OPTIONS ----
    enum class EndScreenOption {MENU, NONE, EXIT};
    

    // ----- INPUT CHECK FUNCTIONS -----

    /* -- MENU SCREEN INPUT --
    * Returns which menu option was selected 
    */
    MenuOption checkMenuInput() {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mouse, menuStartGame)) {
                return MenuOption::START;
            } else if (CheckCollisionPointRec(mouse, menuContinueQuest)) {
                return MenuOption::CONTINUE;
            } else if (CheckCollisionPointRec(mouse, menuExitGame)) {
                return MenuOption::EXIT;
            } 
        }
        return MenuOption::NONE;
    }
    
    
    /* -- GAMEPLAY SCREEN INPUT --
    * Returns which gameplay option was selected 
    */
    GameOption checkGameInput() {
        Vector2 mousePoint = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, option1Button)) {
                return GameOption::OPTION_A;

            } else if (CheckCollisionPointRec(mousePoint, option2Button)) {
                return GameOption::OPTION_B;

            } else if (CheckCollisionPointRec(mousePoint, menuButton)) {
                return GameOption::BACK; 

            }
        }
        return GameOption::NONE;
    }


    /* -- END SCREEN INPUT --
    * Returns which end screen option was selected 
    */
    EndScreenOption checkEndInput() {
        Vector2 mousePoint = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, endGameExit)) {
                return EndScreenOption::EXIT; // Exit game

            } else if (CheckCollisionPointRec(mousePoint, menuButton)) {
                return EndScreenOption::MENU; // Menu button pressed

            }
        }
        return EndScreenOption::NONE;
    }

};