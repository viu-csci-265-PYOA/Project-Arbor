#ifndef ARBOR_SRC_ACTION_H
#define ARBOR_SRC_ACTION_H

#include "room.hpp"
#include "gamestate.hpp"

#include <string>
#include <functional>

class Room;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = 0;
};

class UnlockCommand : public Command {
private:
    Room* next_room;
public: 
    void execute() override {

    }
};

class Action
{
private:
    std::string name;
    Command* command;
public:
    Action(/* args */);
    ~Action();

    // void print() const;
    void run_action();
    std::string get_name() const;
};

Action::Action(/* args */)
{
}

Action::~Action()
{
}

#endif