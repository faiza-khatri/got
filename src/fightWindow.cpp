#include "fightWindow.h"

FightWindow::FightWindow(sf::Vector2u& windowSize) {
	p1 = new Player(100, 10, 20, "danaerys", getSelectedPlayerId());
	changeActiveStatus(0);
}

void FightWindow::initializeComponents(sf::Vector2u&, int playerSelected) {
	setSelectedPlayerId(playerSelected);
}
void FightWindow::renderScreen(sf::RenderWindow& window) {
	p1->animate(false);
	window.draw(p1->getSprite());
}
int FightWindow::handleInput(sf::RenderWindow&) {
	p1->changeState();
	return 0;
}

void FightWindow::operator=(const FightWindow* other) {
	Player* p1 = other->p1;
}

FightWindow::~FightWindow() {
	delete p1;
}
