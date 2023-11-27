#include <iostream>

using namespace std;

class A {
public:
    A() { n = 0; }
    int n;
};

class share {
public:
    // 默认构造函数
    share() : point(nullptr), count(new int(0)) {}

    // 显式构造函数
    explicit share(A* p1) : point(p1), count(new int(1)) {}

    // 析构函数
    ~share() {
        // 减少引用计数并在没有引用时删除资源
        if (--(*count) == 0) {
            delete point;
            delete count;

        }
    }

    // 拷贝构造函数
    share(share& t2) : point(t2.point), count(t2.count) {
        // 增加引用计数
        (*count)++;
    }

    // 赋值操作符
    share& operator=(share& t2) {
        if (this != &t2) {
            // 减少当前对象的引用计数并在没有引用时删除资源
            if (--(*count) == 0) {
                delete point;
                delete count;
            }

            // 拷贝新的数据
            point = t2.point;
            count = t2.count;
            (*count)++;
        }
        return *this;
    }

    // 箭头操作符
    A* operator->() {
        return point;
    }

    // 解引用操作符
    A& operator*() {
        return *point;
    }

private:
    A* point;
    int* count; // 引用计数
};

int main() {
    share sp(new A());
    sp->n = 10;
    cout << "sp->n is :" << sp->n << endl;

    share sp2(sp);
    sp2->n = 20;
    cout << "sp->n is :" << sp2->n << endl;

    share sp3;
    sp3 = sp2;
    sp3->n = 30;
    cout << "sp->n is :" << sp2->n << endl;

    return 0;
}

// int main() {
// 	share sp(new A());
// 	sp->n = 10;
// 	cout << "sp->n is :" << sp->n << endl;
// 	share sp2(sp);
// 	sp2->n = 20;
// 	cout << "sp2->n is :" << sp2->n << endl;
// 	share sp3(new A());
// 	sp3->n = 30;
//     sp = sp3;
// 	cout << "sp->n is :" << sp->n << endl;
//     A a;
//     a = *sp2;
//     cout << "a.n is :" << a.n << endl;
// 	return 0;
// }

