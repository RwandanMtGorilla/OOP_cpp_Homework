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
        cout << id << "-" << score << endl;
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
    /*
    Student &operator= (const Student& t) { //可以不用写 默认情况就可用// 如果要写只能写成 成员函数书写在类内
        id = t.id;
        score = t.score;
        cout << "operator'='" << endl;
        return *this;
    }
    */
    friend ostream& operator<<(ostream& ch, const Student& s);  //友元方法实现运算符重载
};
ostream& operator<<(ostream& ch, const Student& s) {    //友元方法实现运算符重载
    cout << s.id << "_" << s.score << endl;
    return ch;
}
int main(){
    Student s1("A001", 95), s2("A002", 98);
    s1.show();
    s2.show();
    cout << "---" << endl;
    cout << s1 << s2 << endl;
    cout << "---" << endl;
    if (s1 > s2) { cout << "MAX=" << s1 << endl; }
    else{ cout << "MAX=" << s2 << endl; }
    cout << "---" << endl;
    Student s3 = ++++++s1++;
    cout << s1 << s3;
    cout << "---" << endl;
    Student s4 = s1;    //调用拷贝构造函数
    Student s5;
    cout << s5;
    s5 = s1;    //调用等号运算符 operator = //可以不用写 默认情况就可用// 如果要写只能写成 成员函数书写在类内
    cout << s5;
    cout << "---" << endl;
    cout << "---" << endl;

    cout << "---" << endl;
    cout << "Hello World!\n";
}

