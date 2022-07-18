#include <iostream>
#include "cmath"
#include "SFML/Graphics.hpp"
#include "Node.h"
#include "InsertLineMenu/InsertLineMenuController.h"
#include "InsertLineMenu/InsertLineMenuModel.h"
#include "InsertLineMenu/InsertLineMenuRender.h"
#include "InsertLinesMenu/InsertLinesMenuController.h"
#include "InsertLinesMenu/InsertLinesMenuModel.h"
#include "InsertLinesMenu/InsertLinesMenuRender.h"

int scene_x = 10000;
int scene_y = 10000;

int lx = -scene_x * 0.0625, rx = scene_x * 0.0625;
int ly = -scene_y * 0.0625, ry = scene_y * 0.0625;

std::string first_line;
std::string second_line;
std::string third_line;
Node* first_function;
Node* second_function;
Node* third_function;

inline bool Line1(int y, int x) {
    return -(y / 100.) > 4 * (x / 100.) - 13;
}

bool Line2(int y, int x) {
    return -(y / 100.) > (-3) * (x / 100.) - 5;
}

bool isOutTurnedParabola1(int y, int x) {
    return (y / 100. + 1) * (y / 100. + 1) > -0.65 * (x / 100.) - 0.3;
}

bool isOutTurnedParabola2(int y, int x) {
    return (-y / 100. + 4) * (-y / 100. + 4) > -0.65 * (x / 100.) + 1.95;
}

bool isOutCircle(int y, int x) {
    return (x / 100. + 5) * (x / 100. + 5) + (-y / 100. + 3.5) * (-y / 100. + 3.5) < (2.5) * (2.5);
}

bool isOutInvertedParabola(int y, int x) {
    return -y / 100. > -1.1 * (x / 100. + 5.5) * (x / 100. + 5.5) + 0.5;
}

bool isOutRhombus(int y, int x) {
    return fabs(x / 100. - 2) + fabs(-y / 100. + 1) / 0.5 > 1;
}

bool isOutRectangle(int y, int x) {
    return x > -100 && x < -50 && y > -600 && y < -350;
}

