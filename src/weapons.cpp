#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>  // For smart pointers

// Abstract Weapon class
class Weapon {
public:
    virtual void use(sf::RenderWindow& window) = 0;
    virtual ~Weapon() = default;
};

class Spear : public Weapon {
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Spear() {
        // Load spear texture
        if (!texture.loadFromFile("spear.png")) {  // Use relative path
            throw std::runtime_error("Failed to load Spear texture!");
        }
        sprite.setTexture(texture);
        sprite.setPosition(100, 100);  // Set position for visibility
    }
    void use(sf::RenderWindow& window) override {
        window.draw(sprite);
    }
};

class Sword : public Weapon {
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Sword() {
        // Load sword texture
        if (!texture.loadFromFile("sword.png")) {  // Use relative path
            throw std::runtime_error("Failed to load Sword texture!");
        }
        sprite.setTexture(texture);
        sprite.setPosition(200, 100);  // Set position for visibility
    }
    void use(sf::RenderWindow& window) override {
        window.draw(sprite);
    }
};

class BurningSword : public Weapon {
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    BurningSword() {
        // Load burning sword texture
        if (!texture.loadFromFile("burning_sword.png")) {  // Use relative path
            throw std::runtime_error("Failed to load Burning Sword texture!");
        }
        sprite.setTexture(texture);
        sprite.setPosition(300, 100);  // Set position for visibility
    }
    void use(sf::RenderWindow& window) override {
        window.draw(sprite);
    }
};

std::unique_ptr<Weapon> getWeaponForLevel(int level) {
    switch (level) {
    case 1: return std::make_unique<Spear>();
    case 2: return std::make_unique<Sword>();
    case 3: return std::make_unique<BurningSword>();
    default: return nullptr;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Thrones - Weapons");

    int level = 1;
    std::unique_ptr<Weapon> weapon;
    try {
        weapon = getWeaponForLevel(level);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;  // Exit if weapon creation fails
    }

    // // Load map image
    // sf::Image image;
    // if (!image.loadFromFile("map.jpg")) {  // Use relative path
    //     std::cerr << "Failed to load map image!" << std::endl;
    //     return 1;  // Exit if map loading fails
    // }

    // // Set map texture
    // sf::Texture texture;
    // if (!texture.loadFromImage(image)) {
    //     std::cerr << "Failed to create texture from map image!" << std::endl;
    //     return 1;  // Exit if texture creation fails
    // }
    // sf::Sprite backgroundSprite;
    // backgroundSprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(backgroundSprite);  // Draw the map background
        if (weapon) {
            weapon->use(window);  // Draw the weapon
        }
        window.display();
    }

    return 0;
}
