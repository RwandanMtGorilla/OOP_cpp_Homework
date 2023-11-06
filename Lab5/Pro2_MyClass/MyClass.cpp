#include <iostream>
#include <string>
using namespace std;

class MyClass {
    const double pi = 3.141592653589793;
    static int number;
    string name;

public:
    MyClass() {
        number++;
    }

    MyClass(string name) : name(name) {
        number++;
    }

    ~MyClass() {
        number--;
    }

    MyClass(const MyClass& s) : pi(s.pi), name(s.name) {
        number++;
    }

    MyClass& operator=(const MyClass& s) {
        if (this != &s) {
            // pi is a const member, so it cannot be assigned
            // and will always be initialized to the same value.
            name = s.name;
        }
        return *this;
    }

    void print() const {
        cout << "Name: " << name << ", Pi: " << pi << endl;
    }

    static int getNumber() {
        return number;
    }
};

int MyClass::number = 0;

int main() {
    MyClass mc1;
    MyClass mc2("zhang");

    mc1 = mc2;   // 表示将s2赋值给s1
    cout << MyClass::getNumber() << endl;
    MyClass mc3(mc2);  
    // mc3.print();

    const MyClass mc4("li");
    mc4.print();
    cout << MyClass::getNumber() << endl;

    MyClass *pm = new MyClass[6];
    cout << MyClass::getNumber() << endl;

    if (nullptr != pm) {
        delete[] pm;
        pm = nullptr;
    }

    return 0;
}
