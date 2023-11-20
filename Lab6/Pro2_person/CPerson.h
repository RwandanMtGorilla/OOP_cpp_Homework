#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class CPerson {
private:
    string name;
    string id;
    int sex; //1 male, 0 fe
    int age;

public:
    CPerson(string n, string i, int s, int a) : name(n), id(i), sex(s), age(a) {}
    ~CPerson() {}

    void print() const {
        cout << "Name: " << name << ", ID: " << id << ", Sex: " << (sex ? "Man" : "Woman") << ", Age: " << age << endl;
    }
};
