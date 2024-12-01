#include "fightWindow.h"

FightWindow::FightWindow(sf::Vector2u& windowSize, int pl) {
	/*std::cout << "selected player id from fightWindow: " << getSelectedPlayerId() << std::endl;*/
	p1 = new Player(100, 10, 20, "danaerys", pl);
	changeActiveStatus(0);
	FightWindow::enemy = new Enemy(100, 10, 20, "white", 0);
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
	p1->changeDirection();
	p1->changeDirection();
	enemy->changeDirection();

	
}
void FightWindow::renderScreen(sf::RenderWindow& window) {
	p1->animate(false, p1->getSelectedCharacter());
	enemy->animate(false, enemy->getSelectedCharacter());
	window.draw(p1->getSprite());
	window.draw(enemy->getSprite());
}
int FightWindow::handleInput(sf::RenderWindow&) {
	sf::FloatRect playerBounds = p1->getSprite().getGlobalBounds();
	sf::Vector2f playerCenter = sf::Vector2f(playerBounds.left + playerBounds.width / 2, 
		playerBounds.top + playerBounds.height / 2);
	p1->changeState(p1->getPosition(), enemy);
	enemy->changeState(playerCenter, p1);

	if (p1->getHealth() < 0) {
		return 1;
	}
	if (enemy->getHealth() < 0) {
		return 2;
	}

	return 0;
}

void FightWindow::operator=(const FightWindow* other) {
	p1 = other->p1;
	enemy = other->enemy;
}

FightWindow::~FightWindow() {
	delete p1;
	delete enemy;
}
