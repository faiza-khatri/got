#ifndef GAME
#define GAME

#include <string>
#include "GameOverWindow.h"
#include "startScreen.h"
#include "characterSelectWindow.h"
#include "fightWindow.h"

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
	static void setCurrentState(int);
	int getCurrentState()const;
	void setPlayerSelected(int);
	int getPlayerSelected()const;
	void setCurrentScreen(BaseWindow*);
	BaseWindow* getCurrentScreen();

	void intializeComponents(sf::Vector2u&);
	void handleInput(sf::RenderWindow& window);
	void renderScreen(sf::RenderWindow&);

	~Game();
};


#endif