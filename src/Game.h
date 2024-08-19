#pragma once
#include "includes.h"

class Game{

private:

    // Variables
    sf::RenderWindow *window;
    sf::Event event;

    float dt; // time taken per frame (update + render)
    sf::Clock _clock;

    // Init functions
    void initWindow();

public:

    // C-tor / D-tor
    Game();
    virtual ~Game();

    // Main functions
    void updateDT();
    void updateSFMLEvents();
    void Update();
    void Render();
    void Run();
};