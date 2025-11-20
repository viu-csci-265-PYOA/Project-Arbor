#include "../include/room.hpp"
#include "../include/action.hpp"

Action* Room::pause; //declaring static member variable

void Room::print_desc() const {std::cout << room_description << '\n';} 

//loops through the room's vector of actions and prints them, formatted nicely
void Room::print_options() const {
    for (int i = 0; i < options.size(); i++)
    {
        std::cout << i+1 << ". " << options[i]->get_name() << '\n';
    }
}

//function to perform all of a room's logic.
//Checks if there exist any actions in the rooms options vector.
//Prints "dead end" if the room has no further options. 
//This is a placeholder message to make clear what is happening in runtime.
void Room::enter() {
    char input;
    print_desc();

    if(options.size() > 0) { // check if options is empty
        print_options();
        input = helper::option_input();
        if(helper::input_is_digit(input)) { //input validation check
            helper::choose_option(input, options);
        }
        if(input == 'p') {pause->run_action();}
    }
    //if options is empty check for pause input
    else if(options.size() == 0) {
        std::cout << "dead end" << '\n';
        input = helper::option_input();
        if(input == 'p') {pause->run_action();}
    }
}

std::string Room::get_desc() const {return room_description;}

std::string Room::get_name() const{return room_name;}

//Adds an action to the back of the options vector.
//Emplace_back creates a copy of the object being emplaced, (i think)
//so is apparently better for complex data types like Action(?).
void Room::add_action(Action* new_action) {
    options.emplace_back(new_action);
}
