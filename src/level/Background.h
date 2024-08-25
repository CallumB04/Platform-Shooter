#pragma once
#include "../includes.h"

class Background {

private:

    // Variables
    sf::RectangleShape backgroundShape;
    sf::Texture backgroundTexture;

public:

    // C-tor / D-tor
    Background(){
        backgroundShape.setPosition({0, 0});
        backgroundShape.setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
        backgroundTexture.loadFromFile("assets/game-background.jpg");
        backgroundShape.setTexture(&backgroundTexture);
    }
    virtual ~Background(){}

    // Other functions
    sf::RectangleShape getBackgroundShape() { return this->backgroundShape; }
};