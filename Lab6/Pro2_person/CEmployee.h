#include "CPerson.h"

class CEmployee : public CPerson {
private:
    string department;
    float salary;

public:
    CEmployee(string name, string id, int sex, int age, string dept, float sal)
        : CPerson(name, id, sex, age), department(dept), salary(sal) {}

    ~CEmployee() {}

    void print() const {
        CPerson::print();
        cout << "Department: " << department << ", Salary: " << salary << endl;
    }
};
