#ifndef ARBOR_SRC_HELPER_H
#define ARBOR_SRC_HELPER_H

#include "action.hpp"

#include <vector>


//currently unused 
//namespace with helper functions that could be used by multiple objects
namespace helper {

bool check_choice_input(char input);
char option_input();
void choose_option(char choice, std::vector<Action*> options);

}


#endif
