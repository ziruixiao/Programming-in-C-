//
//  complex.h
//  ECE2036
//
//  Created by Felix Xiao on 9/23/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#ifndef __ECE2036__complex__
#define __ECE2036__complex__

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Complex {
private:
    //define instance variables
    double real;
    double imaginary;
    double magnitude;
    double angle;
    bool NaN;
    
public:
    //define constructors
    Complex();
    Complex(double, double);
    Complex(double);
    
    //define getters
    double getReal();
    double getImaginary();
    double getMagnitude();
    double getAngle();
    bool getNaN();
    
    //define and implement setters
    void setReal(double);
    void setImaginary(double);
    void setMagnitude(double);
    void setAngle(double);
    void setNaN(bool);
    
    //define other methods
    void setComplex(double, double);  //this is like we discussed in class
    void displayRect(); //prints number in rectangular format– see output sample for format
    void displayPolar(); //prints number in polar format– see output sample for format
    void polar(); //this fills in the mag and angle data members based on rectangular values
    void rect(); //this fills in the real and imag data members based on polar values
    void conj(); //takes the conjugate of the number
    
    //specify overriding functions
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);
    
};
#endif /* defined(__ECE2036__complex__) */
