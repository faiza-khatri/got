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

#include "game.h"

// Abstract class representing all windows of the game
// inherits from RenderWinow, adds extra features

class BaseWindow {
public:
	// pure virtual function to load textures
	void loadTextures(std::string&);

	virtual void initializeComponents(sf::Vector2u&) = 0;

	virtual void renderScreen(sf::RenderWindow&) = 0;         

	// returns the texture given filename of the texture
	sf::Texture& getTextures(std::string&);

	// getters
	sf::Sprite& getBgSprite();
	sf::Font& getFont();
	std::map<std::string, sf::Texture>& getTextures();

	// setters
	void setBgSprite(const sf::Sprite&);
	void setFont(const sf::Font&);
	void setTextures(const std::map<std::string, sf::Texture>&);
	void setTextureElement(const std::string&, const sf::Texture&);

private:
	sf::Sprite bgSprite;
	sf::Font font;
	std::map<std::string, sf::Texture> textures;

};



#endif