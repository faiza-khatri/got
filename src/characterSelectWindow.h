#ifndef CHARACTERSELECTWINDOW_H
#define CHARACTERSELECTWINDOW_H

#include "baseWindow.h"
#include "player.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class CharacterSelectWindow : public BaseWindow {

private:
	sf::Sprite selectedCharacterSprite; // Full image of the selected character
	sf::Sprite selectedCharacterSprite2; // Full image of the selected character
	sf::Text characterDetailsText;      // Text to show character details
	sf::RectangleShape selectButton;    // Button for final selection
	int PORTRAIT_WIDTH;
	int PORTRAIT_HEIGHT;
	int INTRO_WIDTH;
	int INTRO_HEIGHT;
	bool isCharacterSelected = false;   // Tracks whether a character is selected
	bool isCharacterSelected2 = false;
	/*std::map<int, sf::Sprite> characterList;*/
	sf::Text gameNameText;
	sf::Text gameNameTestBg;
	std::map<int, sf::Sprite> characterList;
	std::map<int, sf::Sprite> characterList2;
	std::map<int, sf::Sprite> character;
	sf::RectangleShape bgCharacters;
	Player* p1;
	Player* p2;
	std::string selectedCharacter1;
	std::string selectedCharacter2;
	

public:

	CharacterSelectWindow(sf::Vector2u& windowSize);
	~CharacterSelectWindow();
	void operator=(const CharacterSelectWindow*);

	// populates textures with character introduction pngs
	void initializeComponents(sf::Vector2u&, int, int) override;
	void renderScreen(sf::RenderWindow&) override;


	// mouse and keyboard input
	int handleInput(sf::RenderWindow&) override;



	sf::Sprite selectButtonSprite;
	sf::Texture selectButtonTexture;

	sf::SoundBuffer clickBuffer;             // click sound
	sf::Sound clickSound;                    // click sound

};

#endif 