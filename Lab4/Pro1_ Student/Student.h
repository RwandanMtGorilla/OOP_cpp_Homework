#pragma once
#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int age;
public:
    Student();  
    Student(const std::string& n, int a);  
    ~Student();  
    void print() const; 
};
