#pragma once
#include "../includes.h"

class Platform
{

private:
    // Platform shape + texture
    sf::RectangleShape platformShape;
    sf::Texture platformTexture;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); // desktop width and height
    sf::Vector2f screenScale = {
        static_cast<float>(desktop.width) / BASE_WIDTH,
        static_cast<float>(desktop.height) / BASE_HEIGHT}; // scale of screen compared to base values (1920x1080)

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