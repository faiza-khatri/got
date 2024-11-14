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

class BaseWindow : public sf::RenderWindow {
public:
	// pure virtual function to load textures
	virtual void loadTextures() = 0;

	// returns the texture given filename of the texture
	sf::Texture& getTexture(std::string const&);

	// getters
	sf::Sprite& getBgSprite();
	sf::Font& getFont();
	std::map<std::string, sf::Texture>& getTextures();

	// setters
	void setBgSprite(const sf::Sprite&);
	void setFont(const sf::Font&);
	void setTextures(const std::map<std::string, sf::Texture>&);

private:
	sf::Sprite bgSprite;
	sf::Font font;
	std::map<std::string, sf::Texture> textures;

};



#endif