#ifndef ARBOR_INCLUDE_PAUSEMENU_H
#define ARBOR_INCLUDE_PAUSEMENU_H

#include "action.hpp"

#include <vector>
#include <iostream>
#include <string>

class PauseMenu {
private:
    std::vector<Action> options;
public:
    void print() const;
    
};

#endif