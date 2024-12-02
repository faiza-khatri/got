#ifndef BASE_WINDOW_H
#define BASE_WINDOW_H

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

// Abstract class representing all windows of the game
// Inherits from sf::RenderWindow, adding extra features
class BaseWindow {
public:
    // Pure virtual functions to be implemented in derived classes
    virtual void initializeComponents(sf::Vector2u& windowSize, int playerSelected) = 0;
    virtual int handleInput(sf::RenderWindow& wind) = 0;
    virtual void renderScreen(sf::RenderWindow& window) = 0;
    void loadTextures(std::string&);

    // Getter function to retrieve a texture by filename
    sf::Texture& getTextures(const std::string& fileName);

    // Setters
    void setBgSprite(const sf::Sprite& newBgSprite);
    void setFont(const sf::Font& newFont);
    void setTextures(const std::map<std::string, sf::Texture>& newTextures);
    void setTextureElement(const std::string& fileName, const sf::Texture& texture);

    // Getters
    sf::Sprite& getBgSprite();
    sf::Font& getFont();
    std::map<std::string, sf::Texture>& getTextures();
    bool getActiveStatus();
    void changeActiveStatus(bool act);
    int selectedPlayerId = 1;
    void setSelectedPlayerId(int pl);
    int getSelectedPlayerId();

private:
    sf::Sprite bgSprite;
    sf::Font font;
    std::map<std::string, sf::Texture> textures;
    bool active = false;

    
};

#endif
