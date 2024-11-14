#include "baseWindow.h"

sf::Texture& BaseWindow::getTextures(std::string const& fileName) {
	return textures[fileName];
}

// setters
void BaseWindow::setBgSprite(const sf::Sprite& newBgSprite) {
    bgSprite = newBgSprite;
}

void BaseWindow::setFont(const sf::Font& newFont) {
    font = newFont;
}

void BaseWindow::setTextures(const std::map<std::string, sf::Texture>& newTextures) {
    textures = newTextures;
}

void BaseWindow::setTextureElement(const std::string& fileName, const sf::Texture& texture) {
	textures[fileName] = texture;
}

// getters
sf::Sprite& BaseWindow::getBgSprite() {
	return bgSprite;
}

sf::Font& BaseWindow::getFont() {
	return font;
}

std::map<std::string, sf::Texture>& BaseWindow::getTextures() {
	return textures;
}
