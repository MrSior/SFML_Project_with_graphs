//
// Created by Семён Чубенко on 11.11.2021.
//

#include "InsertLinesMenuRender.h"

InsertLinesMenuRender::InsertLinesMenuRender(InsertLinesMenuModel *model) {
    m_model = model;
    init();
}

void InsertLinesMenuRender::init() {
    window_x = 946;
    window_y = 155;
    m_window.create(sf::VideoMode(window_x, window_y), "Text Editor", sf::Style::Close | sf::Style::Titlebar);
    font.loadFromFile("./Fonts/Courier New.ttf");
}

void InsertLinesMenuRender::Render() {
    m_window.clear(sf::Color(9,31,47));
    m_window.draw(*this);
    m_window.display();
}

void InsertLinesMenuRender::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::RectangleShape cursor(sf::Vector2f(25, 45));
    if (m_model->getCurrentLine() == 0) {
        cursor.setPosition(22 * (m_model->getCurrentCursorPosition() + 4) + 10, 7 + m_model->getCurrentLine() * 45);
    } else if (m_model->getCurrentLine() == 1) {
        cursor.setPosition(22 * (m_model->getCurrentCursorPosition() + 5) + 10, 7 + m_model->getCurrentLine() * 45);
    } else {
        cursor.setPosition(22 * (m_model->getCurrentCursorPosition() + 6) + 10, 7 + m_model->getCurrentLine() * 45);
    }
    cursor.setFillColor(sf::Color(66, 84, 90));
    target.draw(cursor);

    std::string line = "Red)" + m_model->getStringToInsert();
    sf::Text textLine = sf::Text(line, font, 35);
    textLine.setStyle(sf::Text::Bold);
    textLine.setPosition(10, 5);
    target.draw(textLine);

    std::string line2 = "Blue)" + m_model->getPosToInsertString();
    sf::Text textLine2 = sf::Text(line2, font, 35);
    textLine2.setStyle(sf::Text::Bold);
    textLine2.setPosition(10, 50);
    target.draw(textLine2);

    std::string line3 = "Black)" + m_model->getNInsertsString();
    sf::Text textLine3 = sf::Text(line3, font, 35);
    textLine3.setStyle(sf::Text::Bold);
    textLine3.setPosition(10, 95);
    target.draw(textLine3);
}