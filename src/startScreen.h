#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "baseWindow.h"
#include <SFML/Graphics.hpp>
#include <string>

class StartScreen : public BaseWindow {
public:
    StartScreen();
    void loadTextures() override;
    void setupScreen(sf::RenderWindow& window);

private:
    void updateButtonPositions(sf::Vector2u windowSize, sf::Sprite& playButton, sf::Sprite& exitButton, sf::Sprite& cbButton);
};

#endif
