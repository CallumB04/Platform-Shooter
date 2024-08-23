#include "Player.h"

// Constructor / Destructor

Player::Player(sf::Vector2f startPos)
{
    // Initialising player variables
    this->playerPosition = startPos;
    this->playerSize = sf::Vector2f(35.0f, 60.0f);
    this->playerWalkSpeed = 250.0f;
    this->isJump = false;
    this->fallingMomentum = 0.0f;
    this->fallingAcceleration = 0.1f;
    this->startJumpingMomentum = 5.0f; // allows jumpingMomentum to be reset to this value after each jump
    this->jumpingMomentum = this->startJumpingMomentum;
    this->jumpingAcceleration = -0.25f;

    // Initialing player shape
    playerShape.setPosition(playerPosition);
    playerShape.setSize(playerSize);
    playerShape.setFillColor(sf::Color::White);
}

Player::~Player()
{
}

// Other functions

sf::Vector2f Player::getPosition()
{
    return this->playerPosition;
}

sf::Vector2f Player::getSize()
{
    return this->playerSize;
}

void Player::setPosition(sf::Vector2f position)
{
    this->playerPosition = position;
    playerShape.setPosition(position);
}

void Player::setFallingMomentum(float momentum)
{
    this->fallingMomentum = momentum;
}

void Player::setJumpingMomentum(float momentum)
{
    this->jumpingMomentum = momentum;
}

void Player::startJump()
{
    this->isJump = true;
}

void Player::endJump()
{
    this->isJump = false;
    this->jumpingMomentum = this->startJumpingMomentum;
}

bool Player::isGrounded()
{
    if (this->playerPosition.y + this->playerSize.y == WINDOW_HEIGHT){ // Playing is touching the floor, return true. else return false
        return true;
    } return false;
}

bool Player::isJumping()
{
    return this->isJump;
}

sf::RectangleShape Player::getPlayerShape()
{
    return playerShape;
}

float Player::getWalkSpeed()
{
    return this->playerWalkSpeed;
}

float Player::getFallingMomentum()
{
    return this->fallingMomentum;
}

float Player::getFallingAcceleration()
{
    return this->fallingAcceleration;
}

float Player::getJumpingMomentum()
{
    return this->jumpingMomentum;
}

float Player::getJumpingAcceleration()
{
    return this->jumpingAcceleration;
}
