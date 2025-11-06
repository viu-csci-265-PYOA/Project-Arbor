#include "command.hpp"

//simulates moving by changing the current room to the next room.
void LeaveCommand::execute() {
    state->set_current_room(next_room);
}

void EndCommand::execute() {
    state->set_current_stage(WIN);
}