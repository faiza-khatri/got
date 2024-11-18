#include "player.h"

#include <filesystem>

#include <SFML/Window/Keyboard.hpp> 


Player::Player(int hlth, int spd, int attackPwr, std::string nme) {
	sf::Sprite player;
	setState(0); // defaut is idle
	setHealth(hlth);
	setSpeed(spd);
	setAttackPower(attackPwr);
	setSprite(player);
	setName(nme);
	std::string s = "jonsnow";
	setSelectedCharacter(s);
	setCurrentFrame(0);
	loadCharVarTextures();

	std::string chrPlayer = getSelectedCharacter();

	setCharTexture(getCharVar()[chrPlayer][2]);

	player.setTexture(getCharTexture());

	int frameWidth, frameHeight;
	int numFrames;

	if (chrPlayer == "jonsnow" || chrPlayer == "brienne") {
		frameWidth = 290 / 4;
		frameHeight = 86;
	}
	else {
		frameWidth = 100;
		frameHeight = 60;
	}

	player.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));

	player.setPosition(400.0f, 500.0f);
	player.setScale(5.0f, 5.0f);
	setSprite(player);


	sf::Clock clk;

	setAnimationClock(clk);
	setElapsedTime(0.0f);

}

void Player::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		if (getState() != 1) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][0]);
			getSprite().setTexture(getCharTexture());
			setState(1);
		}		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
		if (getState() != -1) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][1]);
			getSprite().setTexture(getCharTexture());
			setState(-1);
		}	
	}
	/*else {
		if (getState() != 0) {
			setState(0);
			setCurrentFrame(0);
		}
		
	}*/
}

