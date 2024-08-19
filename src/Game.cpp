#include "Game.h"

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Platform-Shooter", sf::Style::Close);
    this->window->setFramerateLimit(60);
}

Game::Game(){
    this->initWindow();
}

Game::~Game(){
    delete this->window;
}

void Game::Run(){
    while ( this->window->isOpen() ){
        // update + render functions will go here
    }
}