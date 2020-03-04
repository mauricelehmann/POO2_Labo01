//
// Created by Claire on 27/02/2020.
//

#ifndef POO2_LABO01_MATRIXOPERATOR_H
#define POO2_LABO01_MATRIXOPERATOR_H


#include "Matrix.h"

class MatrixOperator {
public :
    Matrix compute(const Matrix& m1, const Matrix& m2);

private :
    int operate(int elem1, int elem2);
};


#endif //POO2_LABO01_MATRIXOPERATOR_H
