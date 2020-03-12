/*
 * File:   Matrix.cpp
 * POO2 - Labo 1
 * Author: Maurice Lehmann, Claire Delhomme
 *
 */

#include "Matrix.h"
using namespace std;




bool Matrix::isSeedInit = false;

Matrix::Matrix(const unsigned row, const unsigned col, const unsigned modulo) noexcept(false)
:ROW(row),COL(col),modulo(modulo)
{
    if(row < 1 || col < 1)
        throw out_of_range("Number of rows or column cannot be smaller than 1!");

    //Init seed for the random
    if(!isSeedInit){
        srand((time(NULL)));
        isSeedInit = true;
    }

    this->values = new int*[row];

    for(int i = 0; i < row; ++i){

        this->values[i] = new int[col];
        //Fill value
        for(int j = 0; j < col; ++j)
            this->values[i][j] = (int) (rand() / (RAND_MAX + 1.0) * modulo);
    }
}


Matrix::Matrix(const Matrix& matrix):ROW(matrix.ROW),COL(matrix.COL),modulo(matrix.modulo){

	this->values = new int*[ROW];
    for(int i = 0; i < ROW; ++i){

        this->values[i] = new int[COL];
        //Fill value
        for(int j = 0; j < COL; ++j){
            this->values[i][j] = matrix.values[i][j];
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Matrix &m){
    for(int i = 0 ; i < m.ROW ; ++i){
        for(int j = 0 ; j < m.COL ; ++j)
            os << m.values[i][j] << " ";
        os << endl;
    }
    return os;
}
/**
 *
 */
Matrix::~Matrix() {

    for(int i = 0; i < COL; ++i){
        delete[] this->values[i];
    }
    delete[] this->values;
}


void Matrix::addSelf(const Matrix& matrix) noexcept(false){
    Addition add;
    this->operationSelf(matrix, add);
}

Matrix Matrix::addStatic(const Matrix& matrix) const noexcept(false){
    Addition add;
    return this->operationStatic(matrix, add);

}

Matrix* Matrix::addDynamic(const Matrix& matrix) const noexcept(false){
    Addition add;
    return operationDynamic(matrix, add);
}

void Matrix::subSelf(const Matrix& matrix) noexcept(false){
    Subtraction sub;
    this->operationSelf(matrix, sub);

}

Matrix Matrix::subStatic(const Matrix& matrix) const noexcept(false){
    Subtraction sub;
    return this->operationStatic(matrix, sub);

}

Matrix* Matrix::subDynamic(const Matrix& matrix) const noexcept(false){
    Subtraction sub;
    return operationDynamic(matrix, sub);
}

void Matrix::multiplySelf(const Matrix& matrix) noexcept(false){
    Multiplication mult;
    this->operationSelf(matrix, mult);

}

Matrix Matrix::multiplyStatic(const Matrix& matrix) const noexcept(false){
    Multiplication mul;
    return this->operationStatic(matrix, mul);
}

Matrix* Matrix::multiplyDynamic(const Matrix& matrix) const noexcept(false){
    Multiplication mul;
    return operationDynamic(matrix, mul);
}


int Matrix::getValue(unsigned numRow, unsigned numCol) const noexcept(false){
    if(numRow > ROW || numCol > COL){
        throw invalid_argument("Coordinates invalids!");
    }

    return this->values[numRow][numCol];
}

void Matrix::computeMatrix(const Matrix& matrix, const Operator& op){
    this->resize(matrix);
    for(int i = 0; i < ROW; ++i) {
        for(int j = 0; j < COL; ++j){
            this->values[i][j] = applyModulo(op.calculate(this->values[i][j], matrix.values[i][j]), modulo) ;
        }
    }
}

unsigned Matrix::applyModulo(int value, unsigned m) const{
    int mod = value %(int)m;
    if (mod < 0) {
        mod += m;
    }
    return mod;
}

void Matrix::resize(const Matrix& matrix){
    unsigned row = max(this->ROW, matrix.ROW);
    unsigned col = max(this->COL, matrix.COL);

    Matrix tmp(row, col, 0);

    //Copy "this" Matrix into tmp
    for(int i = 0; i < this->ROW; ++i) {
        for(int j = 0; j < this->COL; ++j){
            tmp.values[i][j] = this->values[i][j];
        }
    }
    tmp.modulo = modulo;
    *this = tmp;
}


void Matrix::operationSelf(const Matrix& matrix, const Operator& op){
    checkModulo(matrix);
    Matrix output = *this;
    output.computeMatrix(matrix, op);
    *this = output;
}


Matrix Matrix::operationStatic(const Matrix& matrix, const Operator& op) const {
    checkModulo(matrix);
    Matrix output = *this;
    output.computeMatrix(matrix, op);
    return output;

}


Matrix* Matrix::operationDynamic(const Matrix& matrix, const Operator& op) const {
    checkModulo(matrix);
    Matrix* output = new Matrix(ROW, COL, 0);
    output->modulo = modulo;
    //Copy "this" Matrix into output
    for(int i = 0; i < this->ROW; ++i) {
        for(int j = 0; j < this->COL; ++j){
            output->values[i][j] = this->values[i][j];
        }
    }
    output->computeMatrix(matrix, op);
    return output;
}

void Matrix::checkModulo(const Matrix& matrix) const noexcept(false){
    if(matrix.modulo != this->modulo)
        throw invalid_argument("The modulos should be the same");
}

Matrix& Matrix::operator=(const Matrix& m){
    Matrix tmp(m);
    std::swap(tmp.values, values);
    this->modulo = tmp.modulo;
    this->COL = tmp.COL;
    this->ROW = tmp.ROW;
    return *this;
}
