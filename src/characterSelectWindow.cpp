#include "characterSelectWindow.h"

#include <filesystem>
#include <iostream>
#include <string>



CharacterSelectWindow::CharacterSelectWindow(sf::Vector2u& windowSize) {


    // populate textures map
    loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\characterIntroPortraits");
    loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\characterIntros");

    p1 = new Player(100, 10, 20, "danaerys", 0, 0);
    p2 = new Player(100, 10, 20, "danaerys", 0, 1);

    // populates characterlist
   /* initializeComponents(windowSize);*/
    std::string clickSoundPath = std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\sounds\\click.wav";
    if (!clickBuffer.loadFromFile(clickSoundPath)) {
        std::cerr << "Error: Unable to load click sound!" << std::endl;
    }
    clickSound.setBuffer(clickBuffer);

    // set as active by default
    changeActiveStatus(0);
    INTRO_WIDTH = 180;
    INTRO_HEIGHT = 300;
    PORTRAIT_WIDTH = 80;
    PORTRAIT_HEIGHT = 100;

}

void CharacterSelectWindow::initializeComponents(sf::Vector2u&, int playerSelected, int pl2) {
    p1->changeDirection();
    p1->changeDirection();
    p2->changeDirection();


    setSelectedPlayerId1(playerSelected);
    setSelectedPlayerId2(pl2);
    int characterId = 0;
    int characterIntroId = 0;

    for (const auto& [filename, texture] : getTextures()) {
        sf::Sprite sprite;
        sf::Sprite sprite2;
        sprite.setTexture(texture);
        sprite2.setTexture(texture);

        if (filename.find("Portrait") != std::string::npos) {
            float scaleX = static_cast<float>(PORTRAIT_WIDTH) / texture.getSize().x;
            float scaleY = static_cast<float>(PORTRAIT_HEIGHT) / texture.getSize().y;
            sprite.setScale(scaleX, scaleY);
            sprite2.setScale(scaleX, scaleY);

            sprite.setPosition(
                (characterIntroId % 5) * (PORTRAIT_WIDTH + 10) + 500,
                (characterIntroId / 5) * (PORTRAIT_HEIGHT + 10) + 50);
            sprite2.setPosition(
                (characterIntroId % 5) * (PORTRAIT_WIDTH + 10) + 500,
                (characterIntroId / 5) * (PORTRAIT_HEIGHT + 10) + 50);

            
            characterList[characterIntroId] = sprite;
            characterList2[characterIntroId] = sprite2;
            characterIntroId++;
        }
        /*else {
            float scaleX = static_cast<float>(INTRO_WIDTH) / texture.getSize().x;
            float scaleY = static_cast<float>(INTRO_HEIGHT) / texture.getSize().y;
            sprite.setScale(scaleX, scaleY);

            sprite.setPosition(5, 20);
            character[characterId++] = sprite;
        }*/
    }

    if (!selectButtonTexture.loadFromFile(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\characterIntros\\sel.png")) {
        std::cerr << "Error: Unable to load sel.png!" << std::endl;
    }
    else {
        selectButtonSprite.setTexture(selectButtonTexture);
        sf::Vector2f desiredSize(150.0f, 50.0f);
        float scaleX = desiredSize.x / selectButtonTexture.getSize().x;
        float scaleY = desiredSize.y / selectButtonTexture.getSize().y;
        float scale = std::min(scaleX, scaleY); // aspect ratio
        selectButtonSprite.setScale(scale, scale);

        selectButtonSprite.setPosition(600, 400);
    }


    characterDetailsText.setFont(getFont());
    characterDetailsText.setCharacterSize(20);
    characterDetailsText.setFillColor(sf::Color::White);
    characterDetailsText.setPosition(50, 300);

    // background
    bgCharacters.setSize(sf::Vector2f(INTRO_WIDTH + 2.0f, INTRO_HEIGHT + 2.0f));
    bgCharacters.setFillColor(sf::Color::White);
    bgCharacters.setPosition(5, 20);
}

void CharacterSelectWindow::renderScreen(sf::RenderWindow& wind) {
    wind.clear(sf::Color::Black);
    
    p1->animate(false, selectedCharacter1, 6, 2); // idle
    p2->animate(false, selectedCharacter2, 6, 2); // idle

    wind.draw(p1->getSprite());
    wind.draw(p2->getSprite());

    const int portraitsPerRow = 5;
    const float marginX = 20.0f;
    const float marginY = 20.0f;
    const float startX = 50.0f;
    const float startY = 50.0f;

    for (auto& [characterIntroId, sprite] : characterList) {
        int row = characterIntroId / portraitsPerRow;
        int col = characterIntroId % portraitsPerRow;

        sf::RectangleShape bgPortraits;
        bgPortraits.setSize(sf::Vector2f(PORTRAIT_WIDTH + 10.0f, PORTRAIT_HEIGHT + 10.0f));
        bgPortraits.setFillColor(sf::Color(50, 50, 50));
        bgPortraits.setPosition(startX + col * (PORTRAIT_WIDTH + marginX), startY + row * (PORTRAIT_HEIGHT + marginY));

        wind.draw(bgPortraits);
        sprite.setPosition(
            startX + col * (PORTRAIT_WIDTH + marginX) + 5.0f,
            startY + row * (PORTRAIT_HEIGHT + marginY) + 5.0f);
        wind.draw(sprite);
    }

    for (auto& [characterIntroId, sprite] : characterList2) {
        int row = characterIntroId / portraitsPerRow;
        int col = characterIntroId % portraitsPerRow;

        sf::RectangleShape bgPortraits;
        bgPortraits.setSize(sf::Vector2f(PORTRAIT_WIDTH + 10.0f, PORTRAIT_HEIGHT + 10.0f));
        bgPortraits.setFillColor(sf::Color(50, 50, 50));
        bgPortraits.setPosition(startX+400 + col * (PORTRAIT_WIDTH + marginX), startY + row * (PORTRAIT_HEIGHT + marginY));

        wind.draw(bgPortraits);
        sprite.setPosition(
            startX+400 + col * (PORTRAIT_WIDTH + marginX) + 5.0f,
            startY + row * (PORTRAIT_HEIGHT + marginY) + 5.0f);
        wind.draw(sprite);
    }



    //  "Select" button
    wind.draw(selectButtonSprite);
}

int CharacterSelectWindow::handleInput(sf::RenderWindow& wind) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(wind);
    std::vector<std::string> chars = { "brienne", "danaerys", "jonsnow" };

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (auto& [characterId, sprite] : characterList) {
            if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                setSelectedPlayerId1(characterId);

                p1->setSelectedCharacter(chars[characterId]);

                characterDetailsText.setString(
                    "Character Name: Character " + std::to_string(characterId) +
                    "\nStats: Strength 10, Speed 8");
                break;
            }
        }
        for (auto& [characterId, sprite] : characterList2) {
            if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                setSelectedPlayerId2(characterId);
                p2->setSelectedCharacter(chars[characterId]);

                characterDetailsText.setString(
                    "Character Name: Character " + std::to_string(characterId) +
                    "\nStats: Strength 10, Speed 8");
                break;
            }
        }


        // Check if "Select" button is clicked
        if (selectButtonSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return 1;
        }
    }
    return 0;
}

void CharacterSelectWindow::operator=(const CharacterSelectWindow* other) {
    this->selectedPlayerId1 = other->selectedPlayerId1;
    this->selectedPlayerId2 = other->selectedPlayerId2;
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
    delete p1;
    delete p2;
}