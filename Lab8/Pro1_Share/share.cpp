#include <iostream>

using namespace std;

class A {
public:
    A() { n = 0; }
    int n;
};

class share {
public:
    // 构造函数
    explicit share(A* p1 = nullptr) : point(p1) {}

    // 析构函数
    ~share() {
        delete point;
        cout << "begin to delete share" << endl;
    }

    // 拷贝构造函数
    share(share& t2) {
        point = t2.point;
        t2.point = nullptr;
    }

    // 赋值操作符
    share& operator =(share& t2) {
        if (this != &t2) {
            delete point;
            point = t2.point;
            t2.point = nullptr;
        }
        return *this;
    }

    // 箭头操作符
    A* operator ->() {
        return point;
    }

    // 解引用操作符
    A& operator *() {
        return *point;
    }

private:
    A* point;
};


int main() {
    share sp(new A());
    sp->n = 10;

    share sp2 = sp;
    cout << "sp2->n is :" << sp2->n << endl;

    return 0;
}


// int main() {
// 	share sp(new A());
// 	sp->n = 10;
// 	share sp2 = sp;
// 	cout << "sp2->n is :" << sp2->n << endl;
// cout << "sp->n is :" << sp->n << endl;

// A a;
// share sp3(&a);
// sp = sp3;
// cout << "sp->n is :" << sp->n << endl;

// 	return 0;
// }

