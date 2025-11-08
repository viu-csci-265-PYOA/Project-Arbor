#include "room.hpp"
#include "action.hpp"


void Room::print_desc() const {std::cout << room_description << '\n';} 

//loops through the room's vector of actions and prints them, formatted nicely
void Room::print_options() const {
    for (int i = 0; i < options.size(); i++)
    {
        std::cout << i+1 << ". " << options[i]->get_name() << '\n';
    }
}

//function to take player input as a character.
//  currently uses cin.sync() to clear the input buffer
//  apparently sync() has cases where its not ideal, potentially
//  cin.ignore(numeric_limits::max(),'\n') could be better
char Room::option_input() {
    char input;
    std::cin >> input;
    std::cin.sync();

    return input;
}

//Takes the player input as a char, converts it to an int, 
//then chooses the action that corresponds to.
//The input has 1 subtracted from it, so input of 1 chooses opions[0],
//or the first option.
//Checks if there are any actions in options before running,
//but this is probably not necessary, as choose_option is only ever 
//called by enter(), which does the same check.
void Room::choose_option(char choice) {
    int i_choice = choice - '0';
    if(options.size() > 0 && i_choice - 1 >= 0) {
        options[i_choice - 1]->run_action();
    }
}

//Master function to perform all of a room's logic.
//Checks if there exist any actions in the rooms options vector.
//This is currently redundant with a check in choose_option()
//Prints "dead end" if the room has no further options. 
//This is a placeholder message to make clear what is happening in runtime.
//TODO: implement a way for a dead end room to wait for input instead of 
//looping forever.
void Room::enter() {
    print_desc();
    if(options.size() > 0) {
      print_options();
      choose_option(option_input());
    }else if(options.size() == 0) {
      std::cout << "dead end" << '\n';
    }
}

std::string Room::get_desc() const {return room_description;}

std::string Room::get_name() const{return room_name;}

//Adds an action to the back of the options vector.
//Emplace_back creates a copy of the object being emplaced, (i think)
//so is apparently better for complex data types like Action.
void Room::add_action(Action* new_action) {
    options.emplace_back(new_action);
}
