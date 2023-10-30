#include "String.h"

int main() {
    String s1;
    String s2("hello");

    s1.assign(s2);  // 表示将s2赋值给s1
    s1.print();

    String s3(" world");

    s1.add(s3); // 表示将s3加到s1中
    s1.print();

    return 0;
}
