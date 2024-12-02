#include "character.h"

#include <filesystem>
#include <iostream>

void Character::loadCharVarTextures(std::string& folderPath) {
	
	try {
		std::map<std::string, std::array<sf::Texture, 5>> map;

		for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
			std::array<sf::Texture, 5> arr;
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


void Character::animate(bool flip, std::string& charAnimated) {
	float frameDuration = 0.1f;
	int idx = 2;
	if (state == 1) {
		idx = 0;
	}
	else if (state == -1) {
		idx = 1;
	}
	else if (state == 2) {
		idx = 3;
	}
	else if (state == 3) {
		idx = 4;
	}
	

	int frameWidth, frameHeight, numFrames = 2;
	frameHeight = 128;
	frameWidth = 128;

	if (charAnimated == "jonsnow" || charAnimated=="brienne" || charAnimated == "danaerys") {
		if (state==0) {
			numFrames = 6;
		}
		else if (state==-1) {
			numFrames = 2;
		}
		else if(state == 1){
			numFrames = 6;
		}
		else if (state == 2) {
			numFrames = 8;
		}
		else if (state == 3) {
			if (selectedCharacter == "brienne") {
				numFrames = 3;
			}
			else {
				numFrames = 2;
			}
		}
	}
	else  {
	
		if (state == 0) {
			numFrames = 11;
		}
		else if (state == 1) {
			numFrames = 6;
		}
		else {
			numFrames = 2;
		} 
	}

	elapsedTime += animationClock.restart().asSeconds();


	if (currentFrame >= numFrames) {
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

	
	////////////////////////to be updated when enemy added

}



void Character::move(int dir, Character* chr) {
	float speed = 1000.0f;    // Movement speed
	float deltaTime = 0.03f;  // Approx. frame time for 60 FPS
	float safetyDistance = 70.0f;  // Minimum allowed distance between characters

	// Calculate new position
	float newPos = sprite.getPosition().x + (dir * speed * deltaTime);
	float otherPos = chr->getSprite().getPosition().x;

	// Boundary check
	bool withinBounds = (newPos > 0 && newPos < 800);

	// Ensure movement maintains at least safetyDistance
	bool safeDistanceMaintained = abs(otherPos - newPos) >= safetyDistance;

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

void Character::setCharVar(std::map<std::string, std::array<sf::Texture, 5>>& map) {
	charVars = map;
}
std::map<std::string, std::array<sf::Texture, 5>>& Character::getCharVar() {
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

Character::~Character() {
}