void drawLines(sf::RenderWindow &window) {
//    sf::VertexArray line1(sf::Quads);
//    sf::Vertex v1;
//    v1.position = sf::Vector2f((-ly / 100. + 13) / 4 * 100 + 3 + scene_x / 2, ly + scene_y / 2);
//    v1.color = sf::Color::Black;
//    line1.append(v1);
//    v1.position = sf::Vector2f((-ly / 100. + 13) / 4 * 100 + scene_x / 2, ly + scene_y / 2);
//    v1.color = sf::Color::Black;
//    line1.append(v1);
//    v1.position = sf::Vector2f((-ry / 100. + 13) / 4 * 100 + scene_x / 2, ry + scene_y / 2);
//    v1.color = sf::Color::Black;
//    line1.append(v1);
//    v1.position = sf::Vector2f((-ry / 100. + 13) / 4 * 100 + 3 + scene_x / 2, ry + scene_y / 2);
//    v1.color = sf::Color::Black;
//    line1.append(v1);
//    window.draw(line1);
//
//    sf::VertexArray line2(sf::Quads);
//    sf::Vertex v2;
//    v2.position = sf::Vector2f((-ly / 100. + 5) / -3 * 100 + 3 + scene_x / 2, ly + scene_y / 2);
//    v2.color = sf::Color::Black;
//    line2.append(v2);
//    v2.position = sf::Vector2f((-ly / 100. + 5) / -3 * 100 + scene_x / 2, ly + scene_y / 2);
//    v2.color = sf::Color::Black;
//    line2.append(v2);
//    v2.position = sf::Vector2f((-ry / 100. + 5) / -3 * 100 + scene_x / 2, ry + scene_y / 2);
//    v2.color = sf::Color::Black;
//    line2.append(v2);
//    v2.position = sf::Vector2f((-ry / 100. + 5) / -3 * 100 + 3 + scene_x / 2, ry + scene_y / 2);
//    v2.color = sf::Color::Black;
//    line2.append(v2);
//    window.draw(line2);
//
//    sf::CircleShape shape(250);
//    shape.setFillColor(sf::Color(150, 50, 250, 0));
//    shape.setOutlineThickness(3);
//    shape.setOutlineColor(sf::Color(0, 0, 0));
//    shape.setPosition(-750 + scene_x / 2, 100 + scene_y / 2);
//    window.draw(shape);
//
//    sf::VertexArray diamondl1(sf::Quads);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 50 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl1.append(v1);
//    v1.position = sf::Vector2f(100 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl1.append(v1);
//    v1.position = sf::Vector2f(105 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl1.append(v1);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 53 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl1.append(v1);
//    window.draw(diamondl1);
//
//    sf::VertexArray diamondl2(sf::Quads);
//    v1.position = sf::Vector2f(100 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl2.append(v1);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 150 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl2.append(v1);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 153 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl2.append(v1);
//    v1.position = sf::Vector2f(95 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl2.append(v1);
//    window.draw(diamondl2);
//
//    sf::VertexArray diamondl3(sf::Quads);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 150 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl3.append(v1);
//    v1.position = sf::Vector2f(297 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl3.append(v1);
//    v1.position = sf::Vector2f(302 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl3.append(v1);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 153 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl3.append(v1);
//    window.draw(diamondl3);
//
//    sf::VertexArray diamondl4(sf::Quads);
//    v1.position = sf::Vector2f(297 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl4.append(v1);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 53 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl4.append(v1);
//    v1.position = sf::Vector2f(200 + scene_x / 2, 50 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl4.append(v1);
//    v1.position = sf::Vector2f(302 + scene_x / 2, 100 + scene_y / 2);
//    v1.color = sf::Color::Black;
//    diamondl4.append(v1);
//    window.draw(diamondl4);
//
//    sf::RectangleShape rectangle;
//    rectangle.setSize(sf::Vector2f(56, 303));
//    rectangle.setFillColor(sf::Color::Black);
//    rectangle.setPosition(-103 + scene_x / 2, -600 + scene_y / 2);
//    window.draw(rectangle);
//    rectangle.setSize(sf::Vector2f(50, 300));
//    rectangle.setFillColor(sf::Color::White);
//    rectangle.setPosition(-100 + scene_x / 2, -600 + scene_y / 2);
//    window.draw(rectangle);
//
//    for (int i = lx; i < rx; i++) {  //Drawing isOutTurnedParabola2;
//        if (-65 * i + 19500 >= 0) {
//            int j = int(sqrt(-65 * i + 19500));
//            sf::RectangleShape l;
//            l.setSize(sf::Vector2f(2, 2));
//            l.setPosition(i + scene_x / 2, j + 400 + scene_y / 2);
//            l.setFillColor(sf::Color(0, 0, 0));
//            window.draw(l);
//            l.setPosition(i + scene_x / 2, -j + 400 + scene_y / 2);
//            window.draw(l);
//        }
//    }
//
//    for (int i = lx; i < rx; i++) {  //Drawing isOutTurnedParabola1;
//        if (-65 * i - 3000 >= 0) {
//            int j = int(sqrt(-65 * i - 3000));
//            sf::RectangleShape l;
//            l.setSize(sf::Vector2f(2, 2));
//            l.setPosition(i + scene_x / 2, j - 100 + scene_y / 2);
//            l.setFillColor(sf::Color(0, 0, 0));
//            window.draw(l);
//            l.setPosition(i + scene_x / 2, -j - 100 + scene_y / 2);
//            window.draw(l);
//        }
//    }
//
//    for (int i = lx; i < rx; i++) {  //Drawing isOutTurnedParabola1;
//        int j = int(sqrt(-65 * i - 3000));
//        j = -0.011 * (i + 550) * (i + 550) + 50;
//        sf::RectangleShape l;
//        l.setSize(sf::Vector2f(4, 4));
//        l.setPosition(i + scene_x / 2, -j + scene_y / 2);
//        l.setFillColor(sf::Color(0, 0, 0));
//        window.draw(l);
////        l.setPosition(i + scene_x / 2, -j - 100 + scene_y / 2);
////        window.draw(l);
//    }

//    for (int i = lx; i < rx; i++) {  //Drawing sin(x);
//        int j = int(sqrt(-65 * i - 3000));
//        j = sin(0.01 * i) * 100;
//        //std::cout << sin(i) << '\n';
//        sf::RectangleShape l;
//        l.setSize(sf::Vector2f(4, 4));
//        l.setPosition(i + scene_x / 2, -j + scene_y / 2);
//        l.setFillColor(sf::Color(0, 0, 0));
//        window.draw(l);
//    }

    sf::VertexArray line(sf::LineStrip);
    for (int i = lx; i < rx; i++) {  //Drawing sin(x);
        int j = int(sqrt(-65 * i - 3000));
        j = cos(-0.01 * i) * 100;
        try {
            j = Count(first_function, i * 0.01) * 100;
        } catch (std::invalid_argument& error){
            window.draw(line);
            line.clear();
            continue;
        }
        //if (0.01 * i < 0.5) continue;
        //j = sqrt(0.01 * i - 0.5) * 100;
        //j = std::pow(i * 0.01 + 2, 2) * 100;
        //std::cout << sin(i) << '\n';
//        sf::RectangleShape l;
//        l.setSize(sf::Vector2f(4, 4));
//        l.setPosition(i + scene_x / 2, -j + scene_y / 2);
//        l.setFillColor(sf::Color(0, 0, 0));
        //window.draw(l);

        int i_cur = i + scene_x / 2;
        int j_cur = -j + scene_y / 2;

        line.append(sf::Vertex(sf::Vector2f(i_cur, j_cur)));
        line[line.getVertexCount() - 1].color = sf::Color::Red;
    }
    window.draw(line);

    line.clear();
    for (int i = lx; i < rx; i++) {  //Drawing sin(x);
        int j = 0;
        try {
            j = Count(second_function, i * 0.01) * 100;
        } catch (std::invalid_argument& error){
            window.draw(line);
            line.clear();
            continue;
        }

        int i_cur = i + scene_x / 2;
        int j_cur = -j + scene_y / 2;

        line.append(sf::Vertex(sf::Vector2f(i_cur, j_cur)));
        line[line.getVertexCount() - 1].color = sf::Color::Blue;
    }
    window.draw(line);

    line.clear();
    for (int i = lx; i < rx; i++) {  //Drawing sin(x);
        int j = 0;
        try {
            j = Count(third_function, i * 0.01) * 100;
        } catch (std::invalid_argument& error){
            window.draw(line);
            line.clear();
            continue;
        }

        int i_cur = i + scene_x / 2;
        int j_cur = -j + scene_y / 2;

        line.append(sf::Vertex(sf::Vector2f(i_cur, j_cur)));
        line[line.getVertexCount() - 1].color = sf::Color::Black;
    }
    window.draw(line);
}

