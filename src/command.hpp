#ifndef ARBOR_SRC_COMMAND_H
#define ARBOR_SRC_COMMAND_H

#include "gamestate.hpp"
// #include "room.hpp"

class Room;


class Command {
public:
    virtual void execute();
    virtual ~Command() {}
};

class LeaveCommand : public Command {
private:
    Room* next_room;
    GameState* state;

public:
    LeaveCommand(Room* next_room, GameState* state) : next_room(next_room), state(state)
    {

    }

    ~LeaveCommand () {}

    void execute() override;
};

#endif