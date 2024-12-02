
#include "game.h"

void Game::setCurrentState(int state) {
	currentState = state;
}

int Game::getCurrentState() {
	return currentState;
}


int Game::getPlayerSelected() {
	return playerSelected;
}

void Game::setPlayerSelected(int pl) {
	playerSelected = pl;
}

Game::Game(sf::Vector2u& windowSize) {
	// when game begins, start screen
	currentState = 0;
	

	screens.push_back(new StartScreen(windowSize));
	currentScreen = screens[currentState];
	playerSelected = 0;
	playerSelected2 = 0;
	currentScreen->initializeComponents(windowSize, playerSelected, playerSelected2);
	
}

void Game::intializeComponents(sf::Vector2u& windowSize) {
	currentScreen->initializeComponents(windowSize, playerSelected, playerSelected2);
}

void Game::handleInput(sf::RenderWindow& window) {
	sf::Vector2u windowSize = window.getSize();
	int trans = currentScreen->handleInput(window);
	if (trans) {
		// if on character select screen, go to fight screen
		if (currentState == 1) {
			playerSelected = currentScreen->getSelectedPlayerId1();
			playerSelected2 = currentScreen->getSelectedPlayerId2();
			screens.push_back(new FightWindow(windowSize, playerSelected, playerSelected2));
		}
		// if on start screen, go to character select screen
		else if (currentState == 0) {
			bg = currentScreen->getBgSprite();
			screens.push_back(new CharacterSelectWindow(windowSize));
		}
		// if on fight screen, go to result screen
		else if (currentState == 2) {
			// trans is 1 if player 1 won, and 2 if player 2 won
			std::cout << "transiiton var" << trans << std::endl;
			if (trans == 1) {
				screens.push_back(new EndScreen(windowSize, 0));
			}
			else if (trans == 2) {
				screens.push_back(new EndScreen(windowSize, 1));
			}
		}
		// if on end screen and play again
		else if (currentState == 3) {
			// empty screens vector
			for (BaseWindow* temp : screens) {
				delete temp;
			};
			screens.clear();
			// go back to start screen
			screens.push_back(new StartScreen(windowSize));
			currentState = -1;
		}
		currentState += 1;
		currentScreen = screens[currentState];
		currentScreen->setBgSprite(bg);
		Game::intializeComponents(windowSize);
	}

}

void Game::renderScreen(sf::RenderWindow& wind) {
	wind.draw(bg);
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
	// mem manage
	for (BaseWindow* temp : screens) {
		delete temp;
	};

}

