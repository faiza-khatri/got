#ifndef GAME_GUI
#define GAME_GUI

#include <string>
#include <vector>
#include <map>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

// Abstract class representing all windows of the game
// inherits from RenderWinow, adds extra features

class BaseWindow {
public:
	// pure virtual function to load textures
	void loadTextures(std::string&);

	virtual void initializeComponents(sf::Vector2u&, int playerSelected, int) = 0;
	virtual int handleInput(sf::RenderWindow&) = 0;
	virtual void renderScreen(sf::RenderWindow&) = 0;         

	// returns the texture given filename of the texture
	sf::Texture& getTextures(std::string&);

	/*virtual void operator=(const BaseWindow*) = 0;*/

	void changeActiveStatus(bool);
	void setSelectedPlayerId1(int);
	int getSelectedPlayerId1();
	void setSelectedPlayerId2(int);
	int getSelectedPlayerId2();

	// getters
	sf::Sprite& getBgSprite();
	sf::Font& getFont();
	std::map<std::string, sf::Texture>& getTextures();
	bool getActiveStatus();
	int selectedPlayerId1 = 1;
	int selectedPlayerId2 = 1;
	

	// setters
	void setBgSprite(const sf::Sprite&);
	void setFont(const sf::Font&);
	void setTextures(const std::map<std::string, sf::Texture>&);
	void setTextureElement(const std::string&, const sf::Texture&);
	


private:
	sf::Sprite bgSprite;
	sf::Font font;
	std::map<std::string, sf::Texture> textures;
	bool active = 0;

};



#endif