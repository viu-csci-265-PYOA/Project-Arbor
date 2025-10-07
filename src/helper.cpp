#include "helper.hpp"
bool helper::check_choice_input(const char input) {
    if (input != 'a' || input != 'b' || input != 'c')
    {
        return false;
    }
    return true;
}