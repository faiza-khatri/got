#include "gameStartScreen.h"
#include <iostream>

GameStartScreen::GameStartScreen(sf::RenderWindow& window) : window(window) {
    // Load the background texture
    if (!backgroundTexture.loadFromFile("C:/SFML-Progs/winter.png")) {
        std::cerr << "Error loading winter.png" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Load button textures
    if (!playTexture.loadFromFile("C:/SFML-Progs/play.png") ||
        !exitTexture.loadFromFile("C:/SFML-Progs/exit.png")) {
        std::cerr << "Error loading button images" << std::endl;
    }

    // Create Play Button
    playButton.setTexture(playTexture);
    playButton.setPosition(150, 700);

    // Create Exit Button
    exitButton.setTexture(exitTexture);
    exitButton.setPosition(550, 700);
}

void GameStartScreen::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (isPlayButtonClicked(mousePos)) {
                std::cout << "Play button clicked. Starting the game!" << std::endl;
                // Start the game (replace with actual logic)
            }

            if (isExitButtonClicked(mousePos)) {
                std::cout << "Exit button clicked. Exiting the game!" << std::endl;
                window.close();
            }
        }
    }
}

void GameStartScreen::update() {
    // Any updates needed for your start screen (e.g., animations, sound, etc.)
}

void GameStartScreen::draw() {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(playButton);
    window.draw(exitButton);
    window.display();
}

bool GameStartScreen::isPlayButtonClicked(sf::Vector2i mousePos) {
    return playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

bool GameStartScreen::isExitButtonClicked(sf::Vector2i mousePos) {
    return exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
