#include "fightWindow.h"

FightWindow::FightWindow(sf::Vector2u& windowSize, int pl) {
	/*std::cout << "selected player id from fightWindow: " << getSelectedPlayerId() << std::endl;*/
	p1 = new Player(100, 10, 20, "danaerys", pl);
	changeActiveStatus(0);
}

void FightWindow::initializeComponents(sf::Vector2u&, int playerSelected) {
	setSelectedPlayerId(playerSelected);
	std::string s = "brienne";
	if (playerSelected == 2) {
		s = "jonsnow";
	}
	else if (playerSelected == 1) {
		s = "danaerys";
	}
	p1->setSelectedCharacter(s);
	
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
