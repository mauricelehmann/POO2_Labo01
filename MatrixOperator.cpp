//
// Created by Claire on 27/02/2020.
//

#include "MatrixOperator.h"

Matrix MatrixOperator::compute(const Matrix &m1, const Matrix &m2) {
    Matrix::checkModulo(m1,m2);

    int mod = m1.n();

    int maxM = Math.max(m1.M(), m2.M());
    int maxN = Math.max(m1.N(), m2.N());

    int[][] resultValues = new int[maxN][maxM];

    int elem1, elem2;
    for(int i = 0; i < maxN; ++i) {
        for (int j = 0; j < maxM; ++j) {
            // La valeur de l'élément est 0 si on dépasse les dimensions de la matrice
            elem1 = (i < m1.N() && j < m1.M()) ? m1.getElem(i,j) : 0;
            elem2 = (i < m2.N() && j < m2.M()) ? m2.getElem(i,j) : 0;
            resultValues[i][j] = Math.floorMod(this.operate(elem1, elem2), mod);
        }
    }

    return new Matrix(m1.n(), resultValues);
}
