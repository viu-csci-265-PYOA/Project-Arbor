#include "gamestate.hpp"
#include "room.hpp"

void GameState::print_out() {
    std::cout << "stage: " << current_stage << '\n' 
        << "current room:" << '\n' << "name: " <<
        current_room->get_name() << '\n' <<
        "desc: " << current_room->get_desc() << '\n';
}