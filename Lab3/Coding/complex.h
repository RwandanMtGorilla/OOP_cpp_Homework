// complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
    Complex(double real = 0.0, double imaginary = 0.0);  // 构造函数
    void addition(const Complex &a);
    void subtraction(const Complex &s);
    void multiplication(const Complex &m);  // 乘法运算
    void division(const Complex &d);  // 除法运算
    void printComplex();
    void setComplexNumber(double real, double imaginary);

private:
    double realPart;
    double imaginaryPart;
};

#endif // COMPLEX_H
