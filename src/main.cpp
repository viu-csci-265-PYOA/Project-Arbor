#include "room.hpp"
#include "gamestate.hpp"
#include "action.hpp"
#include "command.hpp" 
#include <vector>
#include <iostream>


int main(int argc, char const *argv[])
{
    std::cout << "running" << '\n';

    Room r1("hello", "goodbye");


    std::vector<Room*> game_rooms;
    std::vector<Command*> game_commands;
    std::vector<Action*> game_actions;

    GameState* state = new GameState;

    Room* room1 = new Room("Dungeon Cell", "a musty cell in a rotten dungeon.");
    game_rooms.emplace_back(room1);
    Room* room2 = new Room("stairway", "an ancient stairway leading up.");
    game_rooms.emplace_back(room2);
    Room* room3 = new Room("hallway", "a decrepit hallway.");
    game_rooms.emplace_back(room3);

    state->set_current_room(room1);
    state->set_current_stage(PLAYING);

    Command* r1_to_r2 = new LeaveCommand(room2, state);
    game_commands.emplace_back(r1_to_r2);
    Command* r1_to_r3 = new LeaveCommand(room3, state);
    game_commands.emplace_back(r1_to_r3);

    Action* leave_cell_to_stairway = new Action("Go to the stairway", r1_to_r2);
    game_actions.emplace_back(leave_cell_to_stairway);
    Action* leave_cell_to_hallway = new Action("Go into the hallway", r1_to_r3);
    game_actions.emplace_back(leave_cell_to_hallway);

    room1->add_action(leave_cell_to_stairway);
    room1->add_action(leave_cell_to_hallway);

    while(state->get_current_stage() == PLAYING) {
        state->get_current_room()->enter();
    }




    return 0;
}
