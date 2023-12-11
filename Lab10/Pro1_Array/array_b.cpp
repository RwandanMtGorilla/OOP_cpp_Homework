#include <algorithm>
//#include "array_b.h"

template <class T>
int Array<T>::getSize() {
    return size;
}

template <class T>
Array<T>::Array() : size(0), arr(nullptr) {}

template <class T>
Array<T>::Array(int size) : size(size), arr(new T[size]) {}

template <class T>
Array<T>::Array(const Array & other) : size(other.size), arr(new T[size]) {
    std::copy(other.arr, other.arr + size, arr);
}

template <class T>
Array<T>::Array(T arr[], int n) : size(n), arr(new T[n]) {
    std::copy(arr, arr + n, this->arr);
}

template <class T>
Array<T>::~Array() {
    delete[] arr;
}

template <class T>
Array<T>& Array<T>::operator=(const Array & rhs) {
    if (this != &rhs) {
        delete[] arr;
        size = rhs.size;
        arr = new T[size];
        std::copy(rhs.arr, rhs.arr + size, arr);
    }
    return *this;
}

template <class T>
Array<T> Array<T>::operator+(const Array & rhs) const {
    Array result(this->size + rhs.size);
    std::copy(this->arr, this->arr + this->size, result.arr);
    std::copy(rhs.arr, rhs.arr + rhs.size, result.arr + this->size);
    return result;
}

template <class T>
T& Array<T>::operator[](int i) {
    if (i >= 0 && i < size) {
        return arr[i];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
const T& Array<T>::operator[](int i) const {
    if (i >= 0 && i < size) {
        return arr[i];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
Array<T>::operator T*() {
    return arr;
}

template <class T>
ostream& operator<<(ostream & out, const Array<T>& rhs) {
    for (int i = 0; i < rhs.size; ++i) {
        out << rhs.arr[i] << " ";
    }
    return out;
}

template class Array<int>;
template class Array<double>;