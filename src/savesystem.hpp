#include <string>

#include "gamestate.hpp"
// class GameState;

namespace save_system {
    void save_game_state(GameState* state, std::string file_name);
    GameState* load_game_state(std::string file_name);
}