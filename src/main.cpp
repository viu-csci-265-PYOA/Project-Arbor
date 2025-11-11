#include "room.hpp"
#include "gamestate.hpp"
#include "action.hpp"
#include "command.hpp"
#include "savesystem.hpp"
 
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    const std::string game_state_file_name = "resource/save/saved_game_state.bin";

    //vectors to store the game objects
    //  so they can be deleted at end of runtime
    std::vector<Room*> game_rooms;
    std::vector<Command*> game_commands;
    std::vector<Action*> game_actions;

    GameState* state = save_system::load_game_state(game_state_file_name);
    state->print_out();
    // GameState* state = new GameState;

    //currently hardcoding the room names and descriptions
    //TODO: system to fetch this data from a txt file.
    Room* room_1 = new Room("Dungeon Cell", "a musty cell in a rotten dungeon.");
    game_rooms.emplace_back(room_1);
    Room* room_2 = new Room("stairway", "an ancient stairway leading up.");
    game_rooms.emplace_back(room_2);
    Room* room_3 = new Room("hallway", "a decrepit hallway.");
    game_rooms.emplace_back(room_3);

    state->set_current_room(room_1);
    state->set_current_stage(PLAYING);

    //leave command only refers to the target room, so the name is important
    //  make clear what room each one is coming from.
    Command* r1_to_r2 = new LeaveCommand(room_2, state);
    game_commands.emplace_back(r1_to_r2);
    Command* r1_to_r3 = new LeaveCommand(room_3, state);
    game_commands.emplace_back(r1_to_r3);

    //two different commands doing the same thing,
    //need to determine if one command can be shared by multiple actions.
    Command* r2_end = new EndCommand(state);
    game_commands.emplace_back(r2_end);
    Command* r3_end = new EndCommand(state);
    game_commands.emplace_back(r3_end);

    //creating actions for the relevant commands.
    Action* leave_cell_to_stairway = new Action("Go to the stairway", r1_to_r2);
    game_actions.emplace_back(leave_cell_to_stairway);
    Action* leave_cell_to_hallway = new Action("Go into the hallway", r1_to_r3);
    game_actions.emplace_back(leave_cell_to_hallway);
    Action* stairway_dead_end = new Action("Dead End", r2_end);
    game_actions.emplace_back(stairway_dead_end);
    Action* hallway_dead_end = new Action("Dead End", r3_end);

    //attaching the actions to room 1
    room_1->add_action(leave_cell_to_stairway);
    room_1->add_action(leave_cell_to_hallway);
    
    //attaching the dead end actions.
    room_2->add_action(stairway_dead_end);
    room_3->add_action(hallway_dead_end);

    //game loop.
    while(state->get_current_stage() == PLAYING) {
        state->get_current_room()->enter();
    }

    save_system::save_game_state(state, game_state_file_name);


    //need to check if cleanup is working and there are no memory leaks.

    //cleaning up commands.
    for (auto i: game_commands) {
        delete i;
    }

    //cleaning up actions.
    for (auto i: game_actions) {
        delete i;
    }

    //cleaning up rooms.
    for (auto i: game_rooms) {
        delete i;
    }

    delete state;

    return 0;
}
