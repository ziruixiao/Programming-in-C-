//
//  lab5_main.cpp
//  ECE2036
//
//  Created by Felix Xiao on 12/2/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "complex.h"
/*
int main()
{

    Matrix A(3,3);
    Matrix C(4,4);
    Complex num(1,1);
    int counter = 0;
    
    for (int i = 1; i<=3; i++) {
        for (int j = 1; j<=3; j++)
        {
            A[i][j] = counter++;
        }
    }
    
    Matrix B(A);
    
    cout << "A Matrix" << endl;
    A.printMatrix();
    cout << endl;
    
    cout << "B transpose" << endl;
    B.transpose();
    cout << B << endl;
    cout << endl;
    
    cout << "The C matrix " << endl;
    
    C[1][1] = num;
    C[2][2] = Complex(4,2);
    C[3][3] = Complex(1,1);
    C[4][4] = Complex(0,1);
    
    cout << C << endl;
    
    A = B * B;
    cout << "The A = B * B matrix is " << endl;
    cout << A << endl;
    cout << endl;
    
    
    
    cout << "The transpose of A is then " << endl;
    (~A).printMatrix();
    cout << endl;
    
    cout << "The matix A is still the following " << endl;
    cout << A << endl;
    
    B = B + B; //THIS PART DOESN'T WORK
    cout << "The B = B + B matrix is " << endl;
    cout << B << endl;
    
    
    B = Complex(6,7) * B;
    cout << "The B = (6+7j) * B gives B as " << endl;
    cout << B << endl;
    
    
    A = C;
    
    cout << "The A = A-A matrix is " << endl;
    A = A - A;
    cout << A << endl;
    
    cout << "Try multipling mismatched matrices" << endl;
    C = A * B;
    cout << C << endl;
    
    cout << "Try adding mismatched matrices" << endl;
    A = A + B;
    cout << A << endl;
    
    cout << "Try subtracting mismatched matrices" << endl;
    A = A - B;
    cout << A << endl;
    
    return 0;

}*/