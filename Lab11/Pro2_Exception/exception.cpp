#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    Array(size_t size) : size(size), data(new T[size]) {
        if (data == nullptr) {
            throw std::bad_alloc();
        }
    }

    ~Array() {
        delete[] data;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    try {
        Array<int> myArray(10);
        std::cout << "Array created." << std::endl;
        myArray[0] = 1; // Normal operation
        std::cout << "Element_1 set to 1." << std::endl;

        std::cout << "Trying access out of range" << std::endl;
        myArray[10] = 2; // should throw exception
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range err: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "unknown err" << std::endl;
    }

    return 0;
}
