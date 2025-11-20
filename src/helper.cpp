#include "../include/helper.hpp"

#include <iostream>
#include <vector>

// function to check a char is a positive integer from 0-9 (a digit)
bool helper::input_is_digit(const char input){
    if (isdigit(input))
    {
        return true;
    }
    return false;
}

//function to take player input as a char.
//  currently uses cin.sync() to clear the input buffer
//  apparently sync() has cases where its not ideal, potentially
//  cin.ignore(numeric_limits::max(),'\n') could be better
char helper::option_input() {
    char input;
    std::cin >> input;
    std::cin.sync();

    return input;
}

//Takes the player input as a char and a vector of actions,
//converts it to an int, then executes the action that corresponds to.
//The input has 1 subtracted from it, so input of 1 chooses options[0],
//or the first option.
//does not check input validity, or if options is empty or not
//so that will be done in a higher level function
void helper::choose_option(char choice, std::vector<Action*> options) {
    int i_choice = choice - '0';
    options[i_choice - 1]->run_action();
}