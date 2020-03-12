/*
 * File:   Operator.h
 * POO2 - Labo 1
 * Author: Maurice Lehmann, Claire Delhomme
 *
 */

#ifndef SRC_OPERATOR_H
#define SRC_OPERATOR_H


class Operator  {
public:
    /**
     *  Méthode virtuelle
     * @param a
     * @param b
     * @return
     */
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
