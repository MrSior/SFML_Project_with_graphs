//
// Created by Семён Чубенко on 11.11.2021.
//

#include "InsertLineMenuModel.h"

InsertLineMenuModel::InsertLineMenuModel(){
    init();
}

void InsertLineMenuModel::init() {
    InsertingStringAndItPos.emplace_back("");
    InsertingStringAndItPos.emplace_back("");
    current_cursor_pos = 0;
    current_line = 0;
    max_symbols_in_line = 30;
    is_insert = false;
}

void InsertLineMenuModel::insertSymbol(char symbol) {
    if (InsertingStringAndItPos[current_line].length() < max_symbols_in_line) {
        InsertingStringAndItPos[current_line].insert(InsertingStringAndItPos[current_line].begin() + current_cursor_pos, symbol);
        setCurrentCursorPosition(getCurrentCursorPosition() + 1);
    }
}

void InsertLineMenuModel::eraseSymbol() {
    if (!InsertingStringAndItPos[current_line].empty()) {
        InsertingStringAndItPos[current_line].erase(InsertingStringAndItPos[current_line].begin() + current_cursor_pos - 1);
        setCurrentCursorPosition(getCurrentCursorPosition() - 1);
    }
}

void InsertLineMenuModel::setCurrentCursorPosition(int pos) {
    if (pos >= 0 && pos <= InsertingStringAndItPos[current_line].length()){
        current_cursor_pos = pos;
    } else if (pos >= 0 && pos > InsertingStringAndItPos[current_line].length()){
        current_cursor_pos = InsertingStringAndItPos[current_line].length();
    }
}

void InsertLineMenuModel::setCurrentLine(int pos) {
    if (pos >= 0 && pos <= 1){
        current_line = pos;
        setCurrentCursorPosition(current_cursor_pos);
    }
}

int InsertLineMenuModel::getCurrentCursorPosition() {
    return current_cursor_pos;
}

int InsertLineMenuModel::getCurrentLine() {
    return current_line;
}

std::string InsertLineMenuModel::getStringToInsert() {
    return InsertingStringAndItPos[0];
}

int InsertLineMenuModel::getPosToInsert() {
    if (!InsertingStringAndItPos[1].empty()) {
        return std::stoi(InsertingStringAndItPos[1]);
    }
    return 1;
}

std::string InsertLineMenuModel::getPosToInsertString() {
    return InsertingStringAndItPos[1];
}

void InsertLineMenuModel::setIsInsert(bool isInsert) {
    is_insert = isInsert;
}

bool InsertLineMenuModel::getIsInsert() {
    return is_insert;
}
