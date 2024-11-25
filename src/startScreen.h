#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "baseWindow.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // For sound and music
#include <string>
#include <map>

class StartScreen : public BaseWindow {
public:
    /*StartScreen();*/
    StartScreen(sf::Vector2u& windowSize);
    void initializeComponents(sf::Vector2u&, int) override;
    void renderScreen(sf::RenderWindow& window) override;
    int handleInput(sf::RenderWindow&) override;
    void operator=(const StartScreen*);

private:
    // UI elements
    sf::Sprite playButton;
    sf::Sprite exitButton;
    sf::Sprite changeBgButton;
    std::map<int, sf::Sprite> spriteList;

    // Sound-related members
    sf::SoundBuffer clickSoundBuffer;   
    sf::Sound clickSound;              
    sf::Music backgroundMusic;         
    /*void loadAudio(); */

};

#endif
