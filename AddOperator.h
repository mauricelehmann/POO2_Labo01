//
// Created by Claire on 27/02/2020.
//

#ifndef POO2_LABO01_ADDOPERATOR_H
#define POO2_LABO01_ADDOPERATOR_H


#include "MatrixOperator.h"

class AddOperator : MatrixOperator{
    int operate(int elem1, int elem2) {
        return elem1 + elem2;
    }
};

#endif //POO2_LABO01_ADDOPERATOR_H
