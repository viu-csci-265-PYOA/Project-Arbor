#include "action.hpp"

void Action::run_action() {
    command->execute();
}

std::string Action::get_name() const {
    return name;
}