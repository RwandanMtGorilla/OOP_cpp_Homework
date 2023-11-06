#include "String.h"

int main() {
	String s1;
	String s2("hello");

	s1 = s2;  // 表示将s2赋值给s1
	s1.print();

	String s3(" world");

	s1.add(s3); // 表示将s3加到s1中
	s1.print();

    String s4(s2);
    String s5;
    s5 = s4.add(s3); // 表示将s4加上s3赋值给s5中
    s5.print();
}


