#pragma once
#include "../State.h"
#include "../entities/Player.h"
#include "../entities/Bullet.h"
#include "../level/Platform.h"
#include "../level/Background.h"

class GameState : public State{
private:

    // Class variables
    bool quit = false;
    sf::Event event;
    bool isExit = false; // if set to true, game and window will force close

    // Initialising objects from other entities/level objects
    Player player = Player(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
    Platform platform;
    Background background;

    std::vector<Bullet> bullets = {};
    bool hasShot = false; // prevents player for holding Comma to spray bullets

public:

    // C-tor / D-tor
    GameState(std::shared_ptr<sf::RenderWindow> &window);
    virtual ~GameState();

    bool getQuit(); // Checks if state needs to be removed
    void endState(); // Performs all necessary actions when state is removed
    bool forceExit();

    // Main Functions
    void handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event);
    void updateCollisions(const float& dt);
    void updateKeybinds(const float& dt);
    void updateEndingCheck();
    void update(const float& dt);
    void render(std::shared_ptr<sf::RenderWindow> &window);
};