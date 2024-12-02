#include "player.h"

#include <filesystem>

#include <SFML/Window/Keyboard.hpp> 


Player::Player(int hlth, int spd, int attackPwr, std::string nm, int pl) {
	std::cout << "i called this constrcutor ..." << std::endl;
	sf::Sprite player;


	setState(0); // defaut is idle
	setHealth(hlth);
	setSpeed(spd);
	setAttackPower(attackPwr);
	setSprite(player);
	setName(nm);
	std::string s;
	if (pl == 0) {
		s = "brienne";
	}
	else if (pl == 2) {
		s = "jonsnow";
	}
	else if (pl == 1) {
		s = "danaerys";
	}

	setSelectedCharacter(s);
	setCurrentFrame(0);
	std::string folderPath = std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\player";
	loadCharVarTextures(folderPath);

	std::string chrPlayer = getSelectedCharacter();

	setCharTexture(getCharVar()[chrPlayer][2]);

	player.setTexture(getCharTexture());

	int frameWidth, frameHeight;
	int numFrames;
	player.setOrigin({ player.getLocalBounds().width / 2.0f, player.getLocalBounds().height });

	if (chrPlayer == "jonsnow") {
		frameWidth = 96;
		frameHeight = 84;
		player.setScale(8.0f, 8.0f);

	}
	else if (chrPlayer == "brienne") {
		frameWidth = 128;
		frameHeight = 128;
		player.setScale(2.0f, 2.0f);
	}
	else {
		frameWidth = 128;
		frameHeight = 128;
		player.setScale(2.0f, 2.0f);
	}

	player.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));


	player.setPosition(60.0f, 300.0f);
	setFacingRight(1);




	setSprite(player);


	sf::Clock clk;

	setAnimationClock(clk);
	setElapsedTime(0.0f);

}


int Player::changeState(sf::Vector2f&, Character* enemy) {

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		move(1, enemy);
		if (getState() != 2) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][3]);
			getSprite().setTexture(getCharTexture());
			setState(2);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		move(-1, enemy);
		if (getState() != 2) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][3]);
			getSprite().setTexture(getCharTexture());
			setState(2);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		if (!isFacingRight()) {
			changeDirection();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		if (isFacingRight()) {
			changeDirection();
		}
	}

	float distance = getSprite().getPosition().x - enemy->getSprite().getPosition().x;

	if (abs(distance) < 180.0f) {
		if (getState() != -1 && getState() != 1 && enemy->getState() == 1) {
			setHealth(getHealth() - 5);
			std::cout << "health of player: " << getHealth() << std::endl;
			if (getState() != 3) {
				setCurrentFrame(0);
				setCharTexture(getCharVar()[getSelectedCharacter()][4]);
				getSprite().setTexture(getCharTexture());
				setState(3);
			}
			return 1;
		}

	}
	return 0;

}