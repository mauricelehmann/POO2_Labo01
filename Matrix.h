/*
 * File:   Matrix.h
 * POO2 - Labo 1
 * Author: Maurice Lehmann, Claire Delhomme
 *
 */

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
    unsigned ROW, COL;  //pas const pour operationSelf
    static bool isSeedInit;


    /**
     *  Opération effectuée en modifiant la matrice sur laquelle est invoquée la méthode,
     *
     * @param matrix    l'autre matrice dans l'opération
     * @param op        l'opérateur à appliquer
     */
    void operationSelf(const Matrix& matrix, const Operator& op);
    /**
     *  Opération effectuée en retournant par valeur une nouvelle matrice résultat allouée statiquement
     *
     * @param matrix    l'autre matrice dans l'opération
     * @param op        l'opérateur à appliquer
     * @return  par valeur une nouvelle matrice résultat allouée statiquement
     */
    Matrix operationStatic(const Matrix& matrix, const Operator& op) const;
    /**
     *  Opération effectuée en retournant un pointeur sur une nouvelle matrice résultat allouée dynamiquement
     *
     * @param matrix    l'autre matrice dans l'opération
     * @param op        l'opérateur à appliquer
     * @return  un pointeur sur une nouvelle matrice résultat allouée dynamiquement
     */
    Matrix* operationDynamic(const Matrix& matrix, const Operator& op) const ;

    /**
     *  Vérifie que deux matrices ont le même modulo
     *
     * @param matrix    l'autre matrice dans l'opération
     */
    void checkModulo(const Matrix& matrix) const noexcept(false);
    /**
     *  Redimensionne la matrice sur laquelle est appelée la méthode aux dimensions de l'autre matrice si
     *  cette dernière est plus grande
     *
     * @param matrix    l'autre matrice dans l'opération
     */
    void resize(const Matrix& matrix);
    /**
     *
     * @param value la valeur sur laquelle appliquer le modulo
     * @param m     le modulo
     * @return  le modulo positif de value
     */
    unsigned applyModulo(int value, unsigned m) const;
    /**
     *  Redimensionne la matrice appelante et applique
     *
     * @param matrix    l'autre matrice dans l'opération
     * @param op        l'opérateur à appliquer
     */
    void computeMatrix(const Matrix& matrix, const Operator& op);

};


#endif //SRC_MATRIX_H
