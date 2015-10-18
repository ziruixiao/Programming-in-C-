//
//  matrix.h
//  ECE2036
//
//  Created by Felix Xiao on 12/2/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#ifndef __ECE2036__matrix__
#define __ECE2036__matrix__

#include <stdio.h>
#include "complex.h"
using namespace std;

#endif /* defined(__ECE2036__matrix__) */

//This is a class prototype to let the compiler know
//that I intend to define a class Matrix. It is needed
//for the global function definition that I put before
//the class Matrix as an example in this lab.

class Matrix;
ostream& operator<<(ostream &, const Matrix &);
Matrix operator*(Complex,Matrix &);

class Matrix
{
    
private:
    friend class MatrixRow;
    Complex& getFromArray(int,int);
    int rows;
    int columns;
    int size;
    Complex **myArray;
    
public:
    //consturctors
    Matrix(int,int);
    Matrix(const Matrix &);
    ~Matrix();
    
    //operators
    Matrix & operator=(const Matrix &);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator*(const Complex&);
    Matrix operator~();
    
    friend ostream& operator<<(ostream &, const Matrix &);
    friend Matrix operator*(Complex, Matrix &);
    
    //BELOW ARE MATRIXROW METHODS
    class MatrixRow //helper class for [][] overloading
    {
    private:
        Matrix& fullMatrix;
        int row;
    public:
        MatrixRow(Matrix& f, int r) : fullMatrix(f), row(r) {}
        Complex& operator[](int c)  const {
            return fullMatrix.getFromArray(row,c);
        }
    };

    MatrixRow operator[](int x) {
        return MatrixRow(*this, x);
    }
    //ABOVE ARE MATRIXROW METHODS
    
    //getters
    int getRows() const;
    int getColumns() const;
    int getSize() const;
    
    //setters
    void setRows(int r);
    void setColumns(int c);
    
    //methods
    void printMatrix();
    void transpose();
    
};