void drawAreas(sf::RenderWindow &window, sf::View &view) {
//    sf::Image image;
//    image.create(rx - lx, ry - ly);
//    for (int i = lx; i < rx; i += 1) {
//        for (int j = ly; j < ry; j += 1) {
//            if ((Line1(j, i) && Line2(j, i) && isOutTurnedParabola1(j, i) && isOutTurnedParabola2(j, i) &&
//                 isOutRhombus(j, i)
//                 && !isOutRectangle(j, i))
//                || (!isOutTurnedParabola2(j, i) && !Line1(j, i))
//                || (isOutCircle(j, i) && !isOutTurnedParabola2(j, i) && isOutInvertedParabola(j, i))
//                || /*(!isOutCircle(j, i) && isOutTurnedParabola2(j, i) && isOutTurnedParabola1(j, i) && !Line2(j, i)
//                    && isOutInvertedParabola(j, i) && i > - 500 && i < 0 && j > -100 && j < 300)
//                ||*/ (i > -320 && j > 400 && !Line2(j, i) && isOutTurnedParabola2(j, i)) &&
//                     isOutInvertedParabola(j, i) && Line1(j, i)
//                || (j < 0 && !isOutInvertedParabola(j, i))) {
//
//                image.setPixel(i - lx, j - ly, sf::Color(0, 165, 207));
////                sf::RectangleShape l;
////                l.setSize(sf::Vector2f(2, 2));
////                l.setPosition(i + scene_x / 2, j + scene_y / 2);
////                l.setFillColor(sf::Color(0, 165, 207));
////                window.draw(l);
//            } else {
//                image.setPixel(i - lx, j - ly, sf::Color(255, 255, 255));
//            }
//        }
//    }
//    sf::Texture texture;
//    texture.loadFromImage(image);
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
//    sprite.setPosition(lx + scene_x / 2, ly + scene_y / 2);
//    window.draw(sprite);
    drawLines(window);
}

