// complex.cpp
// member function definitions for class Complex
#include <iostream>
using std::cout;

#include "complex.h"

Complex::Complex(double real, double imaginary)
    : realPart(real), imaginaryPart(imaginary) { } 

void Complex::addition(const Complex &a) {
   realPart += a.realPart;
   imaginaryPart += a.imaginaryPart;
} 

void Complex::subtraction(const Complex &s) {
   realPart -= s.realPart;
   imaginaryPart -= s.imaginaryPart;
} 

void Complex::multiplication(const Complex &m) {
   double tempReal = realPart * m.realPart - imaginaryPart * m.imaginaryPart;
   imaginaryPart = realPart * m.imaginaryPart + imaginaryPart * m.realPart;
   realPart = tempReal;
}

void Complex::division(const Complex &d) {
    double denominator = d.realPart * d.realPart + d.imaginaryPart * d.imaginaryPart;
    if(denominator != 0) {
        double tempReal = (realPart * d.realPart + imaginaryPart * d.imaginaryPart) / denominator;
        imaginaryPart = (imaginaryPart * d.realPart - realPart * d.imaginaryPart) / denominator;
        realPart = tempReal;
    } else {
        cout << "Error: Division by zero!\n";
    }
}

void Complex::printComplex() { 
   cout << '(' << realPart << ", " << imaginaryPart << ')';
}

void Complex::setComplexNumber(double real, double imaginary) {
   realPart = real;
   imaginaryPart = imaginary;
}
