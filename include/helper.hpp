#ifndef ARBOR_SRC_HELPER_H
#define ARBOR_SRC_HELPER_H

#include "action.hpp"

#include <vector>

//namespace with helper functions that can be used by multiple objects
namespace helper {
    bool input_is_digit(char input);
    char option_input();
    void choose_option(char choice, std::vector<Action*> options);
}

#endif