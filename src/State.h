#pragma once
#include "includes.h"

class State{
private:

    // Variables
    std::shared_ptr<sf::RenderWindow> window;

public:

    // C-tor / D-tor
    State(std::shared_ptr<sf::RenderWindow> &window);
    virtual ~State();

    // Ending/Removing state Functions
    virtual bool getQuit() = 0; // returns value of quit boolean
    virtual void endState() = 0;

    // Main Functions
    // Any class that inherits State class, must have an Update and Render function
    virtual void handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event) = 0;
    virtual void updateKeybinds(const float& dt) = 0;
    virtual void updateEndingCheck() = 0; // Checks if a State needs to be removed (e.g: quit game, unpaused)
    virtual void update(const float& dt) = 0;
    virtual void render(std::shared_ptr<sf::RenderWindow> &window) = 0;
};