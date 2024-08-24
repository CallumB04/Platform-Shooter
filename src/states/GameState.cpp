#include "GameState.h"

// Constructor / Destructor

GameState::GameState(std::shared_ptr<sf::RenderWindow> &window) : State(window)
{
}

GameState::~GameState()
{
}

// Ending state functions

bool GameState::getQuit()
{
    return this->quit;
}

void GameState::endState()
{
    // What to do when state is ending...
}

// Update Functions

void GameState::handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event)
{
    while(window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                window->close();
                break;
        }
    }
}

void GameState::updateCollisions(const float &dt)
{
    // if player not touching platform and not mid-jumping, starts falling
    if (!player.isGrounded(platform.getPlatformShape()) && !player.isJumping()){
        if (player.getPosition().x + player.getSize().x < platform.getPosition().x
        || player.getPosition().x > platform.getPosition().x + platform.getSize().x)
        {
            player.startFall();
        }
        float fallMomentum = player.getFallingMomentum();
        float fallAcceleration = player.getFallingAcceleration();
        player.setPosition({player.getPosition().x, player.getPosition().y + fallMomentum * dt});
        player.setFallingMomentum(fallMomentum + player.getFallingAcceleration() * dt);
    }

    // Stops player from falling through the platform
    if (!player.hasFallen()
    && player.getPosition().y + player.getSize().y > platform.getPosition().y 
    && (player.getPosition().x + player.getSize().x) > platform.getPosition().x 
    && player.getPosition().x < platform.getPosition().x + platform.getSize().x
    && player.getPosition().y < platform.getPosition().y + platform.getSize().y) 
    { 
        player.setPosition({player.getPosition().x, platform.getPosition().y - player.getSize().y});
    }

    // Adding collisions between player and sides of platform
    if (player.hasFallen() 
    && player.getPosition().y + player.getSize().y > platform.getPosition().y
    && player.getPosition().y < platform.getPosition().y + platform.getSize().y){
        if (player.getPosition().x + player.getSize().x > platform.getPosition().x
        && player.getPosition().x < WINDOW_WIDTH / 2){
            player.setPosition({platform.getPosition().x - player.getSize().x, player.getPosition().y});
        }
        else if (player.getPosition().x < platform.getPosition().x + platform.getSize().x
        && player.getPosition().x > WINDOW_WIDTH / 2){
            player.setPosition({platform.getPosition().x + platform.getSize().x, player.getPosition().y});
        }
    }

    // settings falling momentum to 0 and ends fall when player hits the platform
    if (player.isGrounded(platform.getPlatformShape()))
    { 
        player.setFallingMomentum(0.0f); 
        player.endFall();
    }

    // Updating player position whilst jumping
    if (player.isJumping()){

        // Ending jump when momentum reaches 0
        if (player.getJumpingMomentum() <= 0.0f){ player.endJump(); return;}

        float jumpMomentum = player.getJumpingMomentum();
        float jumpAcceleration = player.getJumpingAcceleration();
        player.setPosition({player.getPosition().x, player.getPosition().y - jumpMomentum * dt});
        player.setJumpingMomentum(jumpMomentum + jumpAcceleration * dt);
    }
}

void GameState::updateKeybinds(const float &dt)
{
    /* Check for keypresses */

    // Player horizontal movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        sf::Vector2f position = player.getPosition();
        position.x += (player.getWalkSpeed() * -1 * dt); // -1 because playing is moving left, closer to origin (0,0)
        player.setPosition(sf::Vector2f(position.x, position.y)); // setting new player position after movement
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sf::Vector2f position = player.getPosition();
        position.x += (player.getWalkSpeed() * 1 * dt); // 1 because playing is moving right, further from origin (0,0)
        player.setPosition(sf::Vector2f(position.x, position.y)); // setting new player position after movement
    }

    // Player jump if touching the ground
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.isGrounded(platform.getPlatformShape())){
        player.startJump(); // setting private variable isJump to true
    }
}

void GameState::updateEndingCheck()
{
    // Checks for ways the state could end. then set this->quit to true

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ this->quit = true; }
}

// Main Functions

void GameState::update(const float &dt)
{
    this->updateCollisions(dt);
    this->updateKeybinds(dt);
    this->updateEndingCheck();
}

void GameState::render(std::shared_ptr<sf::RenderWindow> &window)
{
    window->draw(player.getPlayerShape());
    window->draw(platform.getPlatformShape());
}