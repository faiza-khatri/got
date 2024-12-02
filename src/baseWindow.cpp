#include "baseWindow.h"

#include <filesystem>
#include <iostream>

void BaseWindow::loadTextures(std::string& folderPath) {

    // populates texture map
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



sf::Texture& BaseWindow::getTextures(std::string& fileName) {
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

bool BaseWindow::getActiveStatus() {
    return active;
}

void BaseWindow::changeActiveStatus(bool act) {
    active = act;
}

void BaseWindow::setSelectedPlayerId1(int pl) {
    selectedPlayerId1 = pl;
}
int BaseWindow::getSelectedPlayerId1() {
    return selectedPlayerId1;
}

void BaseWindow::setSelectedPlayerId2(int pl) {
    selectedPlayerId2 = pl;
}
int BaseWindow::getSelectedPlayerId2() {
    return selectedPlayerId2;
}
