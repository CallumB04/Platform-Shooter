#pragma once
#include "includes.h"

class Game{

private:

    // Variables
    sf::RenderWindow* window;
    sf::Event event;

    const float dt = 1.0f / 60.0f;
    sf::Clock _clock;

    // Init functions
    void initWindow();

public:

    // C-tor / D-tor
    Game();
    virtual ~Game();

    // Main functions
    void Run();
};