#include "../include/calculator.h"
#include <iostream>
using namespace std;

// ----- AddOperation -----
double AddOperation::calculate(double a, double b) const {
    return a + b;
}

// ----- SubOperation -----
double SubOperation::calculate(double a, double b) const {
    return a - b;
}

// ----- Calculator -----
double Calculator::performOperation(char op, double a, double b) {
    std::unique_ptr<Operation> operation;

    switch (op) {
        case '+':
            operation = std::make_unique<AddOperation>();
            break;
        case '-':
            operation = std::make_unique<SubOperation>();
            break;
        default:
            std::cout << "Error: Unsupported operation\n";
            return 0;
    }

    return operation->calculate(a, b);
}
