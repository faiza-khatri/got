#include "character.h"

#include <filesystem>
#include <iostream>

void Character::loadCharVarTextures(std::string& folderPath) {
	
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
	float frameDuration = 0.15f;
	
	int frameHeight = 128;
	int frameWidth = 128;

	elapsedTime += animationClock.restart().asSeconds();


	if (currentFrame >= numFrames) {
		if (idx == 7) {
			die();
			return;
		}
		sprite.setTexture(charVars[selectedCharacter][2]);
		currentFrame = 0;
		state = 0;
		
	}

	//float actframeWidth = facingRight ? frameWidth : -frameWidth;


	if (elapsedTime >= frameDuration) {
		/*std::cout << selectedCharacter << ": " << idx << std::endl;*/
		elapsedTime = 0.0f;
		
		sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
		currentFrame = (currentFrame + 1);
		
	}


}



void Character::move(int dir, Character* chr) {
	float speed = 900.0f;    // Movement speed
	float deltaTime = 0.03f;  // Approx. frame time for 60 FPS
	float safetyDistance = 70.0f;  // Minimum allowed distance between characters

	// Calculate new position
	float newPos = sprite.getPosition().x + (dir * speed * deltaTime);
	float otherPos = chr->getSprite().getPosition().x;

	// Adjusted boundary check considering the sprite's width and height
	sf::FloatRect bounds = sprite.getGlobalBounds();
	float halfWidth = bounds.width / 2.0f;

	// Ensure movement maintains at least safetyDistance
	bool safeDistanceMaintained = abs(otherPos - newPos) >= safetyDistance;

	// Check boundaries (the sprite's center should stay within the window's width)
	bool withinBounds = (newPos - halfWidth >= 0 && newPos + halfWidth <= 800);

	if (withinBounds && safeDistanceMaintained) {
		sprite.move(dir * speed * deltaTime, 0.0f);
		std::cout << "Moved to: " << sprite.getPosition().x << std::endl;
	}
	else {
		std::cout << "Movement blocked. Current position: " << sprite.getPosition().x
			<< ", Other position: " << otherPos << std::endl;
	}
}





void Character::drawChar(sf::RenderWindow& window) {
	window.draw(sprite);
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

sf::Sprite& Character::getSprite(){
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


