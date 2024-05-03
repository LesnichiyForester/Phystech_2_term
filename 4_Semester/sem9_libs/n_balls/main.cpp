#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

/*Не удалось установить причину, но программа нестабильна и запускается примерно раз через два
Соударения в целом отрабатывают неправильно, хотя по теоретической механике вроед все сходится*/

float length(sf::Vector2f vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

struct Ball
{
    float radius;
    float mass;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float charge;
};

int status_report(Ball ball, int m) {
    cout << m << ball.radius << " " << 
     "(" << ball.position.x << " " << ball.position.y << ") " <<
     "(" << ball.velocity.x << " " << ball.velocity.y << ") " <<
     "(" << ball.acceleration.x << " "<< ball.acceleration.y << ") " <<  endl;
    return 0;
}

int main() {
    srand(time(0));
    
    const int width = 400;
    const int height = 400;
    const int n_balls = 15;

    // Шаг по времени
    const float delta_t = 0.05;

    // Создаём экземпляр класса окно
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    // Задаём максимальное количество кадров в секунду
    window.setFramerateLimit(20);

    // Так как sf::CircleShape занимает много памяти, создаём всего 1 экземпляр
    sf::CircleShape circle(50.0f);
    circle.setFillColor({250, 250, 150});

    std::vector<Ball> balls;
    balls.resize(n_balls);
    for (int i = 0; i < n_balls; i++) {
        balls[i].radius = 4 + rand() % 8;
        balls[i].mass = 4 * balls[i].radius * balls[i].radius;
        balls[i].position = {(float)(rand() % (width - 20)) + 10, (float)(rand() % (height - 20)) + 10};
        balls[i].velocity = {(float)(rand() % 60 - 30), (float)(rand() % 60 - 30)};
        balls[i].acceleration = {0, 0};
        balls[i].charge = rand() / RAND_MAX * 1000 - 500;
    }
    int m = 0;
    while (window.isOpen()) {
        m += 1;
        sf::Event event;
        while (window.pollEvent(event)) {
            // В данном примере проверяем окно на закрытие
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // очистить скрытый холст черным цветом
        window.clear(sf::Color::Black);
        status_report(balls[1], m);

        vector<int> cur_collisions = {};
        for (int i = 0; i < n_balls; i++) {
            // силы и ускорения
            balls[i].acceleration = {0, 0};
            for (int j = 0; j < n_balls; j++) {
                if (i == j)
                    continue;
                float k = (balls[i].charge * balls[j].charge) / balls[i].mass;
                balls[i].acceleration.x += k / (balls[i].position.x - balls[j].position.x) 
                                           / length((balls[i].position - balls[j].position)) 
                                           / length((balls[i].position - balls[j].position)); 
                balls[i].acceleration.y += k / (balls[i].position.y - balls[j].position.y) 
                                           / length((balls[i].position - balls[j].position)) 
                                           / length((balls[i].position - balls[j].position));
            }
            balls[i].velocity += balls[i].acceleration * delta_t;

            //Соударения
            sf::Vector2f r = {0, 0};
            for (int j = 0; j < n_balls; j++) {
                sf::Vector2f r = {0, 0};
                sf::Vector2f normal = {0, 0};
                sf::Vector2f relative_velocity = {0, 0};
                if (i == j or count(cur_collisions.begin(), cur_collisions.end(), j) > 0)
                    continue;
                r = balls[i].position - balls[j].position;
                if (length(r) < balls[i].radius + balls[j].radius) {
                    normal = r / length(r);
                    relative_velocity.x = balls[i].velocity.x - balls[j].velocity.x;
                    relative_velocity.y = balls[i].velocity.y - balls[j].velocity.y;
                    cout << balls[i].velocity.x << " " << balls[j].velocity.x << endl;
                    cout << balls[i].velocity.y << " " << balls[j].velocity.y << endl;
                    cout << relative_velocity.x << " " << balls[i].velocity.x - balls[j].velocity.x << endl;
                    cout << relative_velocity.y << " " << balls[i].velocity.y - balls[j].velocity.y << endl;
                    float dot_product = normal.x * relative_velocity.x + normal.y * relative_velocity.y;
                    if (dot_product < 0) {
                        sf::Vector2f impulse = (2.0f * dot_product / (1 / balls[i].mass + 1 / balls[j].mass)) * normal;
                        balls[i].velocity += impulse / balls[i].mass;
                        balls[j].velocity -= impulse / balls[j].mass;
                        cout << balls[i].velocity.x << " " << balls[j].velocity.x << endl;
                        cout << balls[i].velocity.y << " " << balls[j].velocity.y << endl;
                    }
                }
                cur_collisions.push_back(j);
            }

            // Раздвижение шариков при соударении
            for (int j = 0; j < n_balls; j++) {
                if (i == j)
                    continue;
                r = balls[i].position - balls[j].position;
                if (length(r) < balls[i].radius + balls[j].radius) {
                    balls[i].position += r * static_cast<float>(((balls[i].radius + balls[j].radius) / length(r) - 1) / 2);
                    balls[j].position -= r * static_cast<float>(((balls[i].radius + balls[j].radius) / length(r) - 1) / 2);
                }
            }

            balls[i].position += balls[i].velocity * delta_t;

            if (balls[i].position.x < 0)
                balls[i].velocity.x = -balls[i].velocity.x;
            if (balls[i].position.x > width)
                balls[i].velocity.x = -balls[i].velocity.x;

            if (balls[i].position.y < 0)
                balls[i].velocity.y = -balls[i].velocity.y;
            if (balls[i].position.y > height)
                balls[i].velocity.y = -balls[i].velocity.y;

            // Используем 1 sf::CircleShape, чтобы нарисовать все шары
            circle.setRadius(balls[i].radius);
            // setOrigin - задаёт центр объекта
            // По умолчанию центр - в левом верхнем угле объекта
            // Строка ниже устанавливает центр в центре шарика
            // В дальнейшем функция, setPosition устанавливает положение шарика так, 
            // чтобы его центр был в точке balls[i].position
            circle.setOrigin(balls[i].radius, balls[i].radius);
            circle.setPosition(balls[i].position);
            
            window.draw(circle);
        }
        
        // отображаем содержимое скрытого холста на экран
        window.display();
        //status_report(balls[1], m);
    }
}