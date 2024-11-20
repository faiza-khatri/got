#include "startScreen.h"
#include <iostream>
#include <filesystem>

StartScreen::StartScreen(sf::Vector2u& windowSize) {
    loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\start_scrn");
    initializeComponents(windowSize);
}


//void StartScreen::updateButtonPositions() {
//    
//
//    sf::Texture play = getTextures()["play.png"];
//    sf::Texture change_bg = getTextures()["change_bg.png"];
//
//    
//}

void StartScreen::initializeComponents(sf::Vector2u& windowSize) {

    float buttonWidthFactor = 0.3f;
    float buttonWidth = windowSize.x * buttonWidthFactor;

    sf::Texture change_bg = getTextures()["changebg.png"];

    getBgSprite().setTexture(getTextures()["bg.png"]);
    playButton.setTexture(getTextures()["play.png"]);
    exitButton.setTexture(getTextures()["exit.png"]);
    changeBgButton.setTexture(getTextures()["changebg.png"]);
   /* changeBgButton.setTexture(change_bg);*/

    float buttonHeight = buttonWidth * (getTextures()["play.png"].getSize().y / static_cast<float>(getTextures()["play.png"].getSize().x));
    playButton.setScale(buttonWidth / getTextures()["play.png"].getSize().x, buttonHeight / getTextures()["play.png"].getSize().y);
    exitButton.setScale(playButton.getScale());

    float cbButtonWidth = buttonWidth;
    float cbButtonHeight = cbButtonWidth * change_bg.getSize().y / static_cast<float>(change_bg.getSize().x);
    changeBgButton.setScale(cbButtonWidth / change_bg.getSize().x, cbButtonHeight / change_bg.getSize().y);

    float horizontalSpacing = windowSize.x * 0.05f;
    float buttonY = windowSize.y * 0.5f;

    float playButtonX = (windowSize.x / 2.0f) - buttonWidth - (horizontalSpacing / 2.0f);
    float exitButtonX = (windowSize.x / 2.0f) + (horizontalSpacing / 2.0f);

    playButton.setPosition(playButtonX, buttonY - (buttonHeight / 2.0f));
    exitButton.setPosition(exitButtonX, buttonY - (buttonHeight / 2.0f));
    //bg change button 
    float cbButtonX = (windowSize.x / 2.0f) - (cbButtonWidth / 2.0f);
    float cbButtonY = buttonY + buttonHeight + (windowSize.y * 0.05f);
    changeBgButton.setPosition(cbButtonX, cbButtonY);

    
}

void StartScreen::handleInput(sf::RenderWindow& wind, Game& game) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            if (game.getCurrentState() != 1) {
                game.setCurrentState(1);
            }
        }
        else if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            if (game.getCurrentState() != -1) {
                game.setCurrentState(-1);
                wind.close();
            }
        }
        ////////////// ADD HERE THE LOGIC OF CHANGE BACKGROUND THE STATE CHANGES TO 2 /////////////////////////
    }
}

void StartScreen::renderScreen(sf::RenderWindow& window) {
    
    /*updateButtonPositions(window.getSize());*/
    
    /*sf::RectangleShape rect(sf::Vector2f(200, 100));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(300, 250);

    window.draw(rect);*/
   


    window.draw(getBgSprite());
    window.draw(playButton);
    window.draw(exitButton);
    window.draw(changeBgButton);

}

