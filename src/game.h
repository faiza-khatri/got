#ifndef GAME
#define GAME

#include <string>

#include "startScreen.h"
#include "characterSelectWindow.h"
#include "fightWindow.h"

class Game {
private:
	int currentState;
	/*sf::RenderWindow& window;*/
	std::string playerSelected;
	StartScreen* startScreen;
	CharacterSelectWindow* characterSelectScreen;
	FightWindow* fightScreen;
	BaseWindow* currentScreen;
	std::map<int, BaseWindow*> screens;

public:
	Game(sf::Vector2u&);
	void setCurrentState(int);
	int getCurrentState();
	void setPlayerSelected(std::string&);
	std::string& getPlayerSelected();
	void setCurrentScreen(BaseWindow*);
	BaseWindow* getCurrentScreen();
	
	void intializeComponents(sf::Vector2u&);
	void handleInput(sf::RenderWindow& window);
	void renderScreen(sf::RenderWindow&);

	~Game();
};


#endif