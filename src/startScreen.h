#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "baseWindow.h"
#include <SFML/Graphics.hpp>
#include <string>

class StartScreen : public BaseWindow {
public:
    StartScreen(sf::Vector2u& windowSize);
    void initializeComponents(sf::Vector2u&) override;
    void renderScreen(sf::RenderWindow& window) override;
    void handleInput(sf::RenderWindow&, Game& game);

private:
    sf::Sprite playButton;
    sf::Sprite exitButton;
    sf::Sprite changeBgButton;
    std::map<int, sf::Sprite> spriteList;
    /*void updateButtonPositions(sf::Vector2u windowSize);*/
};

#endif
