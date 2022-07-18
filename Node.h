//
// Created by Семён Чубенко on 26.04.2022.
//

#ifndef FORMULA_TREE_NODE_H
#define FORMULA_TREE_NODE_H

#include <iostream>
#include "stack"
#include "queue"
#include "cmath"

class Node{
public:
    double key;
    std::string operation;

    Node* left;
    Node* right;

    Node(){
        left = nullptr;
        right = nullptr;
        key = -1;
        operation = "0";
    }

    explicit Node(double key){
        this->key = key;
        this->operation = "0";
        left = nullptr;
        right = nullptr;
    }

    explicit Node(std::string operation){
        this->key = -1;
        this->operation = operation;
        left = nullptr;
        right = nullptr;
    }

    ~Node(){
        delete left;
        delete right;
    }
};

bool isLess(std::string a, std::string b){
    if (b == "(") return false;
    if (a == "^" && (b == "sin" || b == "cos" || b == "ln" || b == "sqrt")) {
        return true;
    }
    if ((a == "+" || a == "-") && (b == "+" || b == "-")){
        return true;
    }
    if ((a == "+" || a == "-") && (b == "/" || b == "*" || b == "sqrt" || b == "cos" || b == "ln"  || b == "^" || b == "sin")){
        return true;
    }
    if ((a == "s" || a == "c" || a == "l" || a == "^") && (b == "*" || b == "/")) {
        return false;
    }
    return false;
}

bool isOperation(char a){
    return a == '+' || a == '-' || a == '*' || a == 's' || a == 'c' || a == 'l' || a == '^' || a == '/' || a == 'e';
}

void Build(Node*& root, std::string input){
    if (input.empty()){
        delete root;
        root = nullptr;
        return;
    }
    for (int i = 0; i < input.size() - 1; ++i) {
        if ((isdigit(input[i]) || input[i] == 'x') &&
            (input[i + 1] == 's' || input[i + 1] == 'c' || input[i + 1] == 'l' || input[i + 1] == 'e' || input[i + 1] == 'x') &&
            (input[i + 1] != '*' && input[i + 1] != '-' && input[i + 1] != '+' && input[i + 1] != '^')){
            input.insert(i + 1, "*");
            ++i;
        }
    }
    input.push_back(')');
    std::stack<Node*> operations;
    std::stack<Node*> operands;
    std::string num;
    operations.push(new Node("("));
    input = "(" + input;
    for (int i = 1; i < input.size(); ++i) {
        if (input[i] == '-' && input[i - 1] == '('){
            input.insert(i + 1, "(1-2)*");
            input.erase(i, 1);
        }
        if (input[i] == '('){
            operations.push(new Node("("));
        } else if (input[i] == ')'){
            if(!num.empty()) {
                if (num != "x") {
                    operands.push(new Node(std::stod(num)));
                } else {
                    operands.push(new Node("x"));
                }
            }
            num.clear();
            while (operations.top()->operation != "("){
//                Node* new_node = new Node(operations.top()->operation);
                Node* new_node = operations.top();
                operations.pop();
                if (new_node->operation == "sin" || new_node->operation == "cos" ||
                    new_node->operation == "sqrt" || new_node->operation == "ln" ||
                    new_node->operation == "exp"){
                    Node* operand = operands.top();
                    operands.pop();
                    new_node->left = operand;
                } else {
                    Node *operand1;
                    Node *operand2;
                    operand1 = operands.top();
                    operands.pop();
                    operand2 = operands.top();
                    operands.pop();
                    new_node->left = operand2;
                    new_node->right = operand1;
                }
                operands.push(new_node);
            }
            delete operations.top();
            operations.pop();
        } else if (isOperation(input[i])){
//            if (input[i] == '-' && (i == 0 || input[i - 1] == '(')){
//                num += input[i];
//                continue;
//            }
            if(!num.empty()) {
                if (num != "x") {
                    operands.push(new Node(std::stod(num)));
                } else {
                    operands.push(new Node("x"));
                }
            }
            num.clear();
            while (!operations.empty() && isLess(std::string(1, input[i]), operations.top()->operation)){
//                Node* new_node = new Node(operations.top()->operation);
                Node* new_node = operations.top();
                operations.pop();
                if (new_node->operation == "sin" || new_node->operation == "cos" ||
                    new_node->operation == "sqrt" || new_node->operation == "ln" ||
                    new_node->operation == "exp"){
                    Node* operand = operands.top();
                    operands.pop();
                    new_node->left = operand;
                } else {
                    Node *operand1;
                    Node *operand2;
                    operand1 = operands.top();
                    operands.pop();
                    operand2 = operands.top();
                    operands.pop();
                    new_node->left = operand2;
                    new_node->right = operand1;
                }
                operands.push(new_node);
            }
            if (input[i] == 's' && input[i + 1] == 'q'){
                operations.push(new Node("sqrt"));
                i += 3;
            } else if (input[i] == 's'){
                operations.push(new Node("sin"));
                i += 2;
            } else if (input[i] == 'c'){
                operations.push(new Node("cos"));
                i += 2;
            } else if (input[i] == 'l'){
                operations.push(new Node("ln"));
                i += 1;
            } else if (input[i] == 'e'){
                operations.push(new Node("exp"));
                i += 2;
            } else {
                operations.push(new Node(std::string(1, input[i])));
            }
        } else {
            num += input[i];
        }
    }
    root = operands.top();
}

double Count(Node* root, double x_value){
    if (root == nullptr) return 0;
    if (root->operation == "x") return x_value;
    if(root->operation != "0") {
        double a = Count(root->left, x_value);
        double b = Count(root->right, x_value);
        if (root->operation == "+"){
            return a + b;
        } else if (root->operation == "-"){
            return a - b;
        } else if (root->operation == "*"){
            return a * b;
        } else if (root->operation == "sqrt"){
            if (a < 0){
                throw std::invalid_argument("sqrt");
            }
            return sqrt(a);
        } else if (root->operation == "^"){
            return std::pow(a, b);
        } else if (root->operation == "sin"){
            return std::sin(a);
        } else if (root->operation == "cos"){
            return std::cos(a);
        } else if (root->operation == "ln"){
            if (a <= 0.0001){
                throw std::invalid_argument("ln");
            }
            return log(a);
        } else if (root->operation == "/"){
            if (b == 0){
                throw std::invalid_argument("/");
            }
            return a / b;
        } else if (root->operation == "exp"){
            return exp(a);
        }
    } else {
        return root->key;
    }
}

#endif //FORMULA_TREE_NODE_H
