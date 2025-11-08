#ifndef ARBOR_SRC_COMMAND_H
#define ARBOR_SRC_COMMAND_H

#include "gamestate.hpp" 

class Room;

//pure virtual command class declaration
//implemented and defined by different kinds of command
class Command {
public:
    virtual void execute()=0;
    virtual ~Command() {}
};

//command to move from current_room to next_room
class LeaveCommand : public Command {
private:
    Room* next_room;
    GameState* state;

public:
    LeaveCommand(Room* next_room, GameState* state) 
        : next_room(next_room), state(state) {}

    ~LeaveCommand () {}

    //Every command should do something, so each kind will define its own 
    //execute function.
    void execute() override;
};


class EndCommand : public Command {
private:
    GameState* state;

public:
    EndCommand(GameState* state) 
        : state(state) {}

    ~EndCommand () {}

    void execute() override;
};

#endif
