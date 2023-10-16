#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

void initialize(char[], int*);
void input(char[], int&);
void print(const char*, const int);
void growOlder(const char[], int*);
bool comparePeople(const char*, const int*, const char*, const int*);

int main()
{
    char name1[25];
    char name2[25];
    int age1;
    int age2;

    initialize(name1, &age1);
    initialize(name2, &age2);

    print(name1, age1);
    print(name2, age2);

    input(name1, age1);
    input(name2, age2);

    print(name1, age1);
    print(name2, age2);

    growOlder(name2, &age2);

    if (comparePeople(name1, &age1, name2, &age2))
        cout << "Both people have the same name and age" << endl;

    return 0;
}

void input(char name[], int& age)
{
    cout << "Enter a name: ";
    cin >> name;

    cout << "Enter an age: ";
    cin >> age;
    cout << endl;
}

void initialize(char name[], int* age)
{
    strcpy(name, "");
    *age = 0;
}

void print(const char name[], const int age)
{
    cout << "The value stored in variable name is: "
        << name << endl
        << "The value stored in variable age is: "
        << age << endl << endl;
}

void growOlder(const char name[], int* age)
{
    cout << name << " has grown one year older\n\n";
    (*age)++;
}

bool comparePeople(const char* name1, const int* age1, const char* name2, const int* age2)
{
    return (*age1 == *age2 && strcmp(name1, name2) == 0);
}
