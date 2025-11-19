#include "../include/helper.hpp"

#include <iostream>
#include <vector>

// function to check a char is a positive integer
bool helper::check_choice_input(const char input) {
    int i_input = input - '0'; // convert char to int
    if (i_input >= 0)
    {
        return true;
    }
    return false;
}

char helper::option_input() {
    char input;
    std::cin >> input;
    std::cin.sync();

    return input;
}

void helper::choose_option(char choice, std::vector<Action*> options) {
    int i_choice = choice - '0';
    if(options.size() > 0 && i_choice - 1 >= 0) {
        options[i_choice - 1]->run_action();
    }
}