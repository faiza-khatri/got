#include "characterSelectWindow.h"

#include <filesystem>
#include <iostream>
#include <map>
#include <string>



CharacterSelectWindow::CharacterSelectWindow(sf::Vector2u& windowSize) {
    

    // populate textures map
    loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\characterIntroPortraits");
    loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\characterIntros");

    // populates characterlist
   /* initializeComponents(windowSize);*/

    // set as active by default
    changeActiveStatus(0); 
    INTRO_WIDTH = 180;
    INTRO_HEIGHT = 300;
    
    
    PORTRAIT_WIDTH = 80;
    PORTRAIT_HEIGHT = 100;
    
}

void CharacterSelectWindow::initializeComponents(sf::Vector2u&, int playerSelected) {
    setSelectedPlayerId(playerSelected);
    int characterId = 0;
    int characterIntroId = 0;

    for (const auto& [filename, texture] : getTextures()) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        if (filename.find("Portrait") != std::string::npos) {
            float scaleX = static_cast<float>(PORTRAIT_WIDTH) / texture.getSize().x;
            float scaleY = static_cast<float>(PORTRAIT_HEIGHT) / texture.getSize().y;
            sprite.setScale(scaleX, scaleY);

            sprite.setPosition((characterIntroId % 5) * (PORTRAIT_WIDTH + 10) + 500,
                (characterIntroId / 5) * (PORTRAIT_HEIGHT + 10) + 50);

            characterList[characterIntroId++] = sprite;
            std::cout << "Added sprite: " << characterIntroId << std::endl;
        }
        else {
            float scaleX = static_cast<float>(INTRO_WIDTH) / texture.getSize().x;
            float scaleY = static_cast<float>(INTRO_HEIGHT) / texture.getSize().y;
            sprite.setScale(scaleX, scaleY);
            sprite.setPosition(5, 20);

            character[characterId++] = sprite;
            std::cout << "Added sprite: " << characterId << std::endl;
        }
    };


    // Configure select button
    selectButton.setSize({ 150.0f, 50.0f });
    selectButton.setFillColor(sf::Color::Blue);
    selectButton.setPosition(600, 400);

    characterDetailsText.setFont(getFont());
    characterDetailsText.setCharacterSize(20);
    characterDetailsText.setFillColor(sf::Color::White);
    characterDetailsText.setPosition(50, 300);

    bgCharacters.setSize(sf::Vector2f(INTRO_WIDTH + 2.0f, INTRO_HEIGHT + 2.0f));
    bgCharacters.setFillColor(sf::Color::White);
    bgCharacters.setPosition(5, 20);
}

void CharacterSelectWindow::renderScreen(sf::RenderWindow& wind) {
    wind.clear(sf::Color::Black);

    const int portraitsPerRow = 5;  // Number of portraits per row
    const float marginX = 20.0f;    // Horizontal margin between portraits
    const float marginY = 20.0f;    // Vertical margin between portraits
    const float startX = 100.0f;    // Starting X position for the grid
    const float startY = 50.0f;     // Starting Y position for the grid

    // Draw all portraits
    for (auto& [characterIntroId, sprite] : characterList) {
        int row = characterIntroId / portraitsPerRow;  // Calculate row
        int col = characterIntroId % portraitsPerRow;  // Calculate column

        sf::RectangleShape bgPortraits;
        bgPortraits.setSize(sf::Vector2f(PORTRAIT_WIDTH + 10.0f, PORTRAIT_HEIGHT + 10.0f));  // Background size with padding
        bgPortraits.setFillColor(sf::Color(50, 50, 50));  // Set the background color (adjustable)
        bgPortraits.setPosition(startX + col * (PORTRAIT_WIDTH + marginX), startY + row * (PORTRAIT_HEIGHT + marginY));

        // Draw the portrait background
        wind.draw(bgPortraits);
        sprite.setPosition(startX + col * (PORTRAIT_WIDTH + marginX) + 5.0f,  // Offset by 5px to center
            startY + row * (PORTRAIT_HEIGHT + marginY) + 5.0f);
        wind.draw(sprite);
        /*draw(bgPortraits);*/
    }

    // Draw details of the selected character
    if (isCharacterSelected) {
        // Draw selected character sprite in the center (or any position)
        sf::RectangleShape bgSelectedCharacter;
        bgSelectedCharacter.setSize(sf::Vector2f(INTRO_WIDTH + 20.0f, INTRO_HEIGHT + 20.0f));  // Add padding around the character
        bgSelectedCharacter.setFillColor(sf::Color(60, 60, 60));  // Adjust the background color
        bgSelectedCharacter.setPosition(300.0f, 200.0f);  // Position of the selected character

        // Draw the background behind the selected character
        wind.draw(bgSelectedCharacter);

        // Position and draw the selected character sprite
        selectedCharacterSprite.setPosition(310.0f, 210.0f);  // Slightly offset to fit within background box
        wind.draw(selectedCharacterSprite);

        wind.draw(characterDetailsText);
    }

    // Draw the "Select" button
    wind.draw(selectButton);
}

int CharacterSelectWindow::handleInput(sf::RenderWindow& wind) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (auto& [characterId, sprite] : characterList) {
            if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                setSelectedPlayerId(characterId);
                selectedCharacterSprite = character[characterId];
                isCharacterSelected = true;

                // Set character details text
                characterDetailsText.setString("Character Name: Character " + std::to_string(characterId) +
                    "\nStats: Strength 10, Speed 8");
                break;
            }
        }

        // Check if "Select" button is clicked
        if (selectButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            /*if (game.getCurrentState() != 2) {
                game.setCurrentState(2);
                std::string arr[] = { "brienne","danaerys", "jonsnow"};
                std::cout << "selectedPlayerId" << selectedPlayerId << std::endl;
                game.setPlayerSelected(arr[selectedPlayerId]);
            }*/
            return 1;
        }
    }
    return 0;
}

void CharacterSelectWindow::operator=(const CharacterSelectWindow* other) {
    this->selectedPlayerId = other->selectedPlayerId;
    this->selectedCharacterSprite = other->selectedCharacterSprite;
    this->characterDetailsText = other->characterDetailsText;      // Text to show character details
    this->selectButton = other->selectButton;    // Button for final selection
    this->PORTRAIT_WIDTH = other->PORTRAIT_WIDTH;
    this->PORTRAIT_HEIGHT = other->PORTRAIT_HEIGHT;
    this->INTRO_WIDTH = other->INTRO_WIDTH;
    this->INTRO_HEIGHT = other->INTRO_HEIGHT;
    this->isCharacterSelected = other->isCharacterSelected;   // Tracks whether a character is selected
    this->gameNameText = other->gameNameText;
    this->gameNameTestBg = other->gameNameTestBg;
    this->characterList = other->characterList;
    this->character = other->character;
    this->bgCharacters = other->bgCharacters;
}

CharacterSelectWindow::~CharacterSelectWindow() {

}