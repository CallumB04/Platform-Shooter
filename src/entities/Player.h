#pragma once
#include "../includes.h"

class Player {

private:

    // Player shape
    sf::RectangleShape playerShape;

    // Player variables
    sf::Vector2f playerPosition;
    sf::Vector2f playerSize;
    float playerWalkSpeed;


public:

    // C-tor / D-tor
    Player();
    virtual ~Player();

    // Get functions
    sf::Vector2f getPosition();
    sf::RectangleShape getPlayerShape();
    float getWalkSpeed();

    // Set functions
    void setPosition(sf::Vector2f position);
};
