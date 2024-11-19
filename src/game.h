#ifndef GAME
#define GAME

#include <string>

//#include "startScreen.h"
//#include "characterSelectWindow.h"

class Game {
private:
	int currentState;
	std::string playerSelected;
public:
	Game();
	void setCurrentState(int);
	int getCurrentState();
	void setPlayerSelected(std::string&);
	std::string& getPlayerSelected();
};


#endif