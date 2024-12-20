#include "character.h"
#include <filesystem>
#include <iostream>

void Character::loadCharVarTextures(std::string& folderPath) {

  // loads all textures of a character in an array
	// stores array in map
    try {
        std::map<std::string, std::array<sf::Texture, 8>> map;

        for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
            std::array<sf::Texture, 8> arr;
            int i = 0;
            for (const auto& subEntry : std::filesystem::directory_iterator(entry.path())) {
                sf::Texture t;
                if (!t.loadFromFile(subEntry.path().string())) {
                    std::cout << "Error loading texture: " << subEntry.path() << std::endl;
                }
                else {
                    std::cout << "Loaded texture: " << subEntry.path().filename().string() << std::endl;
                }
                arr[i] = t;
                std::cout << i << std::endl;
                i++;
            }
            map[entry.path().filename().string()] = arr;
            std::cout << "Added: " << entry.path().filename().string() << std::endl;
        }

        setCharVar(map);
    }
    catch (const std::exception& e) {
        std::cout << "Error accessing directory: " << e.what() << std::endl;
    }

}

void Character::animate(bool flip, std::string& charAnimated, int numFrames, int idx) {
    float frameDuration = 0.15f; // furation of a single frame of a single state
    int frameHeight = 128;
    int frameWidth = 128;

    elapsedTime += animationClock.restart().asSeconds(); // update time

    if (currentFrame >= numFrames) { // if finished with animation
        if (idx == 7) { // if state was death
            die();
            return; // end the animation
        }
      // go back to idle state
        sprite.setTexture(charVars[selectedCharacter][2]);
        currentFrame = 0;
        state = 0;

        stopSwordSound();
    }

  // updation of frame
    if (elapsedTime >= frameDuration) { 
        elapsedTime = 0.0f;

      	// intrect params (x offset, y offset, x width, y height)
        sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
        currentFrame = (currentFrame + 1); // go to next frame

        if (state == 1) {
            playSwordSound(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\sounds\\swordSound.wav");
        }
        if (state == 4) {
            playSwordSound(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\sounds\\swordSound.wav");
        }
        if (state == 5) {
            playSwordSound(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\sounds\\swordSound.wav");
        }
    }

}

void Character::move(int dir, Character* chr) {
  // distance = speed * time
    float speed = 900.0f;
    float deltaTime = 0.03f;
    float safetyDistance = 70.0f;

  	// calculate new position
    float newPos = sprite.getPosition().x + (dir * speed * deltaTime);
    float otherPos = chr->getSprite().getPosition().x;

  // boundary 
    sf::FloatRect bounds = sprite.getGlobalBounds();
    float halfWidth = bounds.width / 2.0f;

  	// check for no overlap between characters
    bool safeDistanceMaintained = abs(otherPos - newPos) >= safetyDistance;
    bool withinBounds = (newPos - halfWidth >= 0 && newPos + halfWidth <= 800);

  // boundary check
    if (withinBounds && safeDistanceMaintained) {
        sprite.move(dir * speed * deltaTime, 0.0f);
        std::cout << "Moved to: " << sprite.getPosition().x << std::endl;
    }
    else {
      // if should not move
        std::cout << "Movement blocked. Current position: " << sprite.getPosition().x
            << ", Other position: " << otherPos << std::endl;
    }

}

void Character::drawChar(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Character::playSwordSound(const std::string& soundFilePath) {
    static sf::SoundBuffer swordSoundBuffer;
    if (!swordSoundBuffer.loadFromFile(soundFilePath)) {
        std::cerr << "Error loading sword sound: " << soundFilePath << std::endl;
    }
    swordSound.setBuffer(swordSoundBuffer);
    swordSound.play();
}

void Character::stopSwordSound() {
    swordSound.stop();
}

void Character::setName(std::string& nme) {
    name = nme;
}

std::string& Character::getName() {
    return name;
}

void Character::setSelectedCharacter(std::string& nme) {
    selectedCharacter = nme;
}

std::string& Character::getSelectedCharacter() {
    return selectedCharacter;
}

void Character::setHealth(int hlth) {
    health = hlth;
}

int Character::getHealth() {
    return health;
}

float Character::getElapsedTime() {
    return elapsedTime;
}

void Character::setElapsedTime(float el) {
    elapsedTime = el;
}

void Character::setAttackPower(int attackPwr) {
    attackPower = attackPwr;
}

int Character::getAttackPower() {
    return attackPower;
}

void Character::setSpeed(int spd) {
    speed = spd;
}

int Character::getSpeed() {
    return speed;
}

void Character::setCurrentFrame(int frame) {
    currentFrame = frame;
}

int Character::getCurrentFrame() {
    return currentFrame;
}

void Character::setState(int st) {
    state = st;
}

int Character::getState() {
    return state;
}

void Character::setSprite(sf::Sprite& sprt) {
    sprite = sprt;
}

sf::Sprite& Character::getSprite() {
    return sprite;
}

void Character::setTexture(sf::Texture& chrTexture) {
    charTexture = chrTexture;
}

sf::Texture& Character::getTexture() {
    return charTexture;
}

sf::Clock& Character::getAnimationClock() {
    return animationClock;
}

void Character::setAnimationClock(sf::Clock& clk) {
    animationClock = clk;
}

void Character::setCharVar(std::map<std::string, std::array<sf::Texture, 8>>& map) {
    charVars = map;
}

std::map<std::string, std::array<sf::Texture, 8>>& Character::getCharVar() {
    return charVars;
}

sf::Texture& Character::getCharTexture() {
    return charTexture;
}

void Character::setCharTexture(sf::Texture& txt) {
    charTexture = txt;
}

void Character::setPosition(sf::Vector2f& pos) {
    getSprite().Sprite::setPosition(pos);
}

sf::Vector2f Character::getPosition() {
    return sprite.Sprite::getPosition();
}

bool Character::isFacingRight() {
    return facingRight;
}

void Character::setFacingRight(bool dir) {
    facingRight = dir;
}

void Character::changeDirection() {
    sprite.setOrigin({ abs(sprite.getLocalBounds().width) / 2.0f, abs(sprite.getLocalBounds().height) / 2.0f });

    facingRight = !facingRight;

    sf::Vector2f currentPosition = sprite.getPosition();
    if (facingRight) {
        sprite.setScale({ 2.0f, 2.0f });
    }
    else {
        sprite.setScale({ -2.0f, 2.0f });
        /*sprite.setOrigin({ abs(sprite.getLocalBounds().width) / 2.0f, abs(sprite.getLocalBounds().height) / 2.0f });*/
    }

    sprite.setPosition(currentPosition.x, currentPosition.y);


}

bool Character::isAlive() {
    return alive;
}
void Character::die() {
    alive = false;
}

Character::~Character() {
}