#include "gameEndScreen.h"

#include <filesystem>
#include <iostream>

EndScreen::EndScreen(sf::Vector2u& windowSize, bool won) {
	loadTextures(std::filesystem::current_path().parent_path().parent_path().parent_path().parent_path().string() + "\\pngImages\\end_scrn");
	changeActiveStatus(0);
	std::cout << "Player won: " << won << std::endl;
}

void EndScreen::initializeComponents(sf::Vector2u& windowSize, int playerSelected) {

}

void EndScreen::renderScreen(sf::RenderWindow& window) {

}

int EndScreen::handleInput(sf::RenderWindow&) {
	return 0;

}