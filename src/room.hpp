#ifndef ARBOR_SRC_ROOM_H
#define ARBOR_SRC_ROOM_H

#include "action.hpp"

#include <vector>
#include <iostream>
#include <string>

class Action;

//room class, holds a vector of actions to be presented to the player
//the public enter() function runs all of the relevant logic.
class Room
{
private:
    std::vector<Action*> options;
    std::string room_name;
    std::string room_description;

    void print_options() const;
    char option_input();
    void choose_option(char choice);
    void print_desc() const;
public:
    Room(std::string name, std::string desc) 
        : room_name(name), room_description(desc) {}
    ~Room() {};

    void enter();

    //these are currently unused, but could be useful.
    std::string get_name() const;
    std::string get_desc() const;

    void add_action(Action* new_action);
    
    
};

#endif
