#include "Platform.h"

// Constructor / Destructor

Platform::Platform()
{
    // Initialising platform variables
    this->platformSize = {960, 105};
    this->platformPosition = {((WINDOW_WIDTH - platformSize.x) / 2), WINDOW_HEIGHT / 1.5};

    // Initialising platform shape object
    platformShape.setPosition(platformPosition);
    platformShape.setSize(platformSize);

    // Initialising texture
    platformTexture.loadFromFile("assets/platform.png");
    platformShape.setTexture(&platformTexture);

}

Platform::~Platform()
{
}

sf::RectangleShape Platform::getPlatformShape()
{
    return platformShape;
}

sf::Vector2f Platform::getSize()
{
    return platformSize;
}

sf::Vector2f Platform::getPosition()
{
    return platformPosition;
}
