#include "array_b.h"

int main() {
    Array<int> arr1(5);
    for (int i = 0; i < arr1.getSize(); ++i) {
        arr1[i] = i ;//* 2
    }

    Array<int> arr2 = arr1; // 测试拷贝构造函数
    Array<int> arr3;
    arr3 = arr1; // 测试赋值运算符

    cout << "arr1: " << arr1 << endl;
    cout << "arr2: " << arr2 << endl;
    cout << "arr3: " << arr3 << endl;

    Array<int> arr4 = arr1 + arr2; // 测试加法运算符
    cout << "arr4: " << arr4 << endl;

    return 0;
}
