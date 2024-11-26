#include "character.h"

#include <filesystem>
#include <iostream>

void Character::loadCharVarTextures(std::string& folderPath) {
	
	try {
		std::map<std::string, std::array<sf::Texture, 3>> map;

		for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
			std::array<sf::Texture, 3> arr;
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


void Character::animate(bool flip) {
	float frameDuration = 0.15f;
	int idx = 2;
	if (state == 1) {
		idx = 0;
	}
	else if (state == -1) {
		idx = 1;
	}

	sf::Texture animationTexture = charVars[selectedCharacter][idx];
	

	int frameWidth, frameHeight, numFrames;

	if (selectedCharacter == "jonsnow") {
		frameHeight = 84;
		if (state==0) {
			frameWidth = 96;
			numFrames = 7;
		}
		else if (state==-1) {
			frameWidth = 96;
			numFrames = 6;
		}
		else {
			frameWidth = 96;
			numFrames = 6;
		}
	} else if (selectedCharacter == "brienne") {
		frameHeight = 80;
		if (state == 0) {
			frameWidth = 64;
			numFrames = 4;
		}
		else if (state == -1) {
			frameWidth = 64;
			numFrames = 4;
		}
		else {
			frameWidth = 96;
			numFrames = 8;
		}
	}
	else {
		frameHeight = 64;
		frameWidth = 100;
		if (state == 0) {
			numFrames = 4;
		}
		else if (state==1) {
			numFrames = 6;
		}
		else {
			numFrames = 5;
		}
	}

	elapsedTime += animationClock.restart().asSeconds();

	/*sprite.setTexture(animationTexture);*/


	if (currentFrame >= numFrames) {
		currentFrame = 0;
		state = 0;
		sprite.setTexture(charVars[selectedCharacter][2]);
	}


	if (elapsedTime >= frameDuration) {
		std::cout << selectedCharacter << ": " << idx << std::endl;
		elapsedTime = 0.0f;
		/*std::cout << "Current frame = " << currentFrame << std::endl;
		std::cout << "Offset = " << currentFrame * frameWidth << std::endl;
		std::cout << "Frame Width = " << frameWidth << std::endl;
		std::cout << "Frame Height = " << frameHeight << std::endl;*/
		sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
		currentFrame = (currentFrame + 1);
		
		
	}

	
	////////////////////////to be updated when enemy added

}



void Character::move(int dir) { 
	//////////// later add logic for the case where two characters may override each other
	float xPos = sprite.getPosition().x;
	if (xPos + (2 * dir) > 0 && xPos + (2 * dir) < 1600) {
		sprite.setPosition(xPos + (2 * dir), sprite.getPosition().y);
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

void Character::setCharVar(std::map<std::string, std::array<sf::Texture, 3>>& map) {
	charVars = map;
}
std::map<std::string, std::array<sf::Texture, 3>>& Character::getCharVar() {
	return charVars;
}

sf::Texture& Character::getCharTexture() {
	return charTexture;
}

void Character::setCharTexture(sf::Texture& txt) {
	charTexture = txt;
}

Character::~Character() {
}


