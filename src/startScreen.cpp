#include "startScreen.h"
#include <iostream>

StartScreen::StartScreen() {
}

void StartScreen::loadTextures() {
    sf::Texture playTexture, exitTexture, cbTexture, bgTexture;

    if (!playTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\play.png") ||
        !exitTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\exit.png") ||
        !cbTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\changebg.png") ||
        !bgTexture.loadFromFile("C:\\Users\\hp\\Desktop\\HABIB\\oopClonedTemplate\\got\\pngImages\\start_scrn\\bg.png")) {
        std::cerr << "Error loading textures" << std::endl;
        return;
    }

    setTextureElement("play", playTexture);
    setTextureElement("exit", exitTexture);
    setTextureElement("change_bg", cbTexture);
    setTextureElement("background", bgTexture);
}

void StartScreen::updateButtonPositions(sf::Vector2u windowSize, sf::Sprite& playButton, sf::Sprite& exitButton, sf::Sprite& cbButton) {
    float buttonWidthFactor = 0.3f;
    float buttonWidth = windowSize.x * buttonWidthFactor;
    float buttonHeight = buttonWidth * (getTextures("play").getSize().y / static_cast<float>(getTextures("play").getSize().x));

    playButton.setScale(buttonWidth / getTextures("play").getSize().x, buttonHeight / getTextures("play").getSize().y);
    exitButton.setScale(playButton.getScale());

    float cbButtonWidth = buttonWidth;
    float cbButtonHeight = cbButtonWidth * (getTextures("change_bg").getSize().y / static_cast<float>(getTextures("change_bg").getSize().x));
    cbButton.setScale(cbButtonWidth / getTextures("change_bg").getSize().x, cbButtonHeight / getTextures("change_bg").getSize().y);

    float horizontalSpacing = windowSize.x * 0.05f;
    float buttonY = windowSize.y * 0.5f;

    float playButtonX = (windowSize.x / 2.0f) - buttonWidth - (horizontalSpacing / 2.0f);
    float exitButtonX = (windowSize.x / 2.0f) + (horizontalSpacing / 2.0f);

    playButton.setPosition(playButtonX, buttonY - (buttonHeight / 2.0f));
    exitButton.setPosition(exitButtonX, buttonY - (buttonHeight / 2.0f));

    // Position the Change Background button below the others
    float cbButtonX = (windowSize.x / 2.0f) - (cbButtonWidth / 2.0f);
    float cbButtonY = buttonY + buttonHeight + (windowSize.y * 0.05f);
    cbButton.setPosition(cbButtonX, cbButtonY);
}

void StartScreen::setupScreen(sf::RenderWindow& window) {
    sf::Sprite bgSprite(getTextures("background"));
    setBgSprite(bgSprite);

    sf::Sprite playButton(getTextures("play"));
    sf::Sprite exitButton(getTextures("exit"));
    sf::Sprite changeBgButton(getTextures("change_bg"));

    updateButtonPositions(window.getSize(), playButton, exitButton, changeBgButton);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized) {
                sf::Vector2u newSize(event.size.width, event.size.height);
                updateButtonPositions(newSize, playButton, exitButton, changeBgButton);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        std::cout << "Play button clicked. Starting the game!" << std::endl;
                    }
                    if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        std::cout << "Exit button clicked. Exiting the game!" << std::endl;
                        window.close();
                    }
                    if (changeBgButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        std::cout << "Change Background button clicked. Changing the background!" << std::endl;
                    }
                }
            }
        }

        window.clear();
        window.draw(bgSprite);
        window.draw(playButton);
        window.draw(exitButton);
        window.draw(changeBgButton);
        window.display();
    }
}
