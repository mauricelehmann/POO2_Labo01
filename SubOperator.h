//
// Created by Claire on 27/02/2020.
//

#ifndef POO2_LABO01_SUBOPERATOR_H
#define POO2_LABO01_SUBOPERATOR_H


#include "MatrixOperator.h"

class SubOperator : MatrixOperator{
    int operate(int elem1, int elem2) {
        return elem1 - elem2;
    }
};


#endif //POO2_LABO01_SUBOPERATOR_H
