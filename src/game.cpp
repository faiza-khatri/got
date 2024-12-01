#include "game.h"

void Game::setCurrentState(int state) {
	currentState = state;
}

int Game::getCurrentState() {
	return currentState;
}


int Game::getPlayerSelected(){
	return playerSelected;
}

void Game::setPlayerSelected(int pl) {
	playerSelected = pl;
}

Game::Game(sf::Vector2u& windowSize) {
	currentState = 0;
	/*Game::characterSelectScreen =  new CharacterSelectWindow(windowSize);
	Game::startScreen = new StartScreen(windowSize);
	Game::fightScreen = new FightWindow(windowSize);*/
	/*Game::currentScreen = new StartScreen(windowSize);;*/
	/*screens[0] = startScreen;
	screens[1] = characterSelectScreen;
	screens[2] = fightScreen;*/

	screens.push_back(new StartScreen(windowSize));
	currentScreen = screens[currentState];
	playerSelected = 1;
	currentScreen->initializeComponents(windowSize, playerSelected);
	/*this->window = wind;*/
}

void Game::intializeComponents(sf::Vector2u& windowSize) {
	currentScreen->initializeComponents(windowSize, playerSelected);
}

void Game::handleInput(sf::RenderWindow& window) {
	sf::Vector2u windowSize = window.getSize();
	if (currentScreen->handleInput(window)) {
		if (currentState == 1) {
			playerSelected = currentScreen->getSelectedPlayerId();
			/*std::cout << "selected player id from actual game: " << currentScreen->getSelectedPlayerId() << std::endl;*/
			screens.push_back(new FightWindow(windowSize, playerSelected));
		}
		else if (currentState == 0) {
			screens.push_back(new CharacterSelectWindow(windowSize));
		}
		currentState += 1;
		currentScreen = screens[currentState];
		Game::intializeComponents(windowSize);
	}
	
}

void Game::renderScreen(sf::RenderWindow& wind) {
	currentScreen->renderScreen(wind);
}


void Game::setCurrentScreen(BaseWindow* curr) {
	BaseWindow* temp = currentScreen;
	delete temp;
	currentScreen = curr;
}
BaseWindow* Game::getCurrentScreen() {
	return currentScreen;
}

Game::~Game() {
	/*delete startScreen;
	delete characterSelectScreen;
	delete fightScreen;*/
	for (BaseWindow* temp : screens) {
		delete temp;
	};
}