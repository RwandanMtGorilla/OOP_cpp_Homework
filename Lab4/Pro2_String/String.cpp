#include "String.h"

String::String() : data(nullptr) {
}

String::String(const char *str) {
    if (str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    } else {
        data = nullptr;
    }
}

String::~String() {
    delete[] data;
}

void String::assign(const String &other) {
    if (this == &other) return;

    delete[] data;
    if (other.data) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    } else {
        data = nullptr;
    }
}

void String::add(const String &other) {
    if (!other.data) return;

    if (!data) {
        assign(other);
    } else {
        char *new_data = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(new_data, data);
        strcat(new_data, other.data);
        delete[] data;
        data = new_data;
    }
}

void String::print() const {
    if (data) {
        std::cout << data << std::endl;
    } else {
        std::cout << "String is empty!" << std::endl;
    }
}
