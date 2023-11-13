#include <iostream>

class Complexd {
public:

    double getReal() const { return real; }
    double getImag() const { return imag; }
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    // 构造函数
    Complexd(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 拷贝构造函数
    Complexd(const Complexd &c) : real(c.real), imag(c.imag) {}

    // 赋值运算符
    Complexd &operator=(const Complexd &c) {
        if (this != &c) {
            real = c.real;
            imag = c.imag;
        }
        return *this;
    }

    // 加法运算符
    Complexd operator+(const Complexd &c) const {
        return Complexd(real + c.real, imag + c.imag);
    }

    // 减法运算符
    Complexd operator-(const Complexd &c) const {
        return Complexd(real - c.real, imag - c.imag);
    }

    // 乘法运算符
    Complexd operator*(const Complexd &c) const {
        return Complexd(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // 除法运算符
    Complexd operator/(const Complexd &c) const {
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complexd((real * c.real + imag * c.imag) / denominator, 
                        (imag * c.real - real * c.imag) / denominator);
    }

    // 友元函数，重载 << 运算符
    friend std::ostream &operator<<(std::ostream &os, const Complexd &c) {
        os << "(" << c.real << ", " << c.imag << ")";
        return os;
    }

    // 友元函数，重载 >> 运算符
    friend std::istream &operator>>(std::istream &is, Complexd &c) {
        is >> c.real >> c.imag;
        return is;
    }

private:
    double real; // 实部
    double imag; // 虚部
};

// double + Complexd 运算符
Complexd operator+(double d, const Complexd &c) {
    return Complexd(d + c.getReal(), c.getImag());
}


int main() {
    Complexd c1(2.0, 3.0);
    Complexd c2(4.0, 5.0);

    Complexd c3 = c1 + c2;
    Complexd c4 = c1 - c2;
    Complexd c5 = c1 * c2;
    Complexd c6 = c1 / c2;
    double d = 5.0;
    Complexd c7 = d + c1;

    std::cout << "c1 + c2 = " << c3 << std::endl;
    std::cout << "c1 - c2 = " << c4 << std::endl;
    std::cout << "c1 * c2 = " << c5 << std::endl;
    std::cout << "c1 / c2 = " << c6 << std::endl;
    std::cout << "5.0 + c1 = " << c7 << std::endl;

    return 0;
}
