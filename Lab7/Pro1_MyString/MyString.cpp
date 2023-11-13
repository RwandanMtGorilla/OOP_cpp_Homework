#include <cstring>
#include <iostream>

class MyString {
public:
    // 构造函数
    MyString(const char *str = nullptr) {
        if (str) {
            m_data = new char[strlen(str) + 1];
            strcpy(m_data, str);
        } else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    // 拷贝构造函数
    MyString(const MyString &other) {
        m_data = new char[strlen(other.m_data) + 1];
        strcpy(m_data, other.m_data);
    }

    // 析构函数
    ~MyString() {
        delete[] m_data;
    }

    // 赋值运算符
    MyString &operator=(const MyString &other) {
        if (this != &other) {
            delete[] m_data;
            m_data = new char[strlen(other.m_data) + 1];
            strcpy(m_data, other.m_data);
        }
        return *this;
    }

    // 加法运算符
    MyString operator+(const MyString &other) {
        MyString newStr;
        delete[] newStr.m_data;
        newStr.m_data = new char[strlen(m_data) + strlen(other.m_data) + 1];
        strcpy(newStr.m_data, m_data);
        strcat(newStr.m_data, other.m_data);
        return newStr;
    }

    // 索引运算符
    char &operator[](size_t index) {
        return m_data[index];
    }

    // 常量版本的索引运算符
    const char &operator[](size_t index) const {
        return m_data[index];
    }

    // 用于输出的友元函数
    friend std::ostream &operator<<(std::ostream &os, const MyString &str) {
        os << str.m_data;
        return os;
    }

private:
    char *m_data; // 指向堆上分配的用于存储字符串的内存
};

int main() {
    MyString str1("Hello, ");
    MyString str2("World!");
    MyString str3 = str1 + str2;
    std::cout << str3 << std::endl;
    return 0;
}
