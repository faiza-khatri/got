#include "game.h"

void Game::setCurrentState(int state) {
	currentState = state;
}

int Game::getCurrentState() {
	return currentState;
}


std::string& Game::getPlayerSelected(){
	return playerSelected;
}

void Game::setPlayerSelected(std::string& str) {
	playerSelected = str;
}

Game::Game(sf::Vector2u& windowSize) {
	currentState = 0;
	Game::characterSelectScreen =  new CharacterSelectWindow(windowSize);
	Game::startScreen = new StartScreen(windowSize);
	Game::fightScreen = new FightWindow(windowSize);
	/*Game::currentScreen = new StartScreen(windowSize);;*/
	screens[0] = startScreen;
	screens[1] = characterSelectScreen;
	screens[2] = fightScreen;
	currentScreen = screens[currentState];
	playerSelected = "danaerys";
	currentScreen->initializeComponents(windowSize, currentScreen->getSelectedPlayerId());
	/*this->window = wind;*/
}

void Game::intializeComponents(sf::Vector2u& windowSize) {
	currentScreen->initializeComponents(windowSize, currentScreen->getSelectedPlayerId());
}

void Game::handleInput(sf::RenderWindow& window) {
	if (currentScreen->handleInput(window) == 1) {
		if (currentState == 1) {
			playerSelected = currentScreen->getSelectedPlayerId();
		}
		currentState += 1;
		currentScreen = screens[currentState];
		Game::intializeComponents(window.getSize());
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
	delete startScreen;
	delete characterSelectScreen;
	delete fightScreen;
}