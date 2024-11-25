#ifndef CHARACTERSELECTWINDOW_H
#define CHARACTERSELECTWINDOW_H

#include "baseWindow.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class CharacterSelectWindow : public BaseWindow {

private:
	sf::Sprite selectedCharacterSprite; // Full image of the selected character
	sf::Text characterDetailsText;      // Text to show character details
	sf::RectangleShape selectButton;    // Button for final selection
	int PORTRAIT_WIDTH;
	int PORTRAIT_HEIGHT;
	int INTRO_WIDTH;
	int INTRO_HEIGHT;
	bool isCharacterSelected = false;   // Tracks whether a character is selected
	/*std::map<int, sf::Sprite> characterList;*/
	sf::Text gameNameText;
	sf::Text gameNameTestBg;
	std::map<int, sf::Sprite> characterList;
	std::map<int, sf::Sprite> character;
	sf::RectangleShape bgCharacters;

public:
	/*CharacterSelectWindow();*/
	CharacterSelectWindow(sf::Vector2u& windowSize);
	~CharacterSelectWindow();
	void operator=(const CharacterSelectWindow*);

	// populates textures with character introduction pngs
	void initializeComponents(sf::Vector2u&, int) override;
	void renderScreen(sf::RenderWindow&) override;


	// Handle mouse and keyboard input
	int handleInput(sf::RenderWindow&) override; 


 
    sf::Sprite selectButtonSprite;           
    sf::Texture selectButtonTexture;         

    sf::SoundBuffer clickBuffer;             // click sound
    sf::Sound clickSound;                    // Click sound
        
};

#endif 