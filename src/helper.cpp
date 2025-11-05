#include "helper.hpp"

//was initially going to prompt the user for a, b, or c inputs.
//decided to go with numbered options
//TODO: refactor this to check for valid integer inputs.
bool helper::check_choice_input(const char input) {
    if (input != 'a' || input != 'b' || input != 'c')
    {
        return false;
    }
    return true;
}