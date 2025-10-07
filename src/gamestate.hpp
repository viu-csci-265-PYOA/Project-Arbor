#ifndef ARBOR_SRC_GAMESTATE_H
#define ARBOR_SRC_GAMESTATE_H

#include "room.hpp"

class Room;

class GameState
{
private:
    Room* current_room;
public:
    GameState();
    ~GameState();

    Room* get_current_room() {return current_room;}
    void set_current_room(Room* next_room) { current_room = next_room;}
};

GameState::GameState(/* args */)
{
}

GameState::~GameState()
{
}


#endif