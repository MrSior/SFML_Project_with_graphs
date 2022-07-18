//
// Created by Семён Чубенко on 11.11.2021.
//

#ifndef TEXTEDITOR_INSERTLINESMENUMODEL_H
#define TEXTEDITOR_INSERTLINESMENUMODEL_H

#include "string"
#include "vector"

class InsertLinesMenuModel {
private:
    std::vector<std::string*> line_n_pos;
    int current_cursor_pos;
    int current_line;
    int max_symbols_in_line;
    bool is_insert;
public:
    InsertLinesMenuModel(std::string* first_line, std::string* second_line, std::string* third_line);
    void init(std::string* first_line, std::string* second_line, std::string* third_line);
    void insertSymbol(char symbol);
    void eraseSymbol();
    void setCurrentCursorPosition(int pos);
    void setCurrentLine(int pos);
    int getCurrentCursorPosition();
    int getCurrentLine();
    std::string getStringToInsert();
    std::string getPosToInsertString();
    std::string getNInsertsString();
    int getPosToInsert();
    int getNInserts();
    bool getIsInsert();
    void setIsInsert(bool isInsert);
};


#endif //TEXTEDITOR_INSERTLINESMENUMODEL_H
