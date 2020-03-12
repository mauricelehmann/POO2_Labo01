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
     *  OperationSelf addition
     *
     * @param matrix    l'autre matrice de l'opération
     */
    void addSelf(const Matrix& matrix) noexcept(false);
    /**
     *  OperationStatic addition
     *
     * @param matrix    l'autre matrice de l'opération
     * @return  la matrice résultat allouée statiquement
     */
    Matrix addStatic(const Matrix& matrix) const noexcept(false);
    /**
     *  OperationDynamic addition
     *
     * @param matrix    l'autre matrice de l'opération
     * @return  la matrice résultat allouée dynamiquement
     */
    Matrix* addDynamic(const Matrix& matrix) const noexcept(false);
    /**
     *  OperationSelf soustraction
     *
     * @param matrix    l'autre matrice de l'opération
     */
    void subSelf(const Matrix& matrix) noexcept(false);
    /**
     *  OperationStatic soustraction
     *
     * @param matrix    l'autre matrice de l'opération
     * @return  la matrice résultat allouée statiquement
     */
    Matrix subStatic(const Matrix& matrix) const noexcept(false);
    /**
     *  OperationDynamic soustraction
     *
     * @param matrix    l'autre matrice de l'opération
     * @return  la matrice résultat allouée dynamiquement
     */
    Matrix* subDynamic(const Matrix& matrix) const noexcept(false);

    /**
     *  OperationSelf multiplication
     *
     * @param matrix    l'autre matrice de l'opération
     */
    void multiplySelf(const Matrix& matrix) noexcept(false);
    /**
      *  OperationStatic multiplication
      *
      * @param matrix    l'autre matrice de l'opération
      * @return  la matrice résultat allouée dynamiquement
      */
    Matrix multiplyStatic(const Matrix& matrix) const noexcept(false);
    /**
     *  OperationDynamic multiplication
     *
     * @param matrix    l'autre matrice de l'opération
     * @return  la matrice résultat allouée dynamiquement
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
     * Surcharge de l'opérateur d'affichage
     *
     * @param os    flux de sortie
     * @param m     matrice à afficher
     * @return      une référence au flux de sortie
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);


    /**
     * Surcharge de l'opérateur d'affectaion
     * Appelle le constructeur par copie
     *
     * @param m matrice à copier
     * @return  une référence à la matrice affectée
     */
    Matrix& operator=(const Matrix& m);


private:
    int** values;
    unsigned modulo;
    unsigned ROW, COL;  //pas const pour operationSelf
    static bool isSeedInit;


    /**
     *  Opération effectuée en modifiant la matrice sur laquelle est invoquée la méthode
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
     *  Redimensionne la matrice appelante si besoin et calcule l'opération entre deux matrices
     *
     * @param matrix    l'autre matrice dans l'opération
     * @param op        l'opérateur à appliquer
     */
    void computeMatrix(const Matrix& matrix, const Operator& op);

    /**
     *  Désalloue les valeurs d'une matrice
     *
     * @param values    le tableau de valeurs à désallouer
     * @param row       le nombre de rangées à désallouer
     */
    void desallocateValues(int** values, unsigned row);
    /**
     *  Redimensionne la matrice appelante
     *
     * @param newRow nombre de lignes
     * @param newCol nombre de colonnes
     */
    void resize(const unsigned newRow, const unsigned newCol);

};


#endif //SRC_MATRIX_H
