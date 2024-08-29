#pragma once
#include "../includes.h"

class Bullet 
{
private:
    
    // Bullet variables
    sf::RectangleShape bullet;

    sf::Vector2f size;
    sf::Vector2f position;
    float speed;
    int direction; // direction bullet was shot in. 1 - right, -1 - left

public:
    
    // C-tor / D-tor
    Bullet(sf::Vector2f startPosition, int direction);
    virtual ~Bullet();

    // Functions
    sf::RectangleShape &getShape();

    void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
    sf::Vector2f getSize();
    int getDirection();
    float getSpeed();

};