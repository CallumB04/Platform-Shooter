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

void Game::updateDT(){

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

void Game::Update(){
    this->updateDT();
    this->updateSFMLEvents();
}

void Game::Render(){
    this->window->clear();
    
    this->window->display();
}

void Game::Run(){
    while ( this->window->isOpen() ){
        this->Update();
        this->Render();
    }
}