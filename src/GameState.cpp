#include "GameState.h"

// Constructor / Destructor

GameState::GameState(sf::RenderWindow* window) : State(window)
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

void GameState::handleEvents(sf::RenderWindow *window, sf::Event event)
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
    // Check for keypresses
}

void GameState::updateEndingCheck()
{
    // Checks for ways the state could end
}

// Main Functions

void GameState::update(const float &dt)
{
    this->updateKeybinds(dt);
    this->updateEndingCheck();
}

void GameState::render(sf::RenderTarget* target)
{

}