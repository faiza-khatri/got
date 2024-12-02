#ifndef GAME
#define GAME

#include <string>

#include "startScreen.h"
#include "characterSelectWindow.h"
#include "fightWindow.h"
#include "gameEndScreen.h"

class Game {
private:
	int currentState;
	/*sf::RenderWindow& window;*/
	int playerSelected;
	/*StartScreen* startScreen;
	CharacterSelectWindow* characterSelectScreen;
	FightWindow* fightScreen;*/
	BaseWindow* currentScreen;
	std::vector<BaseWindow*> screens;
	/*std::map<int, BaseWindow*> screens;*/

public:
	Game(sf::Vector2u&);
	void setCurrentState(int);
	int getCurrentState();
	void setPlayerSelected(int);
	int getPlayerSelected();
	void setCurrentScreen(BaseWindow*);
	BaseWindow* getCurrentScreen();
	
	void intializeComponents(sf::Vector2u&);
	void handleInput(sf::RenderWindow& window);
	void renderScreen(sf::RenderWindow&);

	~Game();
};


#endif