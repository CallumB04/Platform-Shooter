#pragma once
#include "../State.h"

class MainMenuState : public State{
private:

    bool quit = false;
    sf::Event event;

public:

    // C-tor / D-tor
    MainMenuState(std::shared_ptr<sf::RenderWindow> &window);
    virtual ~MainMenuState();

    bool getQuit(); // Checks if state needs to be removed
    void endState(); // Performs all necessary actions when state is removed

    // Main Functions
    void handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event);
    void updateKeybinds(const float& dt);
    void updateEndingCheck();
    void update(const float& dt);
    void render(std::shared_ptr<sf::RenderWindow> &window);
};