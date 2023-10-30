#include "Student.h"

int main() {
    Student student1;
    student1.print();

    Student student2("John", 21);
    student2.print();

    Student student3 = student2;
    student3.print();

    return 0;
}
