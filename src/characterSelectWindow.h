#ifndef CHARACTER_SELECT_WINDOW
#define CHARACTER_SELECT_WINDOW

#include "baseWindow.h"

#include <string>
#include <map>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// character selection window and other initial operations
class CharacterSelectWindow : public BaseWindow, public sf::RenderWindow {
private:
	unsigned int selectedPlayerId;
	unsigned int numCharacters;
	/*std::map<int, sf::Sprite> characterList;*/
	sf::Text gameNameText;
	sf::Text gameNameTestBg;
	std::map<int, sf::Sprite> characterList;

public:
	CharacterSelectWindow() : BaseWindow(), RenderWindow() {};
	~CharacterSelectWindow();

	// populates textures with character introduction pngs
	void loadTextures() override;

	// populate characterList with sprites
	void initialize();

	void updateGraphics();


};



#endif
