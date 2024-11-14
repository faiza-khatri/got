#include "characterSelectWindow.h"

#include <filesystem>
#include <iostream>
#include <map>
#include <string>

void CharacterSelectWindow::loadTextures() {
	std::string folderPath = "D:\\oop\\clonedTemplateOOP\\pngImages\\characterIntroPngs";
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

void CharacterSelectWindow::initialize() {
    const int PORTRAIT_WIDTH = 80;
    const int PORTRAIT_HEIGHT = 100;
    int characterId = 0;

    // populate textures map
    loadTextures();
    for (const auto& [filename, texture] : getTextures()) {
        if (filename.find("Portrait") != std::string::npos) {
            sf::Sprite sprite;
            sprite.setTexture(texture);

            float scaleX = static_cast<float>(PORTRAIT_WIDTH) / texture.getSize().x;
            float scaleY = static_cast<float>(PORTRAIT_HEIGHT) / texture.getSize().y;
            sprite.setScale(scaleX, scaleY);

            characterList[characterId++] = sprite;
            std::cout << "Added sprite: " << characterId << std::endl;
        }
    }

}

void CharacterSelectWindow::updateGraphics() {
    for (auto& [characterId, sprite] : characterList) {
        sprite.setPosition(80.5f, 90.0f);
    }
    /*clear();*/
    for (auto it = std::begin(characterList); it != std::end(characterList); ++it)
    {
        draw(it->second);
    }
    display();
}

CharacterSelectWindow::~CharacterSelectWindow() {

}