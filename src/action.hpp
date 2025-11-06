#ifndef ARBOR_SRC_ACTION_H
#define ARBOR_SRC_ACTION_H

#include "gamestate.hpp"
#include "command.hpp"

#include <string>
#include <functional>

class Command;

//Actions are presented by rooms, hold a name, 
//and potentially call a command.
//TODO: consider scenarios where no command is needed,
//  for instance, a 'search' action that just prints info about the room 
//Should actions also hold a description?
//  if player picks an action with name "Try to pick the lock" the description
//  could read "You use your set of thief's tools to jimmy open the lock"

class Action
{
private:
    std::string name;
    Command* command;
public:
    Action(std::string name, Command* command) 
        : name{name}, command{command} {}
    ~Action() {}

    //a print function is currently redundant 
    //  since there is only a name field, but could be useful in future
    // void print() const;
    void run_action();
    std::string get_name() const;

};

#endif
