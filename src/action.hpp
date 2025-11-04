#ifndef ARBOR_SRC_ACTION_H
#define ARBOR_SRC_ACTION_H

#include "gamestate.hpp"
#include "command.hpp"

#include <string>
#include <functional>

class Command;

class Action
{
private:
    std::string name;
    Command* command;
public:
    Action(std::string name, Command* command) : name{name}, command{command} {}
    ~Action() {}

    // void print() const;
    void run_action();
    std::string get_name() const;

};

#endif
