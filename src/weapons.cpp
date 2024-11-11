#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>  // For smart pointers

// Abstract Weapon class
class Weapon {
public:
    virtual void use(sf::RenderWindow& window) = 0; 
    virtual ~Weapon() = default;
};

// Derived class: Spear
class Spear : public Weapon {
private:
    sf::RectangleShape shaft;  
    sf::ConvexShape tip;
public:
    Spear() {
        shaft.setSize(sf::Vector2f(10.f, 100.f));  // Width, Height
        shaft.setFillColor(sf::Color(139, 69, 19)); 
        shaft.setOutlineColor(sf::Color::Black);  // Outline color
        shaft.setOutlineThickness(2.f);  // Thickness of the outline
        shaft.setPosition(200.f, 200.f);  // Position the spear

        // triangular tip of the spear
        tip.setPointCount(3); 
        tip.setPoint(0, sf::Vector2f(5.f, 0.f));    // Top point
        tip.setPoint(1, sf::Vector2f(20.f, 30.f));  // Bottom right point
        tip.setPoint(2, sf::Vector2f(-10.f, 30.f)); // Bottom left point
        tip.setFillColor(sf::Color(192, 192, 192)); // Silver color 
        tip.setOutlineColor(sf::Color::Black);      // Outline color
        tip.setOutlineThickness(2.f);               // Thickness of the outline
        tip.setPosition(200.f, 170.f);  // Position the tip to connect with shaft
    }

    void use(sf::RenderWindow& window) override {
        window.draw(shaft);  
        window.draw(tip);   
    }
};
class Sword : public Weapon {
private:
    sf::RectangleShape blade;    
    sf::RectangleShape crossguard;
    sf::RectangleShape handle;     
    sf::ConvexShape tip;         
public:
    Sword() {
        // Blade of the sword
        blade.setSize(sf::Vector2f(10.f, 100.f));  // Width, Height
        blade.setFillColor(sf::Color(192, 192, 192)); // Silver color
        blade.setOutlineColor(sf::Color::Black);      // Outline color
        blade.setOutlineThickness(2.f);               // Thickness of the outline
        blade.setPosition(200.f, 150.f);              // Position the blade

        // Crossguard of the sword
        crossguard.setSize(sf::Vector2f(30.f, 10.f)); // Width, Height
        crossguard.setFillColor(sf::Color(255, 0, 0)); // Red color
        crossguard.setOutlineColor(sf::Color::Black);  // Outline color
        crossguard.setOutlineThickness(2.f);           // Thickness of the outline
        crossguard.setPosition(190.f, 240.f);          // Position the crossguard

        // Handle of the sword
        handle.setSize(sf::Vector2f(10.f, 40.f));      // Width, Height
        handle.setFillColor(sf::Color(0, 128, 0));     // Green color
        handle.setOutlineColor(sf::Color::Black);      // Outline color
        handle.setOutlineThickness(2.f);               // Thickness of the outline
        handle.setPosition(200.f, 250.f);              // Position the handle

        // Tip of the sword (triangle)
        tip.setPointCount(3);  // Triangle has 3 points
        tip.setPoint(0, sf::Vector2f(0.f, 0.f));      // Top point of the triangle
        tip.setPoint(1, sf::Vector2f(10.f, 10.f));    // Right point
        tip.setPoint(2, sf::Vector2f(-10.f, 10.f));   // Left point
        tip.setFillColor(sf::Color(192, 192, 192));   // Silver color for the tip
        tip.setOutlineColor(sf::Color::Black);        // Black outline for the tip
        tip.setOutlineThickness(2.f);                  // Outline thickness for the tip
        tip.setPosition(205.f, 140.f);                 // Position the tip at the top of the blade
    }

    void use(sf::RenderWindow& window) override {
        window.draw(tip);        
        window.draw(blade);      
        window.draw(crossguard); 
        window.draw(handle);    
    }
};

class BurningSword : public Sword {
private:
    sf::ConvexShape flame; 
public:
    BurningSword() : Sword() {
        flame.setPointCount(5); // Points to create a flame shape
        flame.setPoint(0, sf::Vector2f(10.f, 120.f));  // Bottom
        flame.setPoint(1, sf::Vector2f(-20.f, 80.f));  // Left middle
        flame.setPoint(2, sf::Vector2f(10.f, 40.f));   // Top
        flame.setPoint(3, sf::Vector2f(40.f, 80.f));   // Right middle
        flame.setPoint(4, sf::Vector2f(10.f, 120.f));  // Bottom

        // Set the color and position of the flame
        flame.setFillColor(sf::Color(0xFFA500FF));    
        flame.setOutlineColor(sf::Color::Red);         // Red outline
        flame.setOutlineThickness(2.f);                // Thickness of the outline
        flame.setPosition(200.f, 130.f);               // Position the flame to align with the blade
    }

    void use(sf::RenderWindow& window) override {
        window.draw(flame);   
        Sword::use(window); 
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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Weapon Display");
    int level = 3;  //// level
    auto weapon = getWeaponForLevel(level);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();  
        if (weapon) {
            weapon->use(window);  
        }
        window.display(); 
    }

    return 0;
}
