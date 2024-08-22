#include "Player.h"

// Constructor / Destructor

Player::Player(sf::Vector2f startPos)
{
    // Initialising player variables
    this->playerPosition = startPos;
    this->playerSize = sf::Vector2f(35.0f, 60.0f);
    this->playerWalkSpeed = 250.0f;

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

void Player::setPosition(sf::Vector2f position)
{
    this->playerPosition = position;
    playerShape.setPosition(position);
}

sf::RectangleShape Player::getPlayerShape()
{
    return playerShape;
}

float Player::getWalkSpeed()
{
    return this->playerWalkSpeed;
}
