//
//  matrix.cpp
//  ECE2036
//
//  Created by Felix Xiao on 12/2/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#include "matrix.h"

//2-argument constructor
Matrix::Matrix(int r, int c) : rows(r), columns(c), size(r*c) {
    myArray = new Complex*[size]; //allocate with new
    for (int i = 0; i < rows; ++i) {
        myArray[i] = new Complex[columns]; //allocate with new
        for (int j = 0; j < columns; ++j)
            myArray[i][j] = 0; //set to default value of 0
    }

}

//copy constructor
Matrix::Matrix(const Matrix & rhs) :rows(rhs.rows), columns(rhs.columns), size(rhs.size) {
    myArray = new Complex*[size]; //allocate with new
    for (int i = 0; i < rows; ++i) {
        myArray[i] = new Complex[columns]; //allocate with new
        for (int j = 0; j < columns; ++j) {
            myArray[i][j] = rhs.myArray[i][j]; //set to value of copied
        }
    }
}

//destructor
Matrix::~Matrix() {
    for (int i=0;i<rows;i++){
        delete [] myArray[i]; //delete each individual one
        myArray[i] = NULL; //set to null
    }
    delete myArray; //delete the entire array
    myArray = NULL; //set to null
}

//equal operator
Matrix & Matrix::operator=(const Matrix & rhs) {
    //check for self-assignment
    if (&rhs != this) {
        if (rows != rhs.rows || columns != rhs.columns) {
            for (int i=0;i<rows;i++){
                delete [] myArray[i]; //delete each individual one
                myArray[i] = NULL; //set to null
            }
            delete myArray; //delete the entire array
            myArray = NULL; //set to null
            size = rhs.size;
            myArray = new Complex*[size]; //allocate new array
        }
        
        for (int i = 0; i < rhs.rows; ++i) {
            myArray[i] = new Complex[rhs.columns];
            for (int j = 0; j < rhs.columns; ++j) {
                myArray[i][j] = rhs.myArray[i][j];
            }
        }
        rows = rhs.rows;
        columns = rhs.columns;
    }
    
    return (*this);
    
}

//addition operator
Matrix Matrix::operator+(const Matrix& rhs) {
    if (rows == rhs.rows && columns == rhs.columns) { //both rows and columns need to match
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                myArray[i][j] = myArray[i][j] + rhs.myArray[i][j];
            }
        }
    } else { //set rows and columns to zero
        rows = 0;
        columns = 0;
    }
    return (*this);
}

//subtraction operator
Matrix Matrix::operator-(const Matrix& rhs) {
    if (rows == rhs.rows && columns == rhs.columns) { //both rows and columns need to match
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                myArray[i][j] = myArray[i][j] - rhs.myArray[i][j];
            }
        }
    } else { //set everything to zero
        rows = 0;
        columns = 0;
    }
    return (*this);
}

//multiplication operator
Matrix Matrix::operator*(const Matrix& rhs) {
    Matrix tempMatrix = Matrix(rows,rhs.columns); //a new Matrix is used so that what is being multiplied isn't set. For example, A = B * B needs to keep B the same value.
    if (rows == rhs.columns && columns == rhs.rows) { //rows of A must equal cols of B, vice versa
        Complex **newArray = new Complex*[rows*rhs.columns];
        Complex temp;
        /*
         A B C      G H
         D E F  *   I J     will use rows of first matrix and columns of second matrix for a 2 x 2 matrix
                    K L
         */
        for (int i = 0; i < rows; i++) {
            newArray[i] = new Complex[rhs.columns];
            for (int j = 0; j < rhs.columns; j++) {
                temp = 0;
                for (int k = 0; k < rhs.rows; k++) {
                    temp = temp + myArray[i][k] * rhs.myArray[k][j];
                }
                newArray[i][j] = temp;
            }
        }
        tempMatrix.rows = rows;
        tempMatrix.columns = rhs.columns;
        tempMatrix.size = rows * rhs.columns;
        tempMatrix.myArray = newArray;
    } else { //set everything to zero
        tempMatrix.rows = 0;
        tempMatrix.columns = 0;
    }
    
    return (tempMatrix);
}

//tilde operator for transpose
Matrix Matrix::operator~() {
    Matrix tempMatrix = Matrix(columns,rows); //use columns, rows instead of rows, columns to transpose
    Complex **newArray = new Complex*[size];
    for (int i = 0; i < columns; ++i) {
        newArray[i] = new Complex[columns];
        for (int j = 0; j < rows; ++j) {
            newArray[i][j] = myArray[j][i]; //create transpose
        }
    }
    tempMatrix.myArray = newArray;
    tempMatrix.rows = columns;
    tempMatrix.columns = rows;
    tempMatrix.size = rows * columns;
    return (tempMatrix);
}

//second multiplication operator
Matrix operator*(Complex c, Matrix &matrix) {
    for(int i = 0; i < matrix.rows; i++) {
        for(int j = 0; j < matrix.columns; j++) {
            matrix.myArray[i][j] = matrix.myArray[i][j] * c;
        }
    }
    return matrix;
}

//<< operator
ostream & operator<<(ostream & output, const Matrix & matrix) {
    
    if (matrix.rows == 0 && matrix.columns == 0) { //indicates an error
        output << "Matrix Mismatch Error:" << endl;
        output << "This matrix has zero elements." << endl;
    } else {
        for(int i=0; i<matrix.rows;i++) {
            for(int j=0;j<matrix.columns;j++) {
                output.width(15);
                if (matrix.myArray[i][j].getImaginary() == 0) { //only real number exists
                    output << matrix.myArray[i][j].getReal();
                } else if (matrix.myArray[i][j].getReal() == 0) { //only imaginary number exists
                    output << matrix.myArray[i][j].getImaginary() << "j";
                } else { //both exist
                    output << matrix.myArray[i][j].getReal() << " + " << matrix.myArray[i][j].getImaginary() << "j";
                }
            }
            output<<endl; //when the first loop is done, go to new line
        }
    }
    return output;
}

//getters
int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

int Matrix::getSize() const {
    return size;
}

//setters
void Matrix::setRows(int r) {
    rows = r;
}

void Matrix::setColumns(int c) {
    columns = c;
}

//get from array method to assist with [][] overloading
Complex& Matrix::getFromArray(int r,int c){
    if (r>0 && c > 0) {
        return myArray[r-1][c-1]; //do -1 to deal with zero indexing
    }
    return myArray[0][0];
}

//print matrix, similar to << overload
void Matrix::printMatrix() {
    if (rows == 0 && columns == 0) {
        std::cout << "Matrix Mismatch Error:" << endl;
        std::cout << "This matrix has zero elements." << endl;
    } else {
        for(int i=0; i<rows;i++) {
            for(int j=0;j<columns;j++) {
                std::cout.width(15);
                if (myArray[i][j].getImaginary() == 0) { //only real number exists
                    std::cout << myArray[i][j].getReal();
                } else if (myArray[i][j].getReal() == 0) { //only imaginary number exists
                    std::cout << myArray[i][j].getImaginary() << "j";
                } else { //both exist
                    std::cout << myArray[i][j].getReal() << " + " << myArray[i][j].getImaginary() << "j";
                }
            }
            cout<<endl;
        }
    }
}

//transpose method, similar to ~ operator, except myArray is modified
void Matrix::transpose() {
    Complex **newMatrix = new Complex*[size];
    for (int i = 0; i < columns; ++i) {
        newMatrix[i] = new Complex[columns];
        for (int j = 0; j < rows; ++j) {
            newMatrix[i][j] = myArray[j][i];
        }
    }
    myArray = newMatrix;
}

