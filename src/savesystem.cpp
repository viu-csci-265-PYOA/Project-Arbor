#ifndef ARBOR_SRC_SAVESYSTEM_H
#define ARBOR_SRC_SAVESYSTEM_H

#include <iostream>
#include <fstream>
#include <string>

#include "savesystem.hpp"

void save_system::save_game_state(GameState* state, std::string file_name) {
    std::ofstream file(file_name, std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "failed to open file to save gamestate." << '\n';
        return;
    }
    file.write(reinterpret_cast<const char*>(state), sizeof(*state));
    file.close();
    std::cout << "state saved successfully." << '\n';
}

GameState* save_system::load_game_state(std::string file_name) {
    GameState* new_state = new GameState;
    std::ifstream file(file_name, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "failed to open file to load gamestate" << '\n';
        return new_state;
    }
    file.read(reinterpret_cast<char*>(new_state), sizeof(new_state));
    file.close();
    std::cout << "state loaded successfully." << '\n';
    return new_state;
}




// class GameState;

// class Saver {
// public:
//     virtual void save()=0;
//     virtual ~Saver() {}
// };

// class Loader {
// public:
//     virtual ~Loader() {}
// };

// class GameStateSaver : public Saver {
// private:
//     GameState* state;
//     std::string file_name;
//     std::ofstream* file;
// public:
//     GameStateSaver(
//         GameState* state,
//         std::string file_name,
//         std::ofstream* file
//     ) :
//         state{state}, file_name{file_name}, file{file} {}

//     void save()


// };
#endif