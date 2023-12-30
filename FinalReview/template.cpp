#include <iostream>
using namespace std;



class Student {
    string id;
    int score;
public:
    Student(string i, int s) {
        id = i;
        score = s;
    }
    Student() {
        id = "NULL";
        score = -1;
    }
    void show() {
        cout << id << "-" << score;
    }
    bool operator> (const Student& s) { //成员函数方法实现运算符重载
        if (score > s.score) {
            return true;
        }
        else {
            return false;
        }
    }

    Student &operator++() { //前置'++'    因为要进行连续的引用 所以返回自身的引用'&'而非新的对象
        score++;
        return *this;
    }
    Student operator++ (int) {
        Student temp = *this;
        score++;
        return temp;

    }

    friend ostream& operator<<(ostream& ch, const Student& s);  //友元方法实现运算符重载
};
ostream& operator<<(ostream& ch, const Student& s) {    //友元方法实现运算符重载
    cout << s.id << "_" << s.score;
    return ch;
}
template<typename T>    //typename||class
T max_(T a, T b) {  //函数模板
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}


template<typename T>    // Box 类模板的定义
class Box {
private:
    T data;
public:
    Box(T d) : data(d) {}

    void set(T d) {
        data = d;
    }

    T get() const {
        return data;
    }

    friend ostream& operator<<(ostream& os, const Box<T>& box) {
        os << box.data;
        return os;
    }
};
int main(){
    Student s1("A001", 95), s2("A002", 98);
    s1.show();
    s2.show();
    cout << "---" << endl;
    cout << "MAX=" << max_(s1, s2) << endl;
    cout << "---" << endl;
    cout << "---" << endl;
    // 使用 Box 类模板
    Box<int> intBox(10);
    Box<float> floatBox(3.14f);
    Box<Student> studentBox(s1);

    cout << "Box Contents:" << endl;
    cout << "Integer Box: " << intBox << endl;
    cout << "Float Box: " << floatBox << endl;
    cout << "Student Box: " << studentBox << endl;

    cout << "---" << endl;
    cout << "Hello World!\n";
}

