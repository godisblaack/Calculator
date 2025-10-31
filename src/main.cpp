#include <iostream>
#include "../include/calculator.h"
using namespace std;

int main() {
    Calculator calc;
    double num1, num2;
    char op;

    cout << "Enter expression (e.g., 5 + 3): ";
    cin >> num1 >> op >> num2;

    double result = calc.performOperation(op, num1, num2);
    cout << "Result: " << result << endl;

    return 0;
}
