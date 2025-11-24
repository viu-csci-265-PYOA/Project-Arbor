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
    int room_id;
    std::string room_name;
    std::string room_description;
    int option1;
    int option2;
    std::vector<Action*> options;

    void print_options() const;
    char option_input();
    void choose_option(char choice);
    void print_desc() const;
public:
    Room(int id, std::string name, std::string desc, int opt1, int opt2) 
        : room_id(id), 
          room_name(name), 
          room_description(desc), 
          option1(opt1), 
          option2(opt2) {}
    
    ~Room() {};

    void enter();

    //these are currently unused, but could be useful.
    int get_id() const;
    std::string get_name() const;
    std::string get_desc() const;
    int get_opt(int choice) const;

    void add_action(Action* new_action);
    
    //Creates a room given a room ID and returns the pointer to the room object.
    friend class RoomInfo;
    
};

#endif
