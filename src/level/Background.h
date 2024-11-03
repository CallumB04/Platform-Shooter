#pragma once
#include "../includes.h"

class Background
{

private:
    // Variables
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); // desktop width and height

    sf::RectangleShape gameBackgroundShape;
    sf::Texture gameBackgroundTexture;

    sf::RectangleShape menuBackgroundShape;
    sf::Texture menuBackgroundTexture;

public:
    // C-tor / D-tor
    Background() {}
    virtual ~Background() {}

    // Other functions
    sf::RectangleShape getGameBackgroundShape() { return this->gameBackgroundShape; }
    sf::RectangleShape getMenuBackgroundShape() { return this->menuBackgroundShape; }

    void initGameBackground()
    {
        gameBackgroundShape.setPosition({0, 0});
        gameBackgroundShape.setSize({static_cast<float>(desktop.width), static_cast<float>(desktop.height)});
        gameBackgroundTexture.loadFromFile("assets/game-background.png");
        gameBackgroundShape.setTexture(&gameBackgroundTexture);
    }

    void initMenuBackground()
    {
        menuBackgroundShape.setPosition({0, 0});
        menuBackgroundShape.setSize({static_cast<float>(desktop.width), static_cast<float>(desktop.height)});
        menuBackgroundTexture.loadFromFile("assets/menu-background.png");
        menuBackgroundShape.setTexture(&menuBackgroundTexture);
    }
};