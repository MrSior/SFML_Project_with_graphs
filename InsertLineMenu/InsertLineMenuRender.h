//
// Created by Семён Чубенко on 11.11.2021.
//

#ifndef TEXTEDITOR_INSERTLINEMENURENDER_H
#define TEXTEDITOR_INSERTLINEMENURENDER_H

#include "SFML/Graphics.hpp"
#include "InsertLineMenuModel.h"

class InsertLineMenuRender : public sf::Drawable, public sf::Transformable {
private:
    InsertLineMenuModel* m_model;
    sf::RenderWindow m_window;
    sf::Font font;
    int window_x, window_y;
public:
    InsertLineMenuRender(InsertLineMenuModel* model);
    sf::RenderWindow& window() { return m_window; };

    void init();
    void Render();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //TEXTEDITOR_INSERTLINEMENURENDER_H
