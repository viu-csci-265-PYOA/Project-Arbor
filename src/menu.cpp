#include "../include/menu.hpp"

PauseMenu::PauseMenu(GameState* game_state) {
    state = game_state;

    ResumeCommand* play = new ResumeCommand(state);
    cmds.emplace_back(play);
    EndCommand* end = new EndCommand(state);
    cmds.emplace_back(end);

    Action* resume_game = new Action("Resume", play);
    options.emplace_back(resume_game);
    Action* exit_game = new Action("Exit", end);
    options.emplace_back(exit_game);
}

PauseMenu::~PauseMenu() {
    for(auto i: options) {
        delete i;
    }
    for(auto i: cmds) {
        delete i;
    }
}

void PauseMenu::print() const {
    std::cout << "PAUSED\n";
    if(options.size() >= 1) {
        for(int i = 0; i < options.size(); i++) {
            std::cout << i+1 << ". " << options[i]->get_name() << '\n';
        }
    } else {
        std::cout << "No options.\n";
    }
}

void PauseMenu::run() {
    print();
    char choice = helper::option_input();
    if(helper::input_is_digit(choice)) { //input validation check
        helper::choose_option(choice, options);
    }
}