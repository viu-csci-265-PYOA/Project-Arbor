#ifndef ARBOR_SRC_GAMESTATE_H
#define ARBOR_SRC_GAMESTATE_H

enum state {
    PLAYING,
    WIN,
};

//Simple enum to keep track of what state the game's in.
class GameState {
private:
    state current_state;
public:
    state get_current_state() {return current_state;}
    void set_current_state(state new_state) {current_state = new_state;}
};

#endif