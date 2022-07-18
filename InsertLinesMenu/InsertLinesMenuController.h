//
// Created by Семён Чубенко on 11.11.2021.
//

#ifndef TEXTEDITOR_INSERTLINESMENUCONTROLLER_H
#define TEXTEDITOR_INSERTLINESMENUCONTROLLER_H

#include "InsertLinesMenuModel.h"
#include "InsertLinesMenuRender.h"

class InsertLinesMenuController {
private:
    InsertLinesMenuModel* m_model;
    InsertLinesMenuRender* m_render;
public:
    InsertLinesMenuController(InsertLinesMenuModel* model, InsertLinesMenuRender* render);
    void Run();
};


#endif //TEXTEDITOR_INSERTLINESMENUCONTROLLER_H
