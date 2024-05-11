#include <iostream>
#include <cmath>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "context_menu.hpp"

// Вспомогательные функции, вычисляет расстояние между двумя точками
float distance(sf::Vector2f start, sf::Vector2f finish)
{
    return std::sqrt((start.x - finish.x)*(start.x - finish.x) + (start.y - finish.y)*(start.y - finish.y));
}

// Вспомогательные функции, рисует линию на холсте окна window
void drawLine(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f finish, sf::Color color = sf::Color::White)
{
    sf::Vertex line_vertices[2] = {sf::Vertex(start, color), sf::Vertex(finish, color)};
    window.draw(line_vertices, 2, sf::Lines);
}

//  Вспомагательный класс, описывет шарик
//      position - положение шарика; radius - радиус
//      isChosen - говорит о том, выбран ли шарик или нет
struct Ball
{
    sf::Vector2f position;
    float radius;
    bool isChosen;
    sf::Color color; // Код по заданию

    Ball(sf::Vector2f position, float radius, sf::Color color) : position(position), radius(radius), color(color)
    {
        isChosen = false;
    }

    // Метод, который рисует шарик на холст окна window
    void draw(sf::RenderWindow& window) const
    {
        // Тут рисуем белый кружочек
        sf::CircleShape circle(radius);
        circle.setFillColor(color);
        circle.setOrigin({radius, radius});
        circle.setPosition(position);
        window.draw(circle);

        // Если шарик выбран
        if (isChosen) 
        {
            // То рисуем "уголки"
            const float fraction = 0.7;
            drawLine(window, {position.x - radius, position.y + radius}, {position.x - radius, position.y + radius*fraction});
            drawLine(window, {position.x - radius, position.y + radius}, {position.x - fraction * radius, position.y + radius});

            drawLine(window, {position.x + radius, position.y + radius}, {position.x + radius, position.y + radius*fraction});
            drawLine(window, {position.x + radius, position.y + radius}, {position.x + radius*fraction, position.y + radius});

            drawLine(window, {position.x + radius, position.y - radius}, {position.x + radius*fraction, position.y - radius});
            drawLine(window, {position.x + radius, position.y - radius}, {position.x + radius, position.y - radius*fraction});

            drawLine(window, {position.x - radius, position.y - radius}, {position.x - radius*fraction, position.y - radius});
            drawLine(window, {position.x - radius, position.y - radius}, {position.x - radius, position.y - radius*fraction});
        }
    }

    bool is_inside_rectangle(sf::RectangleShape& rect) { // Код по заданию
    if ((this->position.x + this->radius <= rect.getPosition().x + rect.getSize().x &&
         this->position.x - this->radius >= rect.getPosition().x &&
         this->position.y - this->radius >= rect.getPosition().y &&
         this->position.y + this->radius <= rect.getPosition().y + rect.getSize().y) ||
        (this->position.x - this->radius >= rect.getPosition().x + rect.getSize().x &&
         this->position.x + this->radius <= rect.getPosition().x &&
         this->position.y + this->radius <= rect.getPosition().y &&
         this->position.y - this->radius >= rect.getPosition().y + rect.getSize().y) ||
        (this->position.x + this->radius <= rect.getPosition().x + rect.getSize().x &&
         this->position.x - this->radius >= rect.getPosition().x &&
         this->position.y + this->radius <= rect.getPosition().y &&
         this->position.y - this->radius >= rect.getPosition().y + rect.getSize().y) ||
        (this->position.x - this->radius >= rect.getPosition().x + rect.getSize().x &&
         this->position.x + this->radius <= rect.getPosition().x &&
         this->position.y - this->radius >= rect.getPosition().y &&
         this->position.y + this->radius <= rect.getPosition().y + rect.getSize().y))
        return true;
    return false;
}
 };


