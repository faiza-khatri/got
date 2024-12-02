#ifndef  GAME_END
#define GAME_END

#include "baseWindow.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // For sound and music

class EndScreen : public BaseWindow {
public:
    EndScreen(sf::Vector2u& windowSize, bool);
    void initializeComponents(sf::Vector2u&, int) override;
    void renderScreen(sf::RenderWindow& window) override;
    int handleInput(sf::RenderWindow&) override;
private:
    sf::Sprite gameOverSprite;
    sf::RectangleShape playAgainButton;
    sf::Texture gameOverTexture;
    sf::Texture playAgainTexture;
    sf::SoundBuffer clickBuffer;
    sf::Sound clickSound;
};




#endif