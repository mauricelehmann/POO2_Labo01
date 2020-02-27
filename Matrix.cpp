//
// Created by mle on 20.02.2020.
//

#include "Matrix.h"
using namespace std;
/**
 *
 * @param N
 * @param M
 * @param modulo
 */
Matrix::Matrix(const unsigned N, const unsigned M, const unsigned modulo):N(N),M(M),modulo(modulo){
    //TODO : Check de la taille de N et M ?
    this->values = new int*[N];
    for(int i = 0; i < M; ++i){
        this->values[i] = new int[M];
        for(int j = 0; j < M; ++j){
            this->values[i][j] = (int) (rand() / (RAND_MAX + 1.0) * modulo);
        }
    }
}

/**
 *
 * @param m
 */
Matrix::Matrix(const Matrix& matrix):N(matrix.N),M(matrix.N),modulo(matrix.modulo){
    //TODO
}

/**
 *
 * @param os
 * @param m
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for(int i = 0 ; i < m.N ; ++i){
        for(int j = 0 ; j < m.M ; ++j)
            os << m.values[i][j] << " ";
        os << endl << endl;
    }
    return os;
}
/**
 *
 */
Matrix::~Matrix() {
    for(int i = 0; i < M; ++i){
        delete[] this->values[i];
    }
    delete[] this->values;
}

Matrix Matrix::operator+(Matrix matrix){
    checkModulo(*this, matrix);
    unsigned n = max(this->N, matrix.N);
    unsigned m = max(this->M, matrix.M);
    //TODO : depuis la copie "matrix", resize tt les lignes avec  memcpy( newArr, arr, size * sizeof(int) );
    //Matrix newMatrix = Matrix(n,m,modulo);
    return Matrix(1,1,1);

}

void add(Matrix matrix){

}

void Matrix::checkModulo(const Matrix &m1, const Matrix &m2){
    if(m1.modulo != m2.modulo)
        throw invalid_argument("The modulos should be the same");
}
