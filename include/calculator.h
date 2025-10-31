#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>

// ----- Abstract Base Class -----
class Operation {
public:
    virtual double calculate(double a, double b) const = 0;
    virtual ~Operation() = default;
};

// ----- Derived Classes -----
class AddOperation : public Operation {
public:
    double calculate(double a, double b) const override;
};

class SubOperation : public Operation {
public:
    double calculate(double a, double b) const override;
};

// ----- Calculator Class -----
class Calculator {
public:
    double performOperation(char op, double a, double b);
};

#endif
