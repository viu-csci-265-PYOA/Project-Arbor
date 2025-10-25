#include "room.hpp"


void Room::print_desc() const {std::cout << room_description << '\n';} 

void Room::print_options() const {
    for (int i = 0; i < options.size(); i++)
    {
        std::cout << i+1 << ". " << options[i]->get_name() << '\n';
    }
}

char Room::option_input() {
    char input;
    std::cin >> input;
    std::cin.sync();
}

void Room::choose_option(char choice) {
    int i_choice = choice - '0';
    if(options.size() < 0 && i_choice - 1 <= 0) {
        options[i_choice]->run_action();
    }
}

void Room::enter() {
    print_desc();
    if(options.size() < 0) {
        print_options();
        choose_option(option_input());
    }
}

std::string Room::get_desc() const {return room_description;}

std::string Room::get_name() const{return room_name;}

void Room::add_action(Action* new_action) {
    options.emplace_back(new_action);
}