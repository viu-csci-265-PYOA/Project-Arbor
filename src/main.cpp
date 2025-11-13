#include "room.hpp"
#include "gamestate.hpp"
#include "action.hpp"
#include "command.hpp"
#include "character.hpp"
 
#include <vector>
#include <iostream>


int main(int argc, char const *argv[])
{

    //vectors to store the game objects
    //  so they can be deleted at end of runtime
    std::vector<Room*> game_rooms;
    std::vector<Command*> game_commands;
    std::vector<Action*> game_actions;
    std::vector<Item*> game_items;

    GameState* state = new GameState;
    Character* player = new Character;
    Inventory* inventory = new Inventory;

    //currently hardcoding the room names and descriptions
    //TODO: system to fetch this data from a txt file.
    Room* room_1 = new Room("Dungeon Cell", "a musty cell in a rotten dungeon.");
    game_rooms.emplace_back(room_1);
    Room* room_2 = new Room("stairway", "an ancient stairway leading up.");
    game_rooms.emplace_back(room_2);
    Room* room_3 = new Room("hallway", "a decrepit hallway.");
    game_rooms.emplace_back(room_3);
    Room* room_4 = new Room("treasure trove", "a hoard of gleaming jewels.");

    player->set_current_room(room_1);
    state->set_current_state(PLAYING);

    //leave command only refers to the target room, so the name is important
    //  make clear what room each one is coming from.
    Command* r1_to_r2 = new LeaveCommand(room_2, player);
    game_commands.emplace_back(r1_to_r2);
    Command* r1_to_r3 = new LeaveCommand(room_3, player);
    game_commands.emplace_back(r1_to_r3);

    //two different commands doing the same thing,
    //need to determine if one command can be shared by multiple actions.
    Command* r2_end = new EndCommand(state);
    game_commands.emplace_back(r2_end);
    Command* r3_end = new EndCommand(state);
    game_commands.emplace_back(r3_end);
    Command* r4_end = new EndCommand(state);
    game_commands.emplace_back(r4_end);

    Item* platinum_key = new Item(
        "Platinum Key",
        "A key covered in grime. Gleaming metal peeks through."
    );
    game_items.emplace_back(platinum_key);
    Command* grab_key = new LootCommand(inventory, platinum_key);
    game_commands.emplace_back(grab_key);

    Action* hallway_grab_key = new Action("Pick up the dirty key", grab_key);
    game_actions.emplace_back(hallway_grab_key);

    Command* r3_to_r4_locked = new LeaveCommand(room_4, player);
    game_commands.emplace_back(r3_to_r4_locked);
    Command* r3_to_r4_unlock = new UnlockCommand(inventory, platinum_key, r3_to_r4_locked);
    game_commands.emplace_back(r3_to_r4_unlock);

    Action* unlock_hallway_to_trove = new Action("Attempt to unlock the door.", r3_to_r4_unlock);
    game_actions.emplace_back(unlock_hallway_to_trove);



    //creating actions for the relevant commands.
    Action* leave_cell_to_stairway = new Action("Go to the stairway", r1_to_r2);
    game_actions.emplace_back(leave_cell_to_stairway);
    Action* leave_cell_to_hallway = new Action("Go into the hallway", r1_to_r3);
    game_actions.emplace_back(leave_cell_to_hallway);
    Action* stairway_dead_end = new Action("Dead End", r2_end);
    game_actions.emplace_back(stairway_dead_end);
    Action* hallway_dead_end = new Action("Dead End", r3_end);
    game_actions.emplace_back(hallway_dead_end);
    Action* trove_dead_end = new Action("Dead End", r3_end);
    game_actions.emplace_back(trove_dead_end);


    //attaching the actions to room 1
    room_1->add_action(leave_cell_to_stairway);
    room_1->add_action(leave_cell_to_hallway);
    room_3->add_action(hallway_grab_key);
    room_3->add_action(unlock_hallway_to_trove);

    //attaching the dead end actions.
    room_2->add_action(stairway_dead_end);
    room_3->add_action(hallway_dead_end);
    room_4->add_action(trove_dead_end);

    //game loop.
    while(state->get_current_state() == PLAYING) {
        player->get_current_room()->enter();
    }


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

    return 0;
}