void drawGrid(sf::RenderWindow &window, sf::View &view) {
    for (int i = 0; i < scene_x; i += 100) {
        if (i >= lx + scene_x / 2 && i <= rx + scene_x / 2) {
            sf::RectangleShape l;
            l.setSize(sf::Vector2f(scene_y, 1.5));
            l.rotate(90);
            l.setPosition(i, 0);
            if (i == scene_x / 2) {
                l.setSize(sf::Vector2f(scene_y, 4));
            }
            l.setFillColor(sf::Color::Black);
            window.draw(l);
        }
    }
    for (int i = 0; i < scene_x; i += 100) {
        if (i >= ly + scene_y / 2 && i <= ry + scene_y / 2) {
            sf::RectangleShape l;
            l.setSize(sf::Vector2f(scene_x, 1.5));
            l.setPosition(0, i);
            if (i == scene_y / 2) {
                l.setSize(sf::Vector2f(scene_x, 4));
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
    view.zoom(0.125);
    window.setView(view);
    int zoom_count = 0;
    double zoom_factor = 1;

    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color(156, 156, 156));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Button::Left){
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                    auto button_pos = rectangle.getPosition();
                    if (button_pos.x < worldPos.x && worldPos.x < button_pos.x + rectangle.getSize().x &&
                        button_pos.y < worldPos.y && worldPos.y < button_pos.y + rectangle.getSize().y){
                        //std::cout << "button pressed\n";
                        InsertLinesMenuModel model(&first_line, &second_line, &third_line);
                        InsertLinesMenuRender render(&model);
                        InsertLinesMenuController controller(&model, &render);
                        controller.Run();
                        Build(first_function, model.getStringToInsert());
                        Build(second_function, model.getPosToInsertString());
                        Build(third_function, model.getNInsertsString());
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Z && zoom_count > -3) {
                    view.zoom(0.5);
                    zoom_factor /= 2;
                    int mid_x = rx - lx;
                    int mid_y = ry - ly;
                    rx -= mid_x / 4;
                    lx += mid_x / 4;
                    ry -= mid_y / 4;
                    ly += mid_y / 4;
                    zoom_count--;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::X && zoom_count < 1) {
                    view.zoom(2);
                    zoom_factor *= 2;
                    int mid_x = rx - lx;
                    int mid_y = ry - ly;
                    rx += mid_x / 2;
                    lx -= mid_x / 2;
                    ry += mid_y / 2;
                    ly -= mid_y / 2;
                    zoom_count++;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::A) {
                    view.move(-50, 0);
                    lx -= 50;
                    rx -= 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::D) {
                    view.move(+50, 0);
                    lx += 50;
                    rx += 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::W) {
                    view.move(0, -50);
                    ly -= 50;
                    ry -= 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::S) {
                    view.move(0, 50);
                    ly += 50;
                    ry += 50;
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::T) {
                    std::cout << lx << " " << rx << '\n';
                    std::cout << ly << " " << ry << '\n';
                }
            }
        }

        window.clear(sf::Color::White);
        drawAreas(window, view);
        drawGrid(window, view);
        rectangle.setSize(sf::Vector2f(80 * zoom_factor, 80 * zoom_factor));
        rectangle.setPosition(view.getCenter().x - (rx - lx) / 2 + 10 * zoom_factor, view.getCenter().y - (ry - ly) / 2 + 10 * zoom_factor);
        window.draw(rectangle);
        window.display();
    }
    return 0;
}