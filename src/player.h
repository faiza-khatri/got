#ifndef PLAYER
#define PLAYER

#include "character.h"
//#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

class Player : public Character {
public:
	Player();
	Player(int hlth, int spd, int attackPwr, std::string nme, int pl);

	/*void attack() override;
	void defend() override;*/
	/*void loadCharVarTextures() override;*/
	void changeState() override;
};


#endif