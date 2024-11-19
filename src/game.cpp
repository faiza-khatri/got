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

Game::Game() {
	currentState = 0;
}