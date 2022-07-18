//
// Created by Семён Чубенко on 11.11.2021.
//

#ifndef TEXTEDITOR_INSERTLINESMENURENDER_H
#define TEXTEDITOR_INSERTLINESMENURENDER_H

#include "SFML/Graphics.hpp"
#include "InsertLinesMenuModel.h"

class InsertLinesMenuRender : public sf::Drawable, public sf::Transformable {
private:
    InsertLinesMenuModel* m_model;
    sf::RenderWindow m_window;
    sf::Font font;
    int window_x, window_y;
public:
    InsertLinesMenuRender(InsertLinesMenuModel* model);
    sf::RenderWindow& window() { return m_window; };

    void init();
    void Render();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //TEXTEDITOR_INSERTLINESMENURENDER_H
