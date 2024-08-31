#pragma once
#include "../includes.h"

class Background {

private:

    // Variables
    sf::RectangleShape gameBackgroundShape;
    sf::Texture gameBackgroundTexture;

    sf::RectangleShape menuBackgroundShape;
    sf::Texture menuBackgroundTexture;

public:

    // C-tor / D-tor
    Background(){}
    virtual ~Background(){}

    // Other functions
    sf::RectangleShape getGameBackgroundShape() { return this->gameBackgroundShape; }
    sf::RectangleShape getMenuBackgroundShape() { return this->menuBackgroundShape; }

    void initGameBackground()
    {
        gameBackgroundShape.setPosition({0, 0});
        gameBackgroundShape.setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
        gameBackgroundTexture.loadFromFile("assets/game-background.png");
        gameBackgroundShape.setTexture(&gameBackgroundTexture);
    }

    void initMenuBackground()
    {
        menuBackgroundShape.setPosition({0, 0});
        menuBackgroundShape.setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
        menuBackgroundTexture.loadFromFile("assets/menu-background.png");
        menuBackgroundShape.setTexture(&menuBackgroundTexture);

    }

};