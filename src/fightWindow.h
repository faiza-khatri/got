#ifndef  FIGHT_WINDOW
#define FIGHT_WINDOW

#include "baseWindow.h"
#include "player.h"


#include <map>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

#include "player.h"

//#include "game.h"


class FightWindow : public BaseWindow, public sf::RenderWindow {
public:
    FightWindow(sf::Vector2u& windowSize, int, int);
    void initializeComponents(sf::Vector2u&, int, int) override;
    void renderScreen(sf::RenderWindow& window) override;
    int handleInput(sf::RenderWindow&);
    void operator=(const FightWindow*);
    ~FightWindow();
    void updateLifeBar(float damage, sf::RectangleShape& bar, float& currentWidth);
    sf::RectangleShape lifeBarOutline;
    sf::RectangleShape enemyLifeBarOutline;
    void animateByState(Character*);
private:
    Player* p1;
    Player* p2;
    float playerCurrentWidth; 
    float enemyCurrentWidth;
    sf::RectangleShape lifeBar;                           
    sf::RectangleShape enemyLifeBar;
    sf::Clock clock;
    sf::Sprite controls;
    sf::Texture controlTexture;;

};

#endif