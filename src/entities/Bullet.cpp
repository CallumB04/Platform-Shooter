#include "Bullet.h"

Bullet::Bullet(sf::Vector2f startPosition, int direction)
{
    // Initialising bullet
    this->size = {20.0f * screenScale.x, 8.0f * screenScale.y};
    this->position = startPosition;
    this->speed = 700.0f * screenScale.x;
    this->direction = direction;

    bullet.setFillColor(sf::Color::White);
    bullet.setPosition(this->position);
    bullet.setSize(size);
}

Bullet::~Bullet() {}

sf::RectangleShape &Bullet::getShape()
{
    return this->bullet;
}

void Bullet::setPosition(sf::Vector2f position)
{
    this->position = position;
    bullet.setPosition(position);
}

sf::Vector2f Bullet::getPosition()
{
    return this->position;
}

sf::Vector2f Bullet::getSize()
{
    return this->size;
}

int Bullet::getDirection()
{
    return this->direction;
}

float Bullet::getSpeed()
{
    return this->speed;
}