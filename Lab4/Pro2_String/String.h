#pragma once
#include <iostream>
#include <cstring>

class String {
private:
    char *data;
public:
    String();  // 默认构造函数
    String(const char *str);  // 普通构造函数
    ~String();  // 析构函数
    void assign(const String &other);  // 赋值函数
    void add(const String &other);  // 字符串相加函数
    void print() const;  // 打印函数
};
