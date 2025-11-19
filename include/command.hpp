#ifndef ARBOR_SRC_COMMAND_H
#define ARBOR_SRC_COMMAND_H

#include "gamestate.hpp"
#include "character.hpp" 
#include "inventory.hpp"

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
    Character* player;

public:
    LeaveCommand(Room* next_room, Character* player) 
        : next_room(next_room), player(player) {}

    ~LeaveCommand () {}

    //Every command should do something, so each kind will define its own 
    //execute function.
    void execute() override;
};

//ends the game.
class EndCommand : public Command {
private:
    GameState* state;
public:
    EndCommand(GameState* state) 
        : state(state) {}

    ~EndCommand () {}

    void execute() override;
};

//adds loot item to inventory.
class LootCommand : public Command {
private:
    Inventory* inventory;
    Item* loot;
public:
    LootCommand(Inventory* inv, Item* item)
        : inventory(inv), loot(item) {}
    
    ~LootCommand () {}
    void execute() override;
};

//Checks inventory for the key, then runs a command.
//doesn't necessarily need to be for opening a door, any interaction 
//requiring a specific item would work.
class UnlockCommand : public Command {
private:
    Inventory* inventory;
    Item* key;
    Command* move;
public:
    UnlockCommand(Inventory* inv, Item* item, Command* move)
        : inventory(inv), key(item), move(move) {}
    ~UnlockCommand() {}
    void execute() override;
};

#endif
