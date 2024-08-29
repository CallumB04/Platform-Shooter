#include "MainMenuState.h"

// Private functions
void MainMenuState::checkMenuClick(sf::Event::MouseButtonEvent mouse)
{
    sf::Vector2f mousePosition = {(float) mouse.x, (float) mouse.y};

    if (menuButton_Play.getGlobalBounds().contains(mousePosition)){ this->isPlay = true; }
    else if (menuButton_Settings.getGlobalBounds().contains(mousePosition)){ this->isSettings = true; }
    else if (menuButton_Exit.getGlobalBounds().contains(mousePosition)){ this->isExit = true; }
}

void MainMenuState::checkMousePosition(sf::Event::MouseMoveEvent mouse)
{
    // Getting mouse current X and Y position
    sf::Vector2f mousePosition = { (float) mouse.x, (float) mouse.y };

    // Changes button textures to hover when mouse is touching them
    if (menuButton_Play.getGlobalBounds().contains(mousePosition)){ menuButton_Play.setTexture(&playButtonTexture_hover); }
    else if (menuButton_Settings.getGlobalBounds().contains(mousePosition)){ menuButton_Settings.setTexture(&settingsButtonTexture_hover); }
    else if (menuButton_Exit.getGlobalBounds().contains(mousePosition)){ menuButton_Exit.setTexture(&exitButtonTexture_hover); }

    else
    {
        // Resets all menu buttons to non-hover textures
        menuButton_Play.setTexture(&playButtonTexture);
        menuButton_Settings.setTexture(&settingsButtonTexture); 
        menuButton_Exit.setTexture(&exitButtonTexture);
    }
}

void MainMenuState::initMenuButtons()
{
    // Initialising values for central menu buttons (Play, settings, exit)
    centralMenuButtonsSize = {WINDOW_WIDTH / 6, WINDOW_HEIGHT / 7.8f};
    centralMenuButtonsX = (WINDOW_WIDTH / 2) - (centralMenuButtonsSize.x / 2);

    // Initialising button rectangle shapes
    menuButton_Play.setSize(centralMenuButtonsSize);
    menuButton_Play.setPosition({centralMenuButtonsX, WINDOW_HEIGHT * 0.42f});
    playButtonTexture.loadFromFile("assets/main-menu-buttons/play.png");
    playButtonTexture_hover.loadFromFile("assets/main-menu-buttons/play-hover.png");
    menuButton_Play.setTexture(&playButtonTexture);

    menuButton_Settings.setSize(centralMenuButtonsSize);
    menuButton_Settings.setPosition({centralMenuButtonsX, WINDOW_HEIGHT * 0.56f});
    settingsButtonTexture.loadFromFile("assets/main-menu-buttons/settings.png");
    settingsButtonTexture_hover.loadFromFile("assets/main-menu-buttons/settings-hover.png");
    menuButton_Settings.setTexture(&settingsButtonTexture);

    menuButton_Exit.setSize(centralMenuButtonsSize);
    menuButton_Exit.setPosition({centralMenuButtonsX, WINDOW_HEIGHT * 0.7f});
    exitButtonTexture.loadFromFile("assets/main-menu-buttons/exit.png");
    exitButtonTexture_hover.loadFromFile("assets/main-menu-buttons/exit-hover.png");
    menuButton_Exit.setTexture(&exitButtonTexture);
}

// Constructor / Destructor

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> &window) : State(window)
{
    this->initMenuButtons();
}

MainMenuState::~MainMenuState()
{
}

// Ending state functions

bool MainMenuState::getQuit()
{
    return this->quit;
}

void MainMenuState::endState()
{
    // What to do when state is ending...
}

bool MainMenuState::forceExit()
{
    return this->isExit;
}

// Update Functions

void MainMenuState::handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event)
{
    while(window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.key.code == sf::Mouse::Left){ this->checkMenuClick(event.mouseButton); }
                break;

            case sf::Event::MouseMoved:
                this->checkMousePosition(event.mouseMove);
                break;
        }
    }
}

void MainMenuState::updateKeybinds(const float &dt)
{
    // Check for keypresses

    if (isSettings){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->isSettings = false;
        }
    }
}

void MainMenuState::updateEndingCheck()
{
    /* Checks for ways the state could end. then set this->quit to true */

    // If players clicks Play, ends menu state to load game
    if (isPlay) { this->quit = true; }
}

// Main Functions

void MainMenuState::update(const float &dt)
{
    this->updateKeybinds(dt);
    this->updateEndingCheck();
}

void MainMenuState::render(std::shared_ptr<sf::RenderWindow> &window)
{
    // Drawing Background
    window->draw(this->background.getMenuBackgroundShape());

    // Main Menu
    if (!this->isSettings){
        // Drawing main menu buttons
        window->draw(menuButton_Play);
        window->draw(menuButton_Settings);
        window->draw(menuButton_Exit);
    } 
    
    // Settings Menu
    else if (this->isSettings){
        
    }
}