// array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    int size;
    T * arr;
public:
    int getSize();
    Array();  // Default constructor
    Array(int size);
    Array(const Array & other);
    Array(T[], int n);
    ~Array();
    Array& operator=(const Array & rhs);
    Array operator+(const Array & rhs) const; // append
    T& operator[](int i); // allow read and write
    const T & operator[](int n) const; // readonly    
    operator T *(); // Convert Array object to T *
    friend ostream & operator <<(ostream & out, const Array<T>& rhs);
};

#include "array_b.cpp"  // Include the implementation file

#endif // ARRAY_H
