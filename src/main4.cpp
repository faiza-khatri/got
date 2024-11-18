#include <SFML/Graphics.hpp>
#include <iostream>
#include "startScreen.h" 

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Start Screen Test");
    StartScreen startScreen;
    startScreen.loadTextures();
    startScreen.setupScreen(window);
    return 0;
}
