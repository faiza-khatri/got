#include "fightWindow.h"

FightWindow::FightWindow(sf::Vector2u& windowSize, Game& game) {
	p1 = new Player(100, 10, 20, "danaerys");
}

void FightWindow::initializeComponents(sf::Vector2u&) {

}
void FightWindow::renderScreen(sf::RenderWindow& window) {
	p1->animate(false);
	window.draw(p1->getSprite());
}
void FightWindow::handleInput(sf::RenderWindow&, Game& game) {
	p1->changeState();
}

FightWindow::~FightWindow() {
	delete p1;
}
