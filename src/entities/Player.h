#pragma once
#include "../includes.h"

class Player
{

private:
    // Window variables
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); // desktop width and height
    sf::Vector2f screenScale = {
        static_cast<float>(desktop.width) / BASE_WIDTH,
        static_cast<float>(desktop.height) / BASE_HEIGHT}; // scale of screen compared to base values (1920x1080)

    // Player shape
    sf::RectangleShape playerShape;

    // Player variables
    sf::Vector2f spawnPosition;
    sf::Vector2f playerPosition;
    sf::Vector2f playerSize;
    int lives;
    float playerWalkSpeed;
    bool isJump;
    bool fall;
    float fallingMomentum;
    float fallingAcceleration;
    float startJumpingMomentum;
    float jumpingMomentum;
    float jumpingAcceleration;
    int direction; // 1 - facing right, 2 - facing left

public:
    // C-tor / D-tor
    Player(sf::Vector2f spawnPosition = {0.0f, 0.0f});
    virtual ~Player();

    // Get functions
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::RectangleShape getPlayerShape();
    int getLives();
    float getWalkSpeed();
    float getFallingMomentum();
    float getFallingAcceleration();
    float getJumpingMomentum();
    float getJumpingAcceleration();
    int getDirection();

    // Set functions
    void setPosition(sf::Vector2f position);
    void setFallingMomentum(float momentum);
    void setJumpingMomentum(float momentum);
    void startJump();
    void endJump();
    void startFall();
    void endFall();
    void setDirection(int direction);

    // Other functions
    bool isGrounded(sf::RectangleShape platform);
    bool isJumping();
    bool hasFallen();
    void respawn();
    void removeLife();
};
