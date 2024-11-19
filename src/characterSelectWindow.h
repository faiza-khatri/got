#ifndef CHARACTER_SELECT_WINDOW
#define CHARACTER_SELECT_WINDOW

#include "baseWindow.h"


#include <string>
#include <map>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>


// character selection window and other initial operations
class CharacterSelectWindow : public BaseWindow {
private:
	unsigned int selectedPlayerId;
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
	CharacterSelectWindow(sf::Vector2u& windowSize);
	~CharacterSelectWindow();

	// populates textures with character introduction pngs
	void initializeComponents(sf::Vector2u&) override;
	void renderScreen(sf::RenderWindow&) override;

	//// populate characterList with sprites
	//void initialize();

	/*void updateGraphics();*/

	// Handle mouse and keyboard input
	void handleInput(sf::RenderWindow&, Game&); 

	//// Draw the selected character details
	//void drawDetails(); 


};



#endif
