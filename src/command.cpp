#include "command.hpp"
#include <iostream>

//simulates moving by changing the current room to the next room.
void LeaveCommand::execute() {
    player->set_current_room(next_room);
}

void EndCommand::execute() {
    state->set_current_state(WIN);
}

void LootCommand::execute() {
    inventory->add_item(loot);
}

void UnlockCommand::execute() {
    if(inventory->check_has_item(key)) {
        move->execute();
    } else {
        std::cout << "You don't have the key.\n";
    }
}