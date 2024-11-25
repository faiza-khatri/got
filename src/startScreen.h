#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "baseWindow.h"
#include <SFML/Graphics.hpp>
#include <string>

class StartScreen : public BaseWindow {
public:
    /*StartScreen();*/
    StartScreen(sf::Vector2u& windowSize);
    void initializeComponents(sf::Vector2u&, int) override;
    void renderScreen(sf::RenderWindow& window) override;
    int handleInput(sf::RenderWindow&) override;
    void operator=(const StartScreen*);

private:
    sf::Sprite playButton;
    sf::Sprite exitButton;
    sf::Sprite changeBgButton;
    std::map<int, sf::Sprite> spriteList;
  
    /*void updateButtonPositions(sf::Vector2u windowSize);*/
};

#endif
