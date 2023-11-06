#pragma once
#include <iostream>
#include <cstring>

class String {
private:
    char *pt;

public:
    String();  // 默认构造函数
    ~String();  // 析构函数
    String(const char *str);  // 普通构造函数
    String(const String &s);  // 拷贝构造函数
    String &operator=(const String &s);  // 赋值运算函数

    String &add(const String &s);  // 修改当前对象，并返回引用
    String add(const String &s) const;  // 返回新对象
    void print() const;  // 打印函数
};
