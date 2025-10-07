#include <room.hpp>
#include <action.hpp>

#include <iostream>
#include <vector>
#include <string>

Room::Room() : options(), room_description(), room_name() {}

Room::Room(const std::string name, const std::string desc) : room_name(name), room_description(desc) {}

Room::~Room() {}

void Room::print_desc() const {std::cout << room_description << '\n';} 

void Room::print_options() const {
    for (int i = 0; i < options.size(); i++)
    {
        std::cout << i+1 << ". " << options[i].get_name() << '\n';
    }
}



std::string Room::get_desc() const {return room_description;}

std::string Room::get_name() const{return room_name;}