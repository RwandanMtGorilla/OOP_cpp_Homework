#include <iostream>
using namespace std;
class Shape {       //基类
public:
    virtual void area() {       //虚函数 可以无内容 如果无virtual 则其子类无法覆写
        cout << "shape_area"<<endl;
    }
    //纯虚函数 virtual void area()=0;
    //纯虚函数的类称为抽象类 抽象类不能直接创建对象
    //析构函数最好定义为虚函数
};
class Circle :public Shape {        //派生类Circle
    int radius;
public:
    Circle(int r) {     //构造函数
        radius = r;
    }
    void area() {       //重写父类的area
        cout << "Circle_Area=" << 3.14 * radius * radius << endl;
    }
};
class Rectangle :public Shape {        //派生类Circle
    int width,height;
public:
    Rectangle(int w, int h) {     //构造函数
        width = w;
        height = h;
    }
    void area() {
        cout << "Rectangle_Area=" << width * height << endl;
    }
};
void getArea(Shape* p) {
    p->area();
}
void getArea_(Shape &p) {
    p.area();
}
int main(){
   
    Circle c(1);
    Rectangle r(4, 5);
    getArea(&c);
    getArea(&r);
    cout << "---" << endl;
    getArea_(c);
    getArea_(r);
    cout << "---" << endl;
    Shape s;
    s.area();

    cout << "---" << endl;
    cout << "---" << endl;
    cout << "---" << endl;
    cout << "---" << endl;
    cout << "---" << endl;

    cout << "---" << endl;
    cout << "Hello World!\n";
}

