#pragma once
#include "../State.h"
#include "../entities/Player.h"

class GameState : public State{
private:

    bool quit = false;
    sf::Event event;

    Player player = Player(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/1.5));

public:

    // C-tor / D-tor
    GameState(std::shared_ptr<sf::RenderWindow> &window);
    virtual ~GameState();

    bool getQuit(); // Checks if state needs to be removed
    void endState(); // Performs all necessary actions when state is removed

    // Main Functions
    void handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event);
    void updateGravity(const float& dt);
    void updateKeybinds(const float& dt);
    void updateEndingCheck();
    void update(const float& dt);
    void render(std::shared_ptr<sf::RenderWindow> &window);
};