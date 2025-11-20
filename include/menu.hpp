#ifndef ARBOR_INCLUDE_PAUSEMENU_H
#define ARBOR_INCLUDE_PAUSEMENU_H

#include "action.hpp"
#include "command.hpp"
#include "gamestate.hpp"
#include "helper.hpp"

#include <vector>
#include <iostream>
#include <string>

class PauseMenu {
private:
    std::vector<Action*> options;
    std::vector<Command*> cmds; //for memory cleanup
    GameState* state;
    void print() const;
public:
    PauseMenu(GameState* state);
    ~PauseMenu();

    void run();
};

#endif