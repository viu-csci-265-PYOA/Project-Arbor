#ifndef ARBOR_SRC_GAMESTATE_H
#define ARBOR_SRC_GAMESTATE_H

// #include "room.hpp"

class Room;

enum stage {
    PLAYING,
    WIN,
};

//pure data container to store general data about the game.
//could probably be made into a struct, might be performance benefits?
class GameState {
private:
    Room* current_room;
    stage current_stage;
public:
    Room* get_current_room() {return current_room;}
    void set_current_room(Room* next_room) { current_room = next_room;}

    stage get_current_stage() {return current_stage;}
    void set_current_stage(stage new_stage) {current_stage = new_stage;}
};


#endif
