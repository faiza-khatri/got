#include "GameOverWindow.h"
#include <filesystem>
#include <iostream>
#include <SFML/Audio.hpp>

GameOverWindow::GameOverWindow(sf::Vector2u& windowSize) : BaseWindow() {
    loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\gameOver");
    if (!clickBuffer.loadFromFile(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\sounds\\click.wav")) {
        std::cerr << "Error: Unable to load click sound!" << std::endl;
    }
    clickSound.setBuffer(clickBuffer);

    initializeComponents(windowSize);
}

void GameOverWindow::initializeComponents(sf::Vector2u& windowSize) {
    if (!gameOverTexture.loadFromFile(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\gameOver\\gameover.png")) {
        std::cerr << "Error: Unable to load game over image!" << std::endl;
    }
    gameOverSprite.setTexture(gameOverTexture);
    float scaleX = static_cast<float>(windowSize.x) / gameOverTexture.getSize().x;
    float scaleY = static_cast<float>(windowSize.y) / gameOverTexture.getSize().y;
    gameOverSprite.setScale(scaleX, scaleY);
    gameOverSprite.setPosition(0, 0);

    // play again button
    if (!playAgainTexture.loadFromFile(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\gameOver\\gobu.png")) {
        std::cerr << "Error: Unable to load play again button texture!" << std::endl;
    }
    playAgainButton.setSize(sf::Vector2f(273.0f, 205.0f)); 
    playAgainButton.setTexture(&playAgainTexture);
    playAgainButton.setPosition(
        static_cast<float>(windowSize.x) / 2 - 273.0f / 2,
        static_cast<float>(windowSize.y) * 0.75f - 205.0f / 2
    );
}

void GameOverWindow::renderScreen(sf::RenderWindow& wind) {
    wind.clear(sf::Color::Black);
    wind.draw(gameOverSprite);
    wind.draw(playAgainButton);
}

void GameOverWindow::handleInput(sf::RenderWindow& wind, Game& game) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (playAgainButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            clickSound.play();  // click sound
            game.setCurrentState(0);  // game state to 0 Start screen 
        }
    }
}

GameOverWindow::~GameOverWindow() {
    // Cleanup if needed
}
