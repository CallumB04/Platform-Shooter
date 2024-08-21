#pragma once
#include "State.h"

class GameState : public State{
private:

    bool quit = false;
    sf::Event event;

public:

    // C-tor / D-tor
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    bool getQuit(); // Checks if state needs to be removed
    void endState(); // Performs all necessary actions when state is removed

    // Main Functions
    void handleEvents(sf::RenderWindow* window, sf::Event event);
    void updateKeybinds(const float& dt);
    void updateEndingCheck();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};