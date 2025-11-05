#ifndef ARBOR_SRC_ROOM_H
#define ARBOR_SRC_ROOM_H

#include "action.hpp"

#include <vector>
#include <iostream>
#include <string>

class Action;

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

    std::string get_name() const;
    std::string get_desc() const;

    void add_action(Action* new_action);
    
    
};

#endif
