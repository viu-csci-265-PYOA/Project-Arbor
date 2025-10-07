#ifndef ARBOR_SRC_ROOM_H
#define ARBOR_SRC_ROOM_H

#include "Action.hpp"

#include <vector>
#include <iostream>
#include <string>

class Room
{
private:
    std::vector<Action> options;
    std::string room_name;
    std::string room_description;

    void print_options() const;
    char option_input();
    void choose_option(char choice);
    void print_desc() const;
public:
    Room();
    Room(const std::string name, const std::string desc);
    ~Room();

    void enter();

    std::string get_name() const;
    std::string get_desc() const;
    
    
};

#endif