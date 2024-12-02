#include "fightWindow.h"
#include <SFML/Window/Keyboard.hpp> 

#include <filesystem>

FightWindow::FightWindow(sf::Vector2u& windowSize, int pl, int pl2) {

    // make players
    p1 = new Player(100, 10, 20, "danaerys", pl, 0);

    changeActiveStatus(0);
    p2 = new Player(100, 10, 20, "danaerys", pl2, 1);


    // player 1 life bar
    lifeBar.setSize(sf::Vector2f(200, 20));
    lifeBar.setFillColor(sf::Color::Green);
    lifeBar.setPosition(10, 10); 

    lifeBarOutline.setSize(sf::Vector2f(202, 22));
    lifeBarOutline.setFillColor(sf::Color::Transparent);
    lifeBarOutline.setOutlineColor(sf::Color::White);
    lifeBarOutline.setOutlineThickness(2);
    lifeBarOutline.setPosition(lifeBar.getPosition().x - 1, lifeBar.getPosition().y - 1);


    // player 2 life bar
    enemyLifeBar.setSize(sf::Vector2f(200, 20));
    enemyLifeBar.setFillColor(sf::Color::Green);
    enemyLifeBar.setPosition(windowSize.x - enemyLifeBar.getSize().x - 10, 10);

    enemyLifeBarOutline.setSize(sf::Vector2f(202, 22));
    enemyLifeBarOutline.setFillColor(sf::Color::Transparent);
    enemyLifeBarOutline.setOutlineColor(sf::Color::White);
    enemyLifeBarOutline.setOutlineThickness(2);
    enemyLifeBarOutline.setPosition(
        enemyLifeBar.getPosition().x - 1,
        enemyLifeBar.getPosition().y - 1
    );

    playerCurrentWidth = 200.0f;
    enemyCurrentWidth = 200.0f;


    // controls description sprite
    controls = sf::Sprite();

    
    std::string path = std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\Controls.png";
    if (!controlTexture.loadFromFile(path)) {
        std::cerr << "Error: Unable to load controls!" << std::endl;
    }
    else {
        std::cout << "loaded cntrols png successfully" << std::endl;
        controls.setTexture(controlTexture);
        controls.setScale(2.0f, 2.0f);
        controls.setPosition(0.0f, -340.0f);
        controls.setScale(static_cast<float>(windowSize.x) / ( controlTexture.getSize().x), static_cast<float>(windowSize.y) / ( controlTexture.getSize().y));
    }
    
    

    clock.restart();
}

void FightWindow::initializeComponents(sf::Vector2u&, int playerSelected, int playerSelected2) {
    
    // set players according to global selected players
    setSelectedPlayerId1(playerSelected);
    setSelectedPlayerId2(playerSelected2);
    std::string s = "brienne";
    if (playerSelected == 2) {
        s = "jonsnow";
    }
    else if (playerSelected == 1) {
        s = "danaerys";
    }
    std::string s2 = "brienne";
    if (playerSelected2 == 2) {
        s2 = "jonsnow";
    }
    else if (playerSelected2 == 1) {
        s2 = "danaerys";
    }
    p1->setSelectedCharacter(s);
    p2->setSelectedCharacter(s2);
    p1->changeDirection();
    p1->changeDirection();
    p2->changeDirection();
}

void FightWindow::animateByState(Character* pl) {
    std::string character = pl->getSelectedCharacter();
    switch (pl->getState()) {
    case -1:
        pl->animate(false, character, character == "jonsnow" ? 4 : 2, 1); // defend
        break;
    case 0:
        pl->animate(false, character, 6, 2); // idle
        break;
    case 1:
        pl->animate(false, character, 6, 1); // attack
        break;
    case 2:
        pl->animate(false, character, 8, 3); // walk
        break;
    case 3:
        pl->animate(false, character, character == "brienne" ? 3 : 2, 4); // hurt
        break;
    case 4:
        pl->animate(false, character, character == "danaerys" ? 4 : 3, 5); // attack2
        break;
    case 5:
        pl->animate(false, character, character == "danaerys" ? 3 : 4, 6); // attack2
        break;
    case 6:
        pl->animate(false, character, character == "jonsnow" ? 4 : 3, 7); // dead
        break;
    }

}

void FightWindow::renderScreen(sf::RenderWindow& window) {
    
    window.draw(getBgSprite());
    

    animateByState(p1);
    
    animateByState(p2);

  

    window.draw(p1->getSprite());
    window.draw(p2->getSprite());

    window.draw(lifeBarOutline);
    window.draw(lifeBar);
    window.draw(enemyLifeBarOutline);
    window.draw(enemyLifeBar);
    window.draw(controls);
}

int FightWindow::handleInput(sf::RenderWindow&) {
    sf::FloatRect playerBounds = p1->getSprite().getGlobalBounds();
    sf::Vector2f playerCenter = sf::Vector2f(playerBounds.left + playerBounds.width / 2,
        playerBounds.top + playerBounds.height / 2);

    int damagePl = p1->changeState(p1->getPosition(), p2, 
        sf::Keyboard::Q, sf::Keyboard::W, sf::Keyboard::E, sf::Keyboard::R,
        sf::Keyboard::S, sf::Keyboard::F, sf::Keyboard::A, sf::Keyboard::D);
    int damageEn = p2->changeState(p1->getPosition(), p1,
        sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::P, sf::Keyboard::L,
        sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right);

    if (damagePl) {
        updateLifeBar(10.0f, lifeBar, playerCurrentWidth);
    }
    if (damageEn) {
        updateLifeBar(10.0f, enemyLifeBar, enemyCurrentWidth);
    }

    if (p1->getHealth() <= 0) {
        p1->stateUpdate(7, 6);
        
    }
    if (p2->getHealth() <=  0) {
        p2->stateUpdate(7, 6);
        
    }


    if (!p1->isAlive()) {
        return 1;
    }
    else if (!p2->isAlive()) {
        return 2;
    }

    return 0; 
}

void FightWindow::updateLifeBar(float damage, sf::RectangleShape& bar, float& currentWidth) {
    float maxWidth = 200.0f;

    sf::Time elapsedTime = clock.getElapsedTime();
    if (elapsedTime.asSeconds() > 0.001f) {
        currentWidth -= damage;
        std::cout << "damage :" << std::endl;
        if (currentWidth < 0.0f) {
            currentWidth = 0.0f;
        }
        clock.restart();
    }

    bar.setSize(sf::Vector2f(currentWidth, 20));
    float percentage = currentWidth / maxWidth;
    if (percentage > 0.5f) {
        bar.setFillColor(sf::Color::Green);
    }
    else if (percentage > 0.2f) {
        bar.setFillColor(sf::Color::Yellow);
    }
    else {
        bar.setFillColor(sf::Color::Red);
    }
}

void FightWindow::operator=(const FightWindow* other) {
    p1 = other->p1;
    p2 = other->p2;
}

FightWindow::~FightWindow() {
    delete p1;
    delete p2;
}
