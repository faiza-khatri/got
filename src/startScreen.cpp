#include "startScreen.h"
#include <iostream>
#include <filesystem>


StartScreen::StartScreen(sf::Vector2u& windowSize) {
    loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\start_scrn");
    changeActiveStatus(0);
}

void StartScreen::initializeComponents(sf::Vector2u& windowSize, int playerSelected, int pl2) {
    float buttonWidthFactor = 0.3f;
    float buttonWidth = windowSize.x * buttonWidthFactor;

    sf::Texture change_bg = getTextures()["changebg.png"];

    getBgSprite().setTexture(getTextures()["bg.png"]);
    playButton.setTexture(getTextures()["play.png"]);
    exitButton.setTexture(getTextures()["exit.png"]);
    changeBgButton.setTexture(getTextures()["changebg.png"]);

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

    float cbButtonX = (windowSize.x / 2.0f) - (cbButtonWidth / 2.0f);
    float cbButtonY = buttonY + buttonHeight + (windowSize.y * 0.05f);
    changeBgButton.setPosition(cbButtonX, cbButtonY);

    std::string soundPath = std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\sounds\\";


    if (!backgroundMusic.openFromFile(soundPath + "gamemusic.wav")) {
        std::cerr << "Error: Could not load gamemusic.wav\n";
    }
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

    // Load click sound buffer
    if (!clickSoundBuffer.loadFromFile(soundPath + "click.wav")) {
        std::cerr << "Error: Could not load click.wav\n";
    }
    clickSound.setBuffer(clickSoundBuffer);
}

int StartScreen::handleInput(sf::RenderWindow& wind) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        clickSound.play();
        if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return 1;
        }
        else if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            backgroundMusic.stop();
            wind.close();
        }

    }
    return 0;
}

void StartScreen::renderScreen(sf::RenderWindow& window) {

    window.draw(getBgSprite());
    window.draw(playButton);
    window.draw(exitButton);
    window.draw(changeBgButton);
}


void StartScreen::operator=(const StartScreen* other) {
    playButton = other->playButton;
    exitButton = other->exitButton;
    changeBgButton = other->changeBgButton;
    spriteList = other->spriteList;
}