#include "gameEndScreen.h"

#include <filesystem>
#include <iostream>


EndScreen::EndScreen(sf::Vector2u& windowSize, bool won) {
	loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\end_scrn");
	changeActiveStatus(0);
	std::cout << "Player won: " << won << std::endl;
}

void EndScreen::initializeComponents(sf::Vector2u& windowSize, int playerSelected) {
    if (!gameOverTexture.loadFromFile(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\end_scrn\\gameover.png")) {
        std::cerr << "Error: Unable to load game over image!" << std::endl;
    }
    gameOverSprite.setTexture(gameOverTexture);

    float scaleX = static_cast<float>(windowSize.x) / gameOverTexture.getSize().x;
    float scaleY = static_cast<float>(windowSize.y) / gameOverTexture.getSize().y;
    gameOverSprite.setScale(scaleX, scaleY);
    gameOverSprite.setPosition(0, 0);

    // play again button
    if (!playAgainTexture.loadFromFile(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\end_scrn\\gobu.png")) {
        std::cerr << "Error: Unable to load play again button texture!" << std::endl;
    }
    playAgainButton.setSize(sf::Vector2f(273.0f, 205.0f));
    playAgainButton.setTexture(&playAgainTexture);

    playAgainButton.setPosition(
        static_cast<float>(windowSize.x) / 2 - 273.0f / 2,
        static_cast<float>(windowSize.y) * 0.75f - 205.0f / 2
    );

}

void EndScreen::renderScreen(sf::RenderWindow& wind) {
    wind.draw(gameOverSprite);
    wind.draw(playAgainButton);
}

int EndScreen::handleInput(sf::RenderWindow& wind) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (playAgainButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            clickSound.play();  //  click sound
            return 1;
        }
    }
    return 0;

}