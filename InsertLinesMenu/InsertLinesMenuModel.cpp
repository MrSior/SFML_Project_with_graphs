//
// Created by Семён Чубенко on 11.11.2021.
//

#include "InsertLinesMenuModel.h"

InsertLinesMenuModel::InsertLinesMenuModel(std::string* first_line, std::string* second_line, std::string* third_line){
    init(first_line, second_line, third_line);
}

void InsertLinesMenuModel::init(std::string* first_line, std::string* second_line, std::string* third_line) {
    line_n_pos.emplace_back(first_line);
    line_n_pos.emplace_back(second_line);
    line_n_pos.emplace_back(third_line);
    current_cursor_pos = 0;
    current_line = 0;
    max_symbols_in_line = 30;
    is_insert = false;
}

void InsertLinesMenuModel::insertSymbol(char symbol) {
    if (line_n_pos[current_line]->length() < max_symbols_in_line) {
        line_n_pos[current_line]->insert(line_n_pos[current_line]->begin() + current_cursor_pos, symbol);
        setCurrentCursorPosition(getCurrentCursorPosition() + 1);
    }
}

void InsertLinesMenuModel::eraseSymbol() {
    if (!line_n_pos[current_line]->empty()) {
        line_n_pos[current_line]->erase(line_n_pos[current_line]->begin() + current_cursor_pos - 1);
        setCurrentCursorPosition(getCurrentCursorPosition() - 1);
    }
}

void InsertLinesMenuModel::setCurrentCursorPosition(int pos) {
    if (pos >= 0 && pos <= line_n_pos[current_line]->length()){
        current_cursor_pos = pos;
    } else if (pos >= 0 && pos > line_n_pos[current_line]->length()){
        current_cursor_pos = line_n_pos[current_line]->length();
    }
}

void InsertLinesMenuModel::setCurrentLine(int pos) {
    if (pos >= 0 && pos <= 2){
        current_line = pos;
        setCurrentCursorPosition(current_cursor_pos);
    }
}

int InsertLinesMenuModel::getCurrentCursorPosition() {
    return current_cursor_pos;
}

int InsertLinesMenuModel::getCurrentLine() {
    return current_line;
}

std::string InsertLinesMenuModel::getStringToInsert() {
    return *line_n_pos[0];
}

int InsertLinesMenuModel::getPosToInsert() {
    if (!line_n_pos[1]->empty()) {
        return std::stoi(*line_n_pos[1]);
    }
    return 1;
}

std::string InsertLinesMenuModel::getPosToInsertString() {
    return *line_n_pos[1];
}

std::string InsertLinesMenuModel::getNInsertsString() {
    return *line_n_pos[2];
}

int InsertLinesMenuModel::getNInserts() {
    return std::stoi(*line_n_pos[2]);
}

bool InsertLinesMenuModel::getIsInsert() {
    return is_insert;
}

void InsertLinesMenuModel::setIsInsert(bool isInsert) {
    is_insert = isInsert;
}
