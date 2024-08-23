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
    bool isJump;
    float fallingMomentum;
    float fallingAcceleration;
    float startJumpingMomentum;
    float jumpingMomentum;
    float jumpingAcceleration;


public:

    // C-tor / D-tor
    Player(sf::Vector2f startPos = {0.0f, 0.0f});
    virtual ~Player();

    // Get functions
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::RectangleShape getPlayerShape();
    float getWalkSpeed();
    float getFallingMomentum();
    float getFallingAcceleration();
    float getJumpingMomentum();
    float getJumpingAcceleration();

    // Set functions
    void setPosition(sf::Vector2f position);
    void setFallingMomentum(float momentum);
    void setJumpingMomentum(float momentum);
    void startJump();
    void endJump();

    // Other functions
    bool isGrounded();
    bool isJumping();
};
