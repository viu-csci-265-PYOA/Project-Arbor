#include "../include/room.hpp"
#include "../include/gamestate.hpp"
#include "../include/action.hpp"
#include "../include/command.hpp"
#include "../include/character.hpp"
#include "../include/savesystem.hpp"
#include "../include/fileio.hpp"
 
#include <vector>
#include <iostream>


int main(int argc, char const *argv[])
{
    const std::string game_state_file_name =
        "resource/save/saved_game_state.bin";
    const std::string game_state_file_name_test =
        "resource/save/saved_game_state_test.bin";

    //vectors to store the game objects
    //  so they can be deleted at end of runtime
    std::vector<Room*> game_rooms;
    std::vector<Command*> game_commands;
    std::vector<Action*> game_actions;
    std::vector<Item*> game_items;

    //load room directory info from file
    std::vector<RoomInfo> room_directory;
    get_directory(room_directory);

    //build rooms and emplace in game_rooms vector
    for(RoomInfo room : room_directory){
        game_rooms.emplace_back(create_room(room_directory, room.get_room_no()));
    }

    GameState* state = 
        save_system::load_object<GameState>(game_state_file_name);
    
    Character* player = 
        save_system::load_object<Character>(game_state_file_name);
    
    //adding actions to each game room
    for(Room* room : game_rooms){
        Room* action1 = search_directory(game_rooms, room->get_opt(1));
        room->add_action(create_action(action1, player, state));
        Room* action2 = search_directory(game_rooms, room->get_opt(2));
        room->add_action(create_action(action2, player, state));
    }

    //set for new game
    player->set_current_room(game_rooms[0]);
    state->set_current_state(PLAYING);
   
    //game loop.
    while(state->get_current_state() == PLAYING) {
        player->get_current_room()->enter();
    }

    save_system::save_object<GameState>(state, game_state_file_name);


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
