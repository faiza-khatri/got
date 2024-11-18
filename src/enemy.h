#ifndef ENEMY
#define ENEMY

#include "character.h"

class Enemy : public Character {

	Enemy(int hlth, int spd, int attackPwr, std::string nme);

	void changeState() override;
};


#endif