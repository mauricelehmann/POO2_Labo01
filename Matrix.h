//
// Created by mle on 20.02.2020.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <time.h> /* time (for random seed) */
#include "Operator.h"

class Matrix {
public:
    //Constr. par default
    Matrix(const unsigned row, const unsigned col, const unsigned modulo) noexcept(false);
    //Constr. par copie
    Matrix(const Matrix& m);
    //Destructeur
    ~Matrix();

    /**
     *
     * @param matrix
     */
    void addSelf(const Matrix& matrix) noexcept(false);
    /**
     *
     * @param m
     * @return
     */
    Matrix addStatic(const Matrix& matrix) const noexcept(false);


    /**
     *
     * @param matrix
     * @return
     */
    Matrix* addDynamic(const Matrix& matrix) const noexcept(false);

    /**
 *
 * @param matrix
 */
    void subSelf(const Matrix& matrix) noexcept(false);
    /**
     *
     * @param matrix
     * @return
     */
    Matrix subStatic(const Matrix& matrix) const noexcept(false);
    /**
     *
     * @param matrix
     * @return
     */
    Matrix* subDynamic(const Matrix& matrix) const noexcept(false);


    /**
 *
 * @param matrix
 */
    void multiplySelf(const Matrix& matrix) noexcept(false);
    /**
     *
     * @param matrix
     * @return
     */
    Matrix multiplyStatic(const Matrix& matrix) const noexcept(false);
    /**
     *
     * @param matrix
     * @return
     */
    Matrix* multiplyDynamic(const Matrix& matrix) const noexcept(false);

    /**
     *
     * @param x
     * @param y
     * @return
     */
    int getValue(unsigned x, unsigned y) const noexcept(false);

    /**
     * @param os
     * @param m
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    Matrix& operator=(const Matrix& m);



private:

    int** values;
    unsigned modulo;
    unsigned ROW, COL;
    static bool isSeedInit;


    /**
     *
     * @param matrix
     * @param op
     */
    void operationSelf(const Matrix& matrix, const Operator& op);
    /**
     *
     * @param matrix
     * @param op
     * @return
     */
    Matrix operationStatic(const Matrix& matrix, const Operator& op) const;
    /**
     *
     * @param matrix
     * @param op
     * @return
     */
    Matrix* operationDynamic(const Matrix& matrix, const Operator& op) const ;

    /**
     *
     * @param matrix
     */
    void checkModulo(const Matrix& matrix) const noexcept(false);
    /**
     *
     * @param value
     * @param m
     * @return
     */
    unsigned applyModulo(int value, unsigned m) const;
    /**
     *
     * @param newRow
     * @param newCol
     */
    void resize(const unsigned newRow, const unsigned newCol);
    /**
     *
     * @param values
     * @param col
     */
    void desallocateValues(int** values, unsigned col);

};


#endif //SRC_MATRIX_H
