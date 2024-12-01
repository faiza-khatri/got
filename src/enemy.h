#ifndef ENEMY
#define ENEMY

#include "character.h"


class Enemy : public Character {
	sf::Clock attackClock;
	float moveInterval;
	float elapsedAttack;
	bool isMovingToPlayer;
	bool isMovingAwayFromPlayer;
	bool attackComplete;
	bool attack;
	int randNum;
	int phase;
public:
	Enemy(int hlth, int spd, int attackPwr, std::string nme, int pl);

	void changeState(sf::Vector2f&, Character* player) override;
};



#endif