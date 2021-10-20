#include <iostream>
#include "cmath"
#include "SFML/Graphics.hpp"

int scene_x = 10000;
int scene_y = 10000;

int lx = -scene_x * 0.25, rx = scene_x * 0.25;
int ly = -scene_y * 0.25, ry = scene_y * 0.25;

bool Line1(int y, int x){
    return -(y / 100.) > 4 * (x / 100.) - 13;
}

bool Line2(int y, int x){
    return -(y / 100.) > (-3) * (x / 100.) - 5;
}

bool turnedParabola1(int y, int x){
    return (y / 100. + 1) * (y / 100. + 1) > -0.65 * (x / 100.) - 0.3;
}

bool turnedParabola2(int y, int x){
    return (-y / 100. + 4) * (-y / 100. + 4) > -0.65 * (x / 100.) + 1.95;
}

bool circle(int y, int x){
    return (x / 100. + 5) * (x / 100. + 5) + (-y / 100. + 2.5) * (-y / 100. + 2.5) < 2.35;
}

bool invertedParabola(int y, int x){
    return -y / 100. > -1.1 * (x / 100. + 5.5) * (x / 100. + 5.5) + 0.5;
}

bool rhombus(int y, int x){
    return fabs(x / 100. - 2) + fabs(-y / 100. + 1) / 0.5 > 1;
}

bool rectangle(int y, int x){
    return x > -100 && x < -50 && y > -600 && y < -350;
}

void drawAreas(sf::RenderWindow& window, sf::View& view){
    sf::Image image;

    image.create(rx - lx, ry - ly);
    for(int i = lx; i < rx; i+=1){
        for(int j = ly; j < ry; j+=1){
            if ((Line1(j, i) && Line2(j, i) && turnedParabola1(j, i) && turnedParabola2(j, i) && rhombus(j, i)
                 && !rectangle(j, i))
                || (!turnedParabola2(j, i) && !Line1(j, i))
                || (circle(j, i) && !turnedParabola2(j, i) && invertedParabola(j, i))
                || (!circle(j, i) && turnedParabola2(j, i) && turnedParabola1(j, i) && !Line2(j, i)
                    && invertedParabola(j, i) && i > - 500 && i < 0 && j > -100 && j < 300)
                || (i > -320 && j > 400 && !Line2(j, i) && turnedParabola2(j, i)) && invertedParabola(j, i) && Line1(j, i)){

                image.setPixel(i - lx, j - ly, sf::Color(0, 165, 207));
//                sf::RectangleShape l;
//                l.setSize(sf::Vector2f(2, 2));
//                l.setPosition(i + scene_x / 2, j + scene_y / 2);
//                l.setFillColor(sf::Color(0, 165, 207));
//                window.draw(l);
            }
            else {
                image.setPixel(i - lx, j - ly, sf::Color(255, 255, 255));
            }
        }
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(lx + scene_x / 2, ly + scene_y / 2);
    window.draw(sprite);
}

void drawGrid(sf::RenderWindow& window, sf::View& view){
    for(int i = 0; i < scene_x; i += 100){
        if (i >= lx + scene_x / 2 && i <= rx + scene_x / 2) {
            sf::RectangleShape l;
            l.setSize(sf::Vector2f(scene_y, 3));
            l.rotate(90);
            l.setPosition(i, 0);
            if (i == scene_x / 2) {
                l.setSize(sf::Vector2f(scene_y, 7));
            }
            l.setFillColor(sf::Color::Black);
            window.draw(l);
        }
    }
    for(int i = 0; i < scene_x; i += 100){
        if (i >= ly + scene_y / 2 && i <= ry + scene_y / 2) {
            sf::RectangleShape l;
            l.setSize(sf::Vector2f(scene_x, 3));
            l.setPosition(0, i);
            if (i == scene_y / 2) {
                l.setSize(sf::Vector2f(scene_x, 7));
            }
            l.setFillColor(sf::Color::Black);
            window.draw(l);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::View view(sf::FloatRect(0.f, 0.f, scene_x, scene_y));
    view.setCenter(scene_x / 2, scene_y / 2);
    view.zoom(0.25);
    window.setView(view);
    int zoom_count = 0;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Z && zoom_count > -3){
                    view.zoom(0.5);
                    rx /= 2; rx+=100;
                    lx /= 2; lx-=100;
                    ry /= 2; ry+=100;
                    ly /= 2; ly-=100;
                    zoom_count--;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::X && zoom_count < 1){
                    view.zoom(2);
                    rx *= 2; rx+=100;
                    lx *= 2; lx-=100;
                    ry *= 2; ry+=100;
                    ly *= 2; ly-=100;
                    zoom_count++;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::A){
                    view.move(-50, 0);
                    lx -= 50;
                    rx -= 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::D){
                    view.move(+50, 0);
                    lx += 50;
                    rx += 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::W){
                    view.move(0, -50);
                    ly -= 50;
                    ry -= 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::S){
                    view.move(0, 50);
                    ly += 50;
                    ry += 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::T){
                    std::cout << lx << " " << rx << '\n';
                    std::cout << ly << " " << ry << '\n';
                }
            }
        }

        window.clear(sf::Color::White);
        drawAreas(window, view);
        drawGrid(window, view);
        window.display();
    }
    return 0;
}