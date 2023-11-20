#include <iostream>
#include "CEmployee.h"

using std::cin;
using std::string;

int main() {
    string name, id, department;
    int sex, age;
    float salary;
    cout << "plz input employee's name, id, sex (0:female, 1:male), age, department, salary:\n";
    cin >> name >> id >> sex >> age >> department >> salary;
    CEmployee employee1(name, id, sex, age, department, salary);
    employee1.print();
    return 0;
}
