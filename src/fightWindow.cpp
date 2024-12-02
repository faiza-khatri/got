#include "fightWindow.h"

FightWindow::FightWindow(sf::Vector2u& windowSize, int pl) {
	/*std::cout << "selected player id from fightWindow: " << getSelectedPlayerId() << std::endl;*/
	p1 = new Player(100, 10, 20, "danaerys", pl);
	changeActiveStatus(0);
	FightWindow::enemy = new Enemy(100, 10, 20, "white", 0);

	lifeBar.setSize(sf::Vector2f(200, 20));
	lifeBar.setFillColor(sf::Color::Green);          // color is green
	lifeBar.setPosition(windowSize.x - lifeBar.getSize().x - 10, 10);

	// life bar outline
	lifeBarOutline.setSize(sf::Vector2f(202, 22));
	lifeBarOutline.setFillColor(sf::Color::Transparent);
	lifeBarOutline.setOutlineColor(sf::Color::White);  // white outline
	lifeBarOutline.setOutlineThickness(2);
	lifeBarOutline.setPosition(lifeBar.getPosition().x - 1, lifeBar.getPosition().y - 1);

	//  timing damage decrease
	clock.restart();
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
	window.draw(lifeBarOutline);
	window.draw(lifeBar);
}
int FightWindow::handleInput(sf::RenderWindow&) {

	sf::FloatRect playerBounds = p1->getSprite().getGlobalBounds();

	sf::Vector2f playerCenter = sf::Vector2f(playerBounds.left + playerBounds.width / 2, 
		playerBounds.top + playerBounds.height / 2);
	int damagePl = p1->changeState(p1->getPosition(), enemy);
	int damageEn = enemy->changeState(playerCenter, p1);
	if (damagePl) {
		updateLifeBar(10.0f);
	}

	if (p1->getHealth() < 0) {
		return 1;
	}
	if (enemy->getHealth() < 0) {
		return 2;
	}

	return 0;
}

void FightWindow::updateLifeBar(float damage) {
	static float currentWidth = 200.0f;
	float maxWidth = 200.0f;

	sf::Time elapsedTime = clock.getElapsedTime();
	if (elapsedTime.asSeconds() > 0.001f) {  
		if (currentWidth > 0.0f) {
			currentWidth -= damage;  
			if (currentWidth < 0.0f) {
				currentWidth = 0.0f;
			}
		}

		clock.restart();
	}


	lifeBar.setSize(sf::Vector2f(currentWidth, 20));


	float percentage = currentWidth / maxWidth;
	if (percentage > 0.5f) {
		lifeBar.setFillColor(sf::Color::Green);
	}
	else if (percentage > 0.2f) {
		lifeBar.setFillColor(sf::Color::Yellow);
	}
	else {
		lifeBar.setFillColor(sf::Color::Red);
	}
}

void FightWindow::operator=(const FightWindow* other) {
	p1 = other->p1;
	enemy = other->enemy;
}

FightWindow::~FightWindow() {
	delete p1;
	delete enemy;
}

