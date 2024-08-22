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

    // Other functions
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    sf::RectangleShape getPlayerShape();
};
