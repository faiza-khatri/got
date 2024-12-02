#include "player.h"

#include <filesystem>

#include <SFML/Window/Keyboard.hpp> 


Player::Player(int hlth, int spd, int attackPwr, std::string nm, int pl, int num) {

	// initialize member vars with values
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


	frameWidth = 128;
	frameHeight = 128;

	

	player.setScale(2.0f, 2.0f);

	player.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));


	
	setFacingRight(1);

	if (num) {
		player.setPosition(600.0f, 300.0f);
	}
	else {
		player.setPosition(200.0f, 300.0f);
	}

	setSprite(player);


	sf::Clock clk;

	setAnimationClock(clk);
	setElapsedTime(0.0f);



}


int Player::changeState(sf::Vector2f&, Character* enemy, 
	sf::Keyboard::Key attack1Key,
	sf::Keyboard::Key attack2Key,
	sf::Keyboard::Key attack3Key,
	sf::Keyboard::Key defendKey,
	sf::Keyboard::Key turnLeftKey,
	sf::Keyboard::Key turnRightKey,
	sf::Keyboard::Key moveLeftKey,
	sf::Keyboard::Key moveRightKey) {
	// depending on key, decide state

	if (sf::Keyboard::isKeyPressed(attack1Key)) {
		if (getState() != 1) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][0]);
			getSprite().setTexture(getCharTexture());
			setState(1);
		}
	}
	else if (sf::Keyboard::isKeyPressed(attack2Key)) {
		if (getState() != 4) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][5]);
			getSprite().setTexture(getCharTexture());
			setState(4);
		}
	}
	else if (sf::Keyboard::isKeyPressed(attack3Key)) {
		if (getState() != 5) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][6]);
			getSprite().setTexture(getCharTexture());
			setState(5);
		}
	}
	else if (sf::Keyboard::isKeyPressed(defendKey)) {
		if (getState() != -1) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][1]);
			getSprite().setTexture(getCharTexture());
			setState(-1);
		}
	}

	if (sf::Keyboard::isKeyPressed(moveRightKey)) {

		move(1, enemy);
		if (getState() != 2) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][3]);
			getSprite().setTexture(getCharTexture());
			setState(2);
		}
	}
	else if (sf::Keyboard::isKeyPressed(moveLeftKey)) {
		move(-1, enemy);
		if (getState() != 2) {
			setCurrentFrame(0);
			setCharTexture(getCharVar()[getSelectedCharacter()][3]);
			getSprite().setTexture(getCharTexture());
			setState(2);
		}
	}

	if (sf::Keyboard::isKeyPressed(turnRightKey)) {
		if (!isFacingRight()) {
			changeDirection();
		}
	}
	else if (sf::Keyboard::isKeyPressed(turnLeftKey)) {
		if (isFacingRight()) {
			changeDirection();
		}
	}

	// check distance
	float distance = getSprite().getPosition().x - enemy->getSprite().getPosition().x;

	if (abs(distance) < 150.0f) {
		// check they are facing each other
		bool facingEachOther = (isFacingRight() && !enemy->isFacingRight()) || 
			(!isFacingRight() && enemy->isFacingRight());
		// if not defensive, and opponent does an offence
		if (getState() != -1 && getState() != 1 && (enemy->getState() == 1 || 
			enemy->getState() == 4 || enemy->getState() == 5) && facingEachOther ) {
			// decrement health
			setHealth(getHealth() - 5);
			std::cout << "health of player: " << getHealth() << std::endl;
			move(isFacingRight() ? -1 : 1, enemy);
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

void Player::stateUpdate(int idx, int setSt) {
	// specifically for death
	setCurrentFrame(0);
	setCharTexture(getCharVar()[getSelectedCharacter()][idx]);
	getSprite().setTexture(getCharTexture());
	setState(setSt);
}