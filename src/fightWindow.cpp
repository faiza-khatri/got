#include "fightWindow.h"

FightWindow::FightWindow(sf::Vector2u& windowSize, int pl) {
    p1 = new Player(100, 10, 20, "danaerys", pl);
    changeActiveStatus(0);

    // life bar
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
}

void FightWindow::renderScreen(sf::RenderWindow& window) {
    p1->animate(false);
    window.draw(p1->getSprite());
    window.draw(lifeBarOutline);
    window.draw(lifeBar);
}

int FightWindow::handleInput(sf::RenderWindow&) {
    updateLifeBar(3.0f);  // Increase damage per frame for a faster decrease

    // Call the player's change state function if necessary
    p1->changeState();

    return 0;
}

void FightWindow::updateLifeBar(float damage) {
    static float currentWidth = 200.0f;
    float maxWidth = 200.0f;

    sf::Time elapsedTime = clock.getElapsedTime();
    if (elapsedTime.asSeconds() > 0.001f) {  // Update every (0.001s)
        if (currentWidth > 0.0f) {
            currentWidth -= damage;  // decrease the width by the damage value
            if (currentWidth < 0.0f) {
                currentWidth = 0.0f;
            }
        }

        clock.restart();
    }

    // Update the life bar's size
    lifeBar.setSize(sf::Vector2f(currentWidth, 20));

    // color based on width percentage
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
    Player* p1 = other->p1;
}

FightWindow::~FightWindow() {
    delete p1;
}
