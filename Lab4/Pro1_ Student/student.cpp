#include "Student.h"

Student::Student() : name("Unknown"), age(0) {
    std::cout << "Default constructor called!" << std::endl;
}

Student::Student(const std::string& n, int a) {
    std::cout << "Parameterized constructor called!" << std::endl;
    name = n;
    age = a;
}

Student::~Student() {
    std::cout << "Destructor called for " << name << "!" << std::endl;
}

void Student::print() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}
