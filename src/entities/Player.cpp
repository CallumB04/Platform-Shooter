#include "Player.h"

// Constructor / Destructor

Player::Player()
{
    // Initialising player variables
    this->playerPosition = sf::Vector2f(0.0f, 0.0f);
    this->playerSize = sf::Vector2f(8.0f, 13.0f);
    this->playerWalkSpeed = 10.0f;

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
