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

Matrix::~Matrix() {

    desallocateValues(this->values, ROW);
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

unsigned Matrix::applyModulo(int value, unsigned m) const{
    int mod = value %(int)m;
    if (mod < 0) {
        mod += m;
    }
    return mod;
}


void Matrix::resize(const unsigned newRow, const unsigned newCol){


    //Init. new int**
    int** newValues = new int*[newRow];

    //Copy old values into new one
    for(int i = 0; i < newRow; ++i) {
        newValues[i] = new int[newCol];
        for (int j = 0; j < newCol; ++j) {
            if(j < COL && i < ROW) {
                newValues[i][j] = values[i][j];
            }else{
                newValues[i][j] = 0;
            }
        }
    }

    //Desallocate old values
    desallocateValues(this->values, ROW);

    //Change the ptr of values
    this->values = newValues;

    //Range range
    this->COL = newCol;
    this->ROW = newRow;
}

void Matrix::desallocateValues(int** values, unsigned row){
    for(int i = 0; i < row; ++i){
        delete[] values[i];
    }
    delete[] values;
}

void Matrix::operationSelf(const Matrix& matrix, const Operator& op){
    checkModulo(matrix);
    unsigned row = max(this->ROW, matrix.ROW);
    unsigned col = max(this->COL, matrix.COL);


    //Resize the matrix
    this->resize(row, col);

    for(int i = 0; i < matrix.ROW; ++i) {
        for(int j = 0; j < matrix.COL; ++j){
            values[i][j] = applyModulo(op.calculate(matrix.values[i][j], values[i][j]), modulo) ;
        }
    }

}


Matrix Matrix::operationStatic(const Matrix& matrix, const Operator& op) const {
    checkModulo(matrix);
    unsigned row = max(this->ROW, matrix.ROW);
    unsigned col = max(this->COL, matrix.COL);

    Matrix returnMatrix(matrix);

    returnMatrix.resize(row, col);

    for(int i = 0; i < ROW; ++i) {
        for(int j = 0; j < COL; ++j){
            returnMatrix.values[i][j] = applyModulo(op.calculate(returnMatrix.values[i][j], values[i][j]), modulo) ;
        }
    }

    return returnMatrix;
}


Matrix* Matrix::operationDynamic(const Matrix& matrix, const Operator& op) const {

    checkModulo(matrix);
    unsigned row = max(this->ROW, matrix.ROW);
    unsigned col = max(this->COL, matrix.COL);

    Matrix* returnMatrix = new Matrix(matrix);

    returnMatrix->resize(row, col);

    for(int i = 0; i < ROW; ++i) {
        for(int j = 0; j < COL; ++j){
            returnMatrix->values[i][j] = applyModulo(op.calculate(returnMatrix->values[i][j], values[i][j]), modulo) ;
        }
    }

    return returnMatrix;
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
