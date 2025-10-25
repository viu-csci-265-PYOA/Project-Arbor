#include "command.hpp"

void LeaveCommand::execute() {
    state->set_current_room(next_room);
}