#include "gameEndScreen.h"

#include <filesystem>
#include <iostream>

EndScreen::EndScreen(sf::Vector2u& windowSize, bool wn) {
    // set won variable
    this->won = wn ? 1 : 0;
    changeActiveStatus(0);

    std::cout << "Player won: " << (this->won ? "Player 1" : "Player 2") << std::endl;
}

void EndScreen::initializeComponents(sf::Vector2u& windowSize, int playerSelected, int pl2) {
    // get appropriate winner image
    std::string winnerImage = this->won == 1 ? "player1win.png" : "player2win.png";
    std::string fullPath = std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\end_scrn\\" + winnerImage;

    std::cout << "Attempting to load: " << fullPath << std::endl;

    if (!youWonTexture.loadFromFile(fullPath)) {
        std::cerr << "Error: Unable to load winner image: " << winnerImage << std::endl;
    }
    youWon.setTexture(youWonTexture);

    float scaleX = static_cast<float>(windowSize.x) / youWonTexture.getSize().x;
    float scaleY = static_cast<float>(windowSize.y) / youWonTexture.getSize().y;
    youWon.setScale(scaleX, scaleY);
    youWon.setPosition(0, 0);

    std::string playAgainPath = std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\end_scrn\\gobu.png";

    if (!playAgainTexture.loadFromFile(playAgainPath)) {
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
    wind.draw(youWon);

    wind.draw(playAgainButton);
}

int EndScreen::handleInput(sf::RenderWindow& wind) {
    // play again input handle
    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (playAgainButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            clickSound.play();  
            return 1;
        }
    }
    return 0;
}
