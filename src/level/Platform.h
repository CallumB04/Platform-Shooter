#pragma once
#include "../includes.h"

class Platform{

private:

    // Platform shape
    sf::RectangleShape platformShape;

    // Platform variables
    sf::Vector2f platformPosition;
    sf::Vector2f platformSize;

public:

    // C-tor / D-tor
    Platform();
    virtual ~Platform();

    // Get functions
    sf::RectangleShape getPlatformShape();
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
};