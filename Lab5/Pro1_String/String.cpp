#include "String.h"

String::String() : pt(nullptr) {}

String::String(const char *str) {
    if (str) {
        pt = new char[strlen(str) + 1];
        strcpy(pt, str);
    } else {
        pt = nullptr;
    }
}

String::String(const String &s) {
    if (s.pt) {
        pt = new char[strlen(s.pt) + 1];
        strcpy(pt, s.pt);
    } else {
        pt = nullptr;
    }
}

String::~String() {
    delete[] pt;
}

String &String::operator=(const String &s) {
    if (this != &s) {
        delete[] pt;
        if (s.pt) {
            pt = new char[strlen(s.pt) + 1];
            strcpy(pt, s.pt);
        } else {
            pt = nullptr;
        }
    }
    return *this;
}

String &String::add(const String &s) {
    if (!s.pt) return *this;

    char *new_pt = new char[strlen(pt) + strlen(s.pt) + 1];
    strcpy(new_pt, pt ? pt : "");
    strcat(new_pt, s.pt);
    delete[] pt;
    pt = new_pt;
    return *this;
}

String String::add(const String &s) const {
    String temp(*this);
    temp.add(s);
    return temp;
}

void String::print() const {
    std::cout << (pt ? pt : "[empty]") << std::endl;
}
