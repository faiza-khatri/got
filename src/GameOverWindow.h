#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include "baseWindow.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameOverWindow : public BaseWindow {
public:
    GameOverWindow(sf::Vector2u& windowSize);  // Constructor to initialize window size
    ~GameOverWindow();  // Destructor

    void renderScreen(sf::RenderWindow& wind) override;  // Render the game over screen
    void handleInput(sf::RenderWindow& wind, Game& game);  // Handle input for the "Play Again" button

private:
    void initializeComponents(sf::Vector2u& windowSize);  // Initialize components (textures, button, etc.)

    sf::Sprite gameOverSprite;  // Sprite for Game Over image
    sf::RectangleShape playAgainButton;  // Shape for Play Again button
    sf::Texture gameOverTexture;  // Texture for the Game Over image
    sf::Texture playAgainTexture;  // Texture for Play Again button
    sf::SoundBuffer clickBuffer;  // Sound buffer for button click
    sf::Sound clickSound;         // Sound for button click
};

#endif // GAMEOVERWINDOW_H
