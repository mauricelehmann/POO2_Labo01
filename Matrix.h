//
// Created by mle on 20.02.2020.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
    //Constr. par default
    Matrix(const unsigned N, const unsigned M, const unsigned modulo);
    //Constr. par copie
    Matrix(const Matrix& m);
    //Destructeur
    ~Matrix();

    //void operation(Matrix m, Operation op);
    /**
     *
     * @param m
     * @return
     */
    Matrix operator+(Matrix m);
    /**
     *
     * @param os
     * @param m
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    /**
     *
     * @param matrix
     * @throws invalid_argument
     */
    void checkModulo(const Matrix& m1, const Matrix& m2);


private:
    int** values;
    const unsigned modulo, N, M;
};


#endif //SRC_MATRIX_H
