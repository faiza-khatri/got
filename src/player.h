#ifndef PLAYER
#define PLAYER

#include "character.h"
#include <iostream>

class Player : public Character {
public:
	Player(int hlth, int spd, int attackPwr, std::string nme, int pl, int num);

	int changeState(sf::Vector2f&, Character*, 
		sf::Keyboard::Key, sf::Keyboard::Key,
		sf::Keyboard::Key, sf::Keyboard::Key,
		sf::Keyboard::Key, sf::Keyboard::Key,
		sf::Keyboard::Key, sf::Keyboard::Key);
	void stateUpdate(int idx, int setState);

};


#endif