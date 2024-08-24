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

void GameState::updateGravity(const float &dt)
{
    // Stops player from falling through the floor
    if (player.getPosition().y + player.getSize().y > WINDOW_HEIGHT) { player.setPosition({player.getPosition().x, WINDOW_HEIGHT - player.getSize().y}); }

    // settings falling momentum to 0 when player hits the ground
    if (player.getPosition().y + player.getSize().y == WINDOW_HEIGHT){ player.setFallingMomentum(0.0f); }

    // if player not touching ground and not mid-jumping, starts falling
    if (!player.isGrounded() && !player.isJumping()){

        float fallMomentum = player.getFallingMomentum();
        float fallAcceleration = player.getFallingAcceleration();
        player.setPosition({player.getPosition().x, player.getPosition().y + fallMomentum * dt});
        player.setFallingMomentum(fallMomentum + player.getFallingAcceleration() * dt);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.isGrounded()){
        player.startJump(); // setting private variable isJump to true
    }
}

void GameState::updateEndingCheck()
{
    // Checks for ways the state could end. then set this->quit to true
}

// Main Functions

void GameState::update(const float &dt)
{
    this->updateGravity(dt);
    this->updateKeybinds(dt);
    this->updateEndingCheck();
}

void GameState::render(std::shared_ptr<sf::RenderWindow> &window)
{
    window->draw(player.getPlayerShape());
}