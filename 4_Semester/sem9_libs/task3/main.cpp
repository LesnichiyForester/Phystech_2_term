#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int height = 800;
    int width = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(60);

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Yellow);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    
    float angle = 0;
    float radius = 300;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        angle += 0.03;
        float x = width / 2 + radius * std::cos(angle);
        float y = height / 2 + radius * std::sin(angle);
        circle.setPosition(x, y);

        window.clear();
        window.draw(circle);
        window.display();
    }
}