//#include "GameOverWindow.h"
//#include <filesystem>
//#include <iostream>
//
//GameOverWindow::GameOverWindow(sf::Vector2u& windowSize) : BaseWindow() {
//    // Load textures and sounds
//    std::string basePath = std::filesystem::current_path().parent_path().string();
//    std::string imagesPath = basePath + "\\pngImages\\gameOver";
//    std::string soundsPath = basePath + "\\sounds";
//
//    // Load background texture
//    if (!gameOverTexture.loadFromFile(imagesPath + "\\gameover.png")) {
//        std::cerr << "Error: Unable to load game over image!" << std::endl;
//    }
//    gameOverSprite.setTexture(gameOverTexture);
//
//    // Scale background to fit the window
//    float scaleX = static_cast<float>(windowSize.x) / gameOverTexture.getSize().x;
//    float scaleY = static_cast<float>(windowSize.y) / gameOverTexture.getSize().y;
//    gameOverSprite.setScale(scaleX, scaleY);
//    gameOverSprite.setPosition(0, 0);
//
//    // Load "Play Again" button texture
//    if (!playAgainTexture.loadFromFile(imagesPath + "\\gobu.png")) {
//        std::cerr << "Error: Unable to load play again button texture!" << std::endl;
//    }
//    playAgainButton.setSize(sf::Vector2f(273.0f, 205.0f));
//    playAgainButton.setTexture(&playAgainTexture);
//
//    // Position the button in the center-bottom of the screen
//    playAgainButton.setPosition(
//        static_cast<float>(windowSize.x) / 2 - playAgainButton.getSize().x / 2,
//        static_cast<float>(windowSize.y) * 0.75f - playAgainButton.getSize().y / 2
//    );
//
//    // Load click sound
//    if (!clickBuffer.loadFromFile(soundsPath + "\\click.wav")) {
//        std::cerr << "Error: Unable to load click sound!" << std::endl;
//    }
//    clickSound.setBuffer(clickBuffer);
//}
//
//void GameOverWindow::initializeComponents(sf::Vector2u& windowSize) {
//    // This function can remain empty if initialization is already handled in the constructor
//}
//
//void GameOverWindow::renderScreen(sf::RenderWindow& wind) {
//    // Clear the screen and draw the Game Over screen
//    wind.clear(sf::Color::Black);
//    wind.draw(gameOverSprite);
//    wind.draw(playAgainButton);
//}
//
//int GameOverWindow::handleInput(sf::RenderWindow& wind, Game& game) {
//    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);
//
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//        if (playAgainButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
//            clickSound.play();  // Play click sound
//
//            // Reset game state
//            game.setCurrentState(0);  // Set state to start screen
//        }
//    }
//    return 0;
//}
//
//GameOverWindow::~GameOverWindow() {
//}
