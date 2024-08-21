#include "State.h"
#include "includes.h"

// Constructor / Destructor

State::State(std::shared_ptr<sf::RenderWindow> &window)
{
    this->window = window;
}

State::~State()
{
}