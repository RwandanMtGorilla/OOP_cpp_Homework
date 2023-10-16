#include <iostream>

using namespace std;

// 值传递
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // 不会改变
}

// 指针传递
void swapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;

    swapByValue(x, y);
    cout << "swapByValue: x = " << x << ", y = " << y << endl; 

    swapByPointer(&x, &y);
    cout << "swapByPointer: x = " << x << ", y = " << y << endl; 

    swapByReference(x, y);
    cout << "swapByReference: x = " << x << ", y = " << y << endl; 

    return 0;
}
