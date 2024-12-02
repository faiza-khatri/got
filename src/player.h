#ifndef PLAYER
#define PLAYER

#include "character.h"
//#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

class Player : public Character {
public:
	Player(int hlth, int spd, int attackPwr, std::string nme, int pl, int num);

	/*void attack() override;
	void defend() override;*/
	/*void loadCharVarTextures() override;*/
	int changeState(sf::Vector2f&, Character*, 
		sf::Keyboard::Key, sf::Keyboard::Key,
		sf::Keyboard::Key, sf::Keyboard::Key,
		sf::Keyboard::Key, sf::Keyboard::Key,
		sf::Keyboard::Key, sf::Keyboard::Key);
};


#endif