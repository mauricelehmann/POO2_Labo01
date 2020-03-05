//
// Created by mle on 04.03.2020.
//

#ifndef SRC_OPERATOR_H
#define SRC_OPERATOR_H


class Operator  {
public:
    virtual int calculate(int a, int b) const = 0;
};

class Addition : public Operator {
public:
    int calculate(int a, int b) const override {
        return a + b;
    }
};

class Subtraction : public Operator {
public:
    int calculate(int a, int b) const override {
        return a - b;
    }
};

class Multiplication : public Operator {
public:
    int calculate(int a, int b) const override {
        return a * b;
    }
};

#endif //SRC_OPERATOR_H
