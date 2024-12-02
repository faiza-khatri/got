//#include "enemy.h"
//
//#include <filesystem>
//#include <iostream>
//#include <random>
//
//#include <SFML/Window/Keyboard.hpp> 
//
//Enemy::Enemy(int hlth, int spd, int attackPwr, std::string nme, int pl) {
//	sf::Sprite enemy;
//
//
//	setState(0); // defaut is idle
//	setHealth(hlth);
//	setSpeed(spd);
//	setAttackPower(attackPwr);
//	setSprite(enemy);
//	setName(nme);
//	std::string s;
//	if (pl == 0) {
//		s = "white";
//	}
//	else {
//		s = "whitewalker";
//	}
//
//	setSelectedCharacter(s);
//	setCurrentFrame(0);
//	std::string folderPath = std::filesystem::current_path().parent_path().
//		parent_path().parent_path().parent_path().string() + "\\pngImages\\enemy";
//	loadCharVarTextures(folderPath);
//
//	std::string chrEnemy = getSelectedCharacter();
//	std::cout << "this is my enemy chosen currently: " << chrEnemy << std::endl;
//
//	setCharTexture(getCharVar()[chrEnemy][2]);
//
//	enemy.setTexture(getCharTexture());
//
//	int frameWidth = 128, frameHeight = 128;
//	int numFrames = 11;
//
//
//	/*enemy.setScale(-2.0f, 2.0f);*/
//	enemy.setOrigin({ enemy.getLocalBounds().width / 2.0f, enemy.getLocalBounds().height });
//	enemy.setScale(2.0f, 2.0f);
//	enemy.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
//
//	enemy.setPosition(600.0f, 300.0f);
//	setFacingRight(1);
//
//	setSprite(enemy);
//
//
//	sf::Clock clk;
//
//	setAnimationClock(clk);
//	setElapsedTime(0.0f);
//
//	sf::Clock attClk;
//	sf::Time tm;
//
//	attackClock = attClk;
//	moveInterval = 5.0f;
//	randNum = 0;
//
//	isMovingToPlayer = false;
//	isMovingAwayFromPlayer = false;
//	attackComplete = true;
//	attack = false;
//	elapsedAttack = 0.0f;
//	phase = 0;
//}
//
//int Enemy::changeState(sf::Vector2f& playerPos, Character* player) {
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
//		if (getState() != 1) {
//			setCurrentFrame(0);
//			setCharTexture(getCharVar()[getSelectedCharacter()][0]);
//			getSprite().setTexture(getCharTexture());
//			setState(1);
//		}
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
//		if (getState() != -1) {
//			setCurrentFrame(0);
//			setCharTexture(getCharVar()[getSelectedCharacter()][1]);
//			getSprite().setTexture(getCharTexture());
//			setState(-1);
//		}
//	}
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//
//		move(1, player);
//		if (getState() != 2) {
//			setCurrentFrame(0);
//			setCharTexture(getCharVar()[getSelectedCharacter()][3]);
//			getSprite().setTexture(getCharTexture());
//			setState(2);
//		}
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//		move(-1, player);
//		if (getState() != 2) {
//			setCurrentFrame(0);
//			setCharTexture(getCharVar()[getSelectedCharacter()][3]);
//			getSprite().setTexture(getCharTexture());
//			setState(2);
//		}
//	}
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
//		if (!isFacingRight()) {
//			changeDirection();
//		}
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
//		if (isFacingRight()) {
//			changeDirection();
//		}
//	}
//
//
//	float distance = getSprite().getPosition().x - player->getSprite().getPosition().x;
//
//	if (abs(distance) < 150.0f) {
//		if (getState() != -1 && getState() != 1 && player->getState() == 1) {
//			setHealth(getHealth() - 5);
//			std::cout << "health of enemy: " << getHealth() << std::endl;
//			if (getState() != 3) {
//				setCurrentFrame(0);
//				setCharTexture(getCharVar()[getSelectedCharacter()][4]);
//				getSprite().setTexture(getCharTexture());
//				setState(3);
//
//			}
//		}
//
//
//	}
//
//	return 0;
//}
//
//
