#pragma once
#include "../State.h"
#include "../level/Background.h"

class MainMenuState : public State{
private:

    // Class variables
    bool quit = false;
    sf::Event event;

    // Menu background
    Background background;

    // Main Menu Buttons + Textures
    sf::RectangleShape menuButton_Play;
    sf::RectangleShape menuButton_Settings;
    sf::RectangleShape menuButton_Exit;

    sf::Texture playButtonTexture;
    sf::Texture settingsButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Texture playButtonTexture_hover;
    sf::Texture settingsButtonTexture_hover;
    sf::Texture exitButtonTexture_hover;

    sf::Vector2f centralMenuButtonsSize;
    float centralMenuButtonsX;

    // Main menu variables
    bool isPlay = false;
    bool isSettings = false;
    bool isExit = false;

    // private functions
    void initMenuButtons();
    void checkMenuClick(sf::Event::MouseButtonEvent event);
    void checkMousePosition(sf::Event::MouseMoveEvent mouse);

public:

    // C-tor / D-tor
    MainMenuState(std::shared_ptr<sf::RenderWindow> &window);
    virtual ~MainMenuState();

    bool getQuit(); // Checks if state needs to be removed
    void endState(); // Performs all necessary actions when state is removed
    bool forceExit(); // Check if exit button is pressed and game should be closed

    // Main Functions
    void handleEvents(std::shared_ptr<sf::RenderWindow> &window, sf::Event event);
    void updateKeybinds(const float& dt);
    void updateEndingCheck();
    void update(const float& dt);
    void render(std::shared_ptr<sf::RenderWindow> &window);
};