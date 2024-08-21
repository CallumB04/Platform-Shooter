#pragma once
#include "includes.h"
#include "states/GameState.h"
#include "states/MainMenuState.h"

class Game{

private:

    // Variables
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event event;

    float dt; // time taken per frame (update + render)
    sf::Clock _clock;

    // std::stack<State*> states;
    std::stack<std::unique_ptr<State>> states;

public:

    // C-tor / D-tor
    Game();
    virtual ~Game();

    // Other functions
    void endApp();
    void updateDT();

    // Main functions
    void update();
    void render();
    void run();
};