int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Select, Move, Delete!", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::Color colors[] = {sf::Color::White, sf::Color::Red, sf::Color::Green, sf::Color::Blue, 
                          sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan};
    int randomIndex = 0;
    std::vector<sf::String> contextMenuStrings {"Add Button", "Cut", "Copy", "Paste", "Select All"};

        sf::Font font;
    if (!font.loadFromFile("consolas.ttf")) {
        std::cout << "Can't load button font" << std::endl;
    }

    // Создаём связный список из шариков
    // Связный список -- потому что нам нужно будет постоянно удалять и добавлять в этот список
    sf::Color curColor = sf::Color::White;
    std::list<Ball> balls;
    balls.push_back(Ball({200, 200}, 26, curColor));
    balls.push_back(Ball({400, 300}, 20, curColor));
    balls.push_back(Ball({500, 100}, 16, curColor));
    balls.push_back(Ball({200, 400}, 18, curColor));
    balls.push_back(Ball({350, 150}, 22, curColor));
    balls.push_back(Ball({750, 400}, 21, curColor));


    // Создаём прямоугольник выделения
    // Обратите внимание на четвёртый параметр FillColor, он равен 50.
    // Это alpha - прозрачность      0 = полностью прозрачный     255 = непрозрачный
    sf::RectangleShape selectionRect;
    selectionRect.setFillColor(sf::Color(150, 150, 240, 50));
    selectionRect.setOutlineColor(sf::Color(200, 200, 255));
    selectionRect.setOutlineThickness(1);

    // Специальная переменная, которая будет показывать, что мы находимся в режиме выделения
    bool isSelecting = false;
    bool wasPressedOutsideCircle = true;
    sf::Vector2f offset = {0, 0};
    sf::Vector2f prevMousePos = {0, 0};

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            
            if (event.type == sf::Event::MouseMoved) 
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
                
                // Если мы находимся в режиме выделения, то меняем прямоугольник выделения
                if (isSelecting && wasPressedOutsideCircle) { // Код по заданию: выделение объектов
                    selectionRect.setSize(mousePosition - selectionRect.getPosition());
                    for (Ball& b : balls) {
                        if (b.is_inside_rectangle(selectionRect))
                            b.isChosen = true;
                        else
                            b.isChosen = false; 
                    }
                }
                else if (isSelecting && !wasPressedOutsideCircle) { // Код по заданию: перетаскивание
                    for (Ball& b : balls) {
                        if (b.isChosen)
                            b.position += mousePosition - prevMousePos;
                    }
                }
                prevMousePos = mousePosition;
            }

            if (event.type == sf::Event::MouseButtonPressed) 
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    // Если не зажат левый Ctrl, то все выделения снимаются
                    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)/* && wasPressedOutsideCircle*/)
                    {
                        for (Ball& b : balls)
                            b.isChosen = false;
                    }

                    // Проверяем попал ли курсор в какой-нибудь шарик, если попал - выделяем
                    for (Ball& b : balls)
                        if (distance(mousePosition, b.position) < b.radius) {
                            b.isChosen = true;
                            wasPressedOutsideCircle = false;
                            break;
                        }
                    else
                        wasPressedOutsideCircle = true; 

                    // ЛКМ + левый Alt - добавляем новый случайный шарик
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
                        balls.push_back(Ball(mousePosition, 5 + rand() % 40, curColor));

                    // Задаём новое положения прямоугольника выделения
                    isSelecting = true;
                    selectionRect.setPosition(mousePosition);
                    selectionRect.setSize({0, 0});
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) { // Код по заданию: Меню
                if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::RenderWindow windowMenu(sf::VideoMode(800, 600), "Menu", sf::Style::Default, settings);
                    windowMenu.setFramerateLimit(60);
                    ContextMenu contextMenu(windowMenu, font);
                    for (const auto& el : contextMenuStrings)
                        contextMenu.addButton(el);
                    contextMenu.draw();
                        while (windowMenu.isOpen()) {
                            sf::Event event;
                            while (windowMenu.pollEvent(event)) {
                                if (event.type == sf::Event::MouseButtonPressed)
                                windowMenu.close();
                            }
                        }
                }
            }

            if (event.type == sf::Event::KeyPressed) { // Код по заданию: смена цвета
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        int prevIndex = randomIndex;
                    while (randomIndex == prevIndex)
                        randomIndex = rand() % 7;
                    sf::Color newColor = colors[randomIndex];
                    for (Ball& b : balls)
                        if (b.isChosen == true)
                            b.color = newColor;
                }
            }

            if (event.type == sf::Event::KeyPressed) { // Код по заданию: удаление
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
                    for (auto it = balls.begin(); it != balls.end(); )
                    {
                        if (it->isChosen)
                            it = balls.erase(it); // Erase the object and get the iterator to the next element
                        else
                            ++it;
                    }
                }
            }

            // При отпускании кнопки мыши выходим из режима выделения
            if (event.type == sf::Event::MouseButtonReleased)  {
                isSelecting = false;
                //Код по заданию: выделение/перетаскивание
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                for (Ball& b : balls) {
                    if (distance(mousePosition, b.position) < b.radius && b.isChosen) {
                        for (Ball& b : balls)
                            b.isChosen = false;
                        for (Ball& b : balls)
                        if (distance(mousePosition, b.position) < b.radius) {
                            b.isChosen = true;
                            break;
                        }
                    }
                }
            }        
        }

        window.clear(sf::Color::Black);

        // Рисуем все шарики
        for (Ball& b : balls)
            b.draw(window);

        // Рисуем прямоугольник выделения
        if (isSelecting)
            window.draw(selectionRect);

        window.display();
    }

    return 0;
}