#include "Game.h"

// Constructor / Destructor

Game::Game()
{

    // Initialising Window and config
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    this->window = std::make_shared<sf::RenderWindow>(desktop, "Platform-Shooter", sf::Style::Fullscreen);
    // this->window->setFramerateLimit(120);

    // Pushing states to the stack
    this->states.push(std::make_unique<GameState>(this->window));
    this->states.push(std::make_unique<MainMenuState>(this->window));
}

Game::~Game()
{

    // removing all states from stack
    while (!this->states.empty())
    {
        this->states.pop();
    }
}

// Other Functions

void Game::endApp()
{
    this->window->close();
}

void Game::updateDT()
{
    // updates dt variable with time taken per frame
    this->dt = this->_clock.restart().asSeconds();
}

// Main Functions

void Game::update()
{

    // updateDT() needs to run before anything else, to ensure frametime is accurate
    this->updateDT();

    // updating the state on the top of the stack, if the stack is not empty
    if (!this->states.empty())
    {
        this->states.top()->handleEvents(this->window, this->event);
        this->states.top()->update(this->dt);

        if (this->states.top()->forceExit())
        {
            this->endApp();
        }

        // removes state from stack when moving to new state in the game
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState(); // anything necessary before deleting state (e.g: saving progress)
            this->states.pop();
        }
    }

    // Stack empty, Game end, closing program
    else
    {
        this->endApp();
    }
}

void Game::render()
{
    // clear screen, set background to grey if no other background texture is present
    this->window->clear(sf::Color(180, 180, 180));

    // rendering the state on the top of the stack, if the stack is not empty
    if (!this->states.empty())
    {
        this->states.top()->render(this->window);
    }

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}