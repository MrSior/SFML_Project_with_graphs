//
// Created by Семён Чубенко on 11.11.2021.
//

#ifndef TEXTEDITOR_INSERTLINEMENUCONTROLLER_H
#define TEXTEDITOR_INSERTLINEMENUCONTROLLER_H

#include "InsertLineMenuModel.h"
#include "InsertLineMenuRender.h"

class InsertLineMenuController {
private:
    InsertLineMenuModel* m_model;
    InsertLineMenuRender* m_render;
public:
    InsertLineMenuController(InsertLineMenuModel* model, InsertLineMenuRender* render);
    void Run();
};


#endif //TEXTEDITOR_INSERTLINEMENUCONTROLLER_H
