#include "baseWindow.h"
#include <iostream>
#include <filesystem>

// Function to load textures from a specified directory
void BaseWindow::loadTextures( std::string& folderPath) {
    int i = 0;
    try {
        for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".png") {
                sf::Texture texture;
                if (texture.loadFromFile(entry.path().string())) {
                    setTextureElement(entry.path().filename().string(), texture);
                    std::cout << "Loaded texture: " << entry.path().filename().string() << std::endl;
                }
                else {
                    std::cerr << "Failed to load texture: " << entry.path().filename().string() << std::endl;
                }
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
}

// Getter function to retrieve a texture by filename
sf::Texture& BaseWindow::getTextures(const std::string& fileName) {
    return textures[fileName]; // Returns the texture by filename from the map
}

// Setter functions
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

// Getter functions
sf::Sprite& BaseWindow::getBgSprite() {
    return bgSprite;
}

sf::Font& BaseWindow::getFont() {
    return font;
}

std::map<std::string, sf::Texture>& BaseWindow::getTextures() {
    return textures;
}

bool BaseWindow::getActiveStatus() {
    return active;
}

void BaseWindow::changeActiveStatus(bool act) {
    active = act;
}

void BaseWindow::setSelectedPlayerId(int pl) {
    selectedPlayerId = pl;
}

int BaseWindow::getSelectedPlayerId() {
    return selectedPlayerId;
}
