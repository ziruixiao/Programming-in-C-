//
//  complex.cpp
//  ECE2036
//
//  Created by Felix Xiao on 9/23/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#include "complex.h"

//implement constructors
Complex::Complex() { //this constructor sets all data members to zero or false
    real = 0;
    imaginary = 0;
    magnitude = 0;
    angle = 0;
    NaN = 0;
}

Complex::Complex(double r, double i) { //this constructor takes in a real and imaginary component
    real = r;
    imaginary = i;
    polar(); //generates corresponding polar representation
    NaN = 0;
}

Complex::Complex(double r) { //this constructor takes in a real component
    real = r;
    imaginary = 0; //assumed to be zero
    polar(); //generates corresponding polar representation
    NaN = 0;
}

//implement getters
double Complex::getReal() {
    return real;
}
double Complex::getImaginary() {
    return imaginary;
}
double Complex::getMagnitude() {
    return magnitude;
}
double Complex::getAngle() {
    return angle;
}
bool Complex::getNaN() {
    return NaN;
}

//implement setters
void Complex::setReal(double r) {
    real = r;
}

void Complex::setImaginary(double i) {
    imaginary = i;
}
void Complex::setMagnitude(double m) {
    magnitude = m;
}
void Complex::setAngle(double a) {
    angle = a;
}
void Complex::setNaN(bool n) {
    NaN = n;
}

//implement other methods
void Complex::setComplex(double a, double b) {  //this is like we discussed in class
    setReal(a);
    setImaginary(b);
    polar();
}

void Complex::displayRect() { //prints number in rectangular format– see output sample for format
    std::cout << std::setprecision(2) << std::fixed;
    
    std::cout.width(15);
    if (getNaN()) {
        std::cout << "NaN\n";
    } else if(getImaginary()==0) {
        std::cout << getReal() << endl;
    } else {
        std::cout << getReal() << " + " << getImaginary() << "j" << endl;
    }
}

void Complex::displayPolar() { //prints number in polar format– see output sample for format
    std::cout << std::setprecision(2) << std::fixed;
    
    std::cout.width(15);
    if (getNaN()) {
        std::cout << "NaN\n";
    } else {
        std::cout << getMagnitude() << " < " << getAngle() << endl;
    }
}

void Complex::polar() { //this fills in the mag and angle data members based on rectangular values
    //Set magnitude as following: mag = sqrt(real^2 + imag^2)
    double realTemp = getReal();
    double imagTemp = getImaginary();
    double temp = pow(realTemp, 2) + pow(imagTemp, 2);
    setMagnitude(sqrt(temp));
    
    //Set angle as following:
    //atan will only find angle between 0 and pi/2, so check
    //http://www3.ncc.edu/faculty/ens/schoenf/ELT115/complex.html
    if (realTemp > 0 && imagTemp > 0) { //normal calculation here
        setAngle(atan(imagTemp/realTemp));
    } else if (realTemp < 0 && imagTemp > 0) { //need to add pi to answer
        setAngle(atan(imagTemp/realTemp)+M_PI);
    } else if (realTemp < 0 && imagTemp < 0) { //need to subtract pi from answer
        setAngle(atan(imagTemp/realTemp)-M_PI);
    } else if (realTemp > 0 && imagTemp < 0) { //normal calculation here
        setAngle(atan(imagTemp/realTemp));
    } else { //realTemp == 0, cannot divide by 0
        setNaN(1);
    }
}

void Complex::rect() { //this fills in the real and imag data members based on polar values
    setReal(getMagnitude() * cos(getAngle())); //real = mag * cos(ang)
    setImaginary(getMagnitude() * sin(getAngle())); //imag = mag * sin(ang)
}

void Complex::conj(){ //takes the conjugate of the number
    double temp = getImaginary();
    setImaginary(-1*temp);
    polar();
}

//specify overriding functions
Complex Complex::operator+(Complex RHS) {
    Complex sum;
    sum.setReal(getReal() + RHS.getReal()); //add
    sum.setImaginary(getImaginary() + RHS.getImaginary()); //add
    
    sum.polar(); //make sure the result is in polar format too
    
    return(sum);
}

Complex Complex::operator-(Complex RHS) {
    Complex subtract;
    subtract.setReal(getReal() - RHS.getReal()); //subtract
    subtract.setImaginary(getImaginary() - RHS.getImaginary()); //subtract
    
    subtract.polar(); //make sure the result is in polar format too
    
    return(subtract);
}

Complex Complex::operator*(Complex RHS) {
    Complex multiply;
    double r1 = getReal();
    double r2 = RHS.getReal();
    double i1 = getImaginary();
    double i2 = RHS.getImaginary();
    
    //(r1 + i1) * (r2 + i2) = (r1*r2 - i1*i2) + i(r1*i2 + r2*i1)
    //http://www.physics.orst.edu/~wwarren/COURSES/ph461/H1.pdf
    
    multiply.setReal(r1*r2 - i1*i2);
    multiply.setImaginary(r1*i2 + r2*i1);
    
    multiply.polar(); //make sure the result is in polar format too
    
    return(multiply);
}

Complex Complex::operator/(Complex RHS) {
    Complex divide;
    double r1 = getReal();
    double r2 = RHS.getReal();
    double i1 = getImaginary();
    double i2 = RHS.getImaginary();
    double tempNum;
    double tempDenom;
    //(r1*r2 + i1*i2) / (r2*r2 + i2*i2) for real component
    //(r2*i1 - r1*i2) / (r2*r2 + i2*i2) for imag component
    //http://www.physics.orst.edu/~wwarren/COURSES/ph461/H1.pdf
    
    
    if (RHS.getReal() > 0 || RHS.getImaginary() > 0) { //check for division by 0, if any is above 0, fine
        tempNum = (r1*r2 + i1*i2); //numerator used for real
        tempDenom = (r2*r2 + i2*i2); //denominator used for both real and imag
        
        divide.setReal(tempNum / tempDenom); //divide
        
        tempNum = (r2*i1 - r1*i2); //recalculate numerator used for imag
        divide.setImaginary(tempNum / tempDenom); //divide
    
        divide.polar(); //make sure the result is in polar format too
    } else {
        divide.setNaN(1); //set NaN to true if division by 0
    }
    
    return(divide);
}