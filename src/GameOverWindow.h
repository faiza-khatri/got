#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include "baseWindow.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameOverWindow : public BaseWindow {
public:
    GameOverWindow(sf::Vector2u& windowSize);  
    ~GameOverWindow(); 

    void renderScreen(sf::RenderWindow& wind) ;  
    void handleInput(sf::RenderWindow& wind, Game& game);  

private:
    void initializeComponents(sf::Vector2u& windowSize); 

    sf::Sprite gameOverSprite;  
    sf::RectangleShape playAgainButton; 
    sf::Texture gameOverTexture;  
    sf::Texture playAgainTexture;  
    sf::SoundBuffer clickBuffer;  
    sf::Sound clickSound;        
};

#endif // GAMEOVERWINDOW_H
