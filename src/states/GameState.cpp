#include "GameState.h"

// Constructor / Destructor

GameState::GameState(std::shared_ptr<sf::RenderWindow> &window) : State(window)
{
    this->background.initGameBackground();
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

bool GameState::forceExit()
{
    return this->isExit;
}

// Update Functions

void GameState::handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event)
{
    while(window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Comma && !this->hasShot)
                {
                    sf::Vector2f playerPos = player.getPosition();
                    Bullet bullet({playerPos.x + (player.getSize().x / 2), playerPos.y + (player.getSize().y / 2)}, player.getDirection());
                    bullets.push_back(bullet);
                    this->hasShot = true;
                }
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Comma) { this->hasShot = false; }
                break;
        }
    }
}

void GameState::updateCollisions(const float &dt)
{
    // if player not touching platform and not mid-jumping, starts falling
    if (!player.isGrounded(platform.getPlatformShape()) && !player.isJumping()){
        if ((player.getPosition().x + player.getSize().x < platform.getPosition().x
        || player.getPosition().x > platform.getPosition().x + platform.getSize().x)
        && player.getPosition().y + player.getSize().y > platform.getPosition().y)
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

    // Respawning if player has fallen out of the map
    if (player.getPosition().y > WINDOW_HEIGHT){
        player.respawn();
    }


    /* Updating bullet positions */
    int bulletCounter { 0 }; // counter to allow for removal of bullets in array
    std::vector<int> bulletsToRemove; // vector to store indexes of bullets to remove after iterated through

    // Iterating bullets
    for (Bullet &bullet : bullets)
    {
        // Checking if bullet has left the window, if so push to vector for deletion
        if (bullet.getPosition().x > WINDOW_WIDTH || bullet.getPosition().x + bullet.getSize().x < 0)
            bulletsToRemove.push_back(bulletCounter);

        sf::Vector2f position = bullet.getPosition();
        position.x += bullet.getSpeed() * dt * bullet.getDirection();
        bullet.setPosition(position);
        bulletCounter++;
    }

    std::cout << "Bullets on screen: " << bulletCounter << std::endl;

    // Deleting no longer wanted bullets
    for (int index: bulletsToRemove)
        bullets.erase(bullets.begin() + index);
}

void GameState::updateKeybinds(const float &dt)
{
    /* Check for keypresses */

    // Player horizontal movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        sf::Vector2f position = player.getPosition();
        position.x += (player.getWalkSpeed() * -1 * dt); // -1 because playing is moving left, closer to origin (0,0)
        player.setPosition(sf::Vector2f(position.x, position.y)); // setting new player position after movement
        player.setDirection(-1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sf::Vector2f position = player.getPosition();
        position.x += (player.getWalkSpeed() * 1 * dt); // 1 because playing is moving right, further from origin (0,0)
        player.setPosition(sf::Vector2f(position.x, position.y)); // setting new player position after movement
        player.setDirection(1);
    }

    // Player jump if touching the ground
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.isGrounded(platform.getPlatformShape())){
        player.startJump(); // setting private variable isJump to true
    }
}

void GameState::updateEndingCheck()
{
    /* Checks for ways the state could end. then set this->quit to true */

    // Pressing escape ends game state
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ this->quit = true; }

    // If player lives is 0, end game
    if (player.getLives() == 0){ this->quit = true; }
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
    // render background + platform first
    window->draw(background.getGameBackgroundShape());
    window->draw(platform.getPlatformShape());

    // render bullets behind player
    for (Bullet &bullet : bullets)
        window->draw(bullet.getShape());

    // render player on top
    window->draw(player.getPlayerShape());
}