#include "GameState.h"

// Constructor / Destructor

GameState::GameState(std::shared_ptr<sf::RenderWindow> &window) : State(window)
{
}

GameState::~GameState()
{
}

// Ending state functions

bool GameState::getQuit()
{
    return this->quit;
}

void GameState::endState()
{
    // What to do when state is ending...
}

// Update Functions

void GameState::handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event)
{
    while(window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                window->close();
                break;
        }
    }
}

void GameState::updateKeybinds(const float &dt)
{
    /* Check for keypresses */

    // Player horizontal movement (vertical movement through jumping + falling will be added)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        sf::Vector2f position = player.getPosition();
        position.x += (player.getWalkSpeed() * -1 * dt); // -1 because playing is moving left, closer to origin (0,0)
        player.setPosition(sf::Vector2f(position.x, position.y)); // setting new player position after movement
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sf::Vector2f position = player.getPosition();
        position.x += (player.getWalkSpeed() * 1 * dt); // 1 because playing is moving right, further from origin (0,0)
        player.setPosition(sf::Vector2f(position.x, position.y)); // setting new player position after movement
    }
}

void GameState::updateEndingCheck()
{
    // Checks for ways the state could end. then set this->quit to true
}

// Main Functions

void GameState::update(const float &dt)
{
    this->updateKeybinds(dt);
    this->updateEndingCheck();
}

void GameState::render(std::shared_ptr<sf::RenderWindow> &window)
{
    window->draw(player.getPlayerShape());
}