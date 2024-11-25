#ifndef CHARACTERSELECTWINDOW_H
#define CHARACTERSELECTWINDOW_H

#include "baseWindow.h"
#include "game.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class CharacterSelectWindow : public BaseWindow {
public:
    CharacterSelectWindow(sf::Vector2u& windowSize);
    ~CharacterSelectWindow();

    void renderScreen(sf::RenderWindow& wind) override;
    void handleInput(sf::RenderWindow&, Game&);

private:
    void initializeComponents(sf::Vector2u& windowSize);

    std::map<int, sf::Sprite> characterList; 
    std::map<int, sf::Sprite> character;     

    int selectedPlayerId;
    bool isCharacterSelected = false;

    sf::Sprite selectedCharacterSprite;   
    sf::Text characterDetailsText;       

   /* sf::RectangleShape selectButton;    */    
    sf::Sprite selectButtonSprite;           
    sf::Texture selectButtonTexture;         

    sf::SoundBuffer clickBuffer;             // click sound
    sf::Sound clickSound;                    // Click sound

    float INTRO_WIDTH, INTRO_HEIGHT;
    float PORTRAIT_WIDTH, PORTRAIT_HEIGHT;

    sf::RectangleShape bgCharacters;         
};

#endif 