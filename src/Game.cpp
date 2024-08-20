#include "Game.h"

// Init Functions

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Platform-Shooter", sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

// Constructor / Destructor

Game::Game(){
    this->initWindow();
    this->initStates();
}

Game::~Game(){
    delete this->window;

    // removing all states from stack
    while(!this->states.empty()){
        delete this->states.top();
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

void Game::updateSFMLEvents(){
    while(this->window->pollEvent(event)){
        switch (event.type){
            case sf::Event::Closed:
                this->window->close();
                break;
        }
    }
}

// Main Functions

void Game::update(){ 

    // updateDT() needs to run before anything else, to ensure frametime is accurate
    this->updateDT();
    this->updateSFMLEvents();

    // updating the state on the top of the stack, if the stack is not empty
    if(!this->states.empty()){
        this->states.top()->update(this->dt);

        // removes state from stack when moving to new state in the game
        if (this->states.top()->getQuit()){
            this->states.top()->endState(); // anything necessary before deleting state (e.g: saving progress)
            delete this->states.top();
            this->states.pop();
        }
    }

    // Stack empty, Game end, closing program
    else { this->endApp(); }
}

void Game::render(){
    this->window->clear();

    // rendering the state on the top of the stack, if the stack is not empty
    if(!this->states.empty()){
        this->states.top()->render(this->window);
    }
    
    this->window->display();
}

void Game::run(){
    while ( this->window->isOpen() ){
        this->update();
        this->render();
    }
}