#include "MainMenuState.h"

// Constructor / Destructor

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> &window) : State(window)
{
}

MainMenuState::~MainMenuState()
{
}

// Ending state functions

bool MainMenuState::getQuit()
{
    return this->quit;
}

void MainMenuState::endState()
{
    // What to do when state is ending...
}

// Update Functions

void MainMenuState::handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event)
{
    while(window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                window->close();
                break;
        }
    }
}

void MainMenuState::updateKeybinds(const float &dt)
{
    // Check for keypresses
}

void MainMenuState::updateEndingCheck()
{
    // Checks for ways the state could end. then set this->quit to true
}

// Main Functions

void MainMenuState::update(const float &dt)
{
    this->updateKeybinds(dt);
    this->updateEndingCheck();
}

void MainMenuState::render(std::shared_ptr<sf::RenderWindow> &window)
{

}