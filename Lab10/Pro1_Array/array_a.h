#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    int size;
    T* arr;

public:
    int getSize() { return size; }
    Array() : size(0), arr(nullptr) {}
    Array(int size) : size(size), arr(new T[size]) {}
    Array(const Array & other) : size(other.size), arr(new T[other.size]) {
        copy(other.arr, other.arr + size, arr);
    }
    Array(T arr[], int n) : size(n), arr(new T[n]) {
        copy(arr, arr + n, this->arr);
    }
    ~Array() { delete[] arr; }
    Array& operator=(const Array & rhs);
    Array operator+(const Array & rhs) const;
    T& operator[](int i) { return arr[i]; }
    const T& operator[](int i) const { return arr[i]; }
    operator T*() { return arr; }

    friend ostream & operator <<(ostream & out, const Array<T>& rhs) {
        for (int i = 0; i < rhs.size; ++i) {
            out << rhs.arr[i] << " ";
        }
        return out;
    }
};

template <class T>
Array<T>& Array<T>::operator=(const Array<T> & rhs) {
    if (this != &rhs) {
        delete[] arr;
        size = rhs.size;
        arr = new T[size];
        copy(rhs.arr, rhs.arr + size, arr);
    }
    return *this;
}

template <class T>
Array<T> Array<T>::operator+(const Array<T> & rhs) const {
    Array result(this->size + rhs.size);
    copy(arr, arr + this->size, result.arr);
    copy(rhs.arr, rhs.arr + rhs.size, result.arr + this->size);
    return result;
}

#endif // ARRAY_H
