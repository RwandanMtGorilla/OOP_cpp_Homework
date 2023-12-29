#include <iostream>
using namespace std;
class Date {
private:
    int year, month, day;
public:
    //构造函数和析构函数会自动调用 创建对象时调用构造函数 撤销对象的时候调用析构函数
    
    Date(int y, int m, int d) {//(int y=0, int m=0, int d=0)含默认参数防止无参数调用时报错
        year= y;
        month=m ;
        day=d;
        cout << "构造函数_普通" << endl;
    }
    Date() {//或者使用不带参数的构造函数
        year = 0;
        month = 0;
        day = 0;
        cout << "构造函数_不带参" << endl;
    }
    Date(const Date& t) {
        year = t.year;
        month = t.month;
        day = t.day;
        cout << "构造函数_拷贝" << endl;
    }
    ~Date() {//析构函数 可以不写 撤销对象的时候调用析构函数 析构函数的运行顺序与构造函数时相反
        cout << "析构函数_Date" << endl;
    }
    void show() {
        cout << year << " " << month << " " << day << endl;
    }
    void show_c() const {
        cout << year << " " << month << " " << day << endl;
    }
       
};

class Person {
private:
    string name;
    int age;
    char gender;
    Date date;
    static int count;//小范围全局变量
public:
    Person(string n, int a, char g, int y, int m, int d) :date(y, m, d) {
        name = n;
        age = a;
        gender = g;
        count++;
        cout << "构造函数_普通_Person" << endl;
    }
    Person() {
        date=Date();
        name = "NULL";
        age = -1;
        gender = 'N';
        count++;
    }
    ~Person() {
        cout << "析构函数_Person" << endl;
        count--;
    }
    void show() {
        cout << name << "-" << age << "-" << gender<<endl;
        date.show();
        cout << "count:"<<count << endl;
    }
    void show_c() const{
        //name="Rax";//常成员函数中不允许修改
        cout << name << "-" << age << "-" << gender << endl;
        date.show_c();//常成员函数 调用的也只能是常成员函数
        cout << "count:" << count << endl;
    }
    static void showCount() {
        cout << "COUNT:" << count << endl;
    }
    friend ostream& operator<<(ostream& q, const Person& p);//使用友元允许该函数访问其私有成员
};
class Student :public Person {
private:
    int grade, score;
public:
    Student(string n, int a, char g, int y, int m, int d, int grade, int s ):Person(n,a,g,y,m,d) {
        this->grade = grade;
        score = s;
        cout << "构造函数_普通_Student" << endl;
    }
    ~Student() {
        cout << "析构函数_Student" << endl;
    }
    void show() {
        Person::show();
        cout << grade << "_" << score<< "_" << endl;
    }
};
ostream& operator<<(ostream& q, const Person& p) {
    cout << p.name << "-" << p.age << "-" << p.gender << endl;
    p.date.show_c();//使用了const所以使用_c
    return q; // 返回输出流对象
}
int Person::count = 0;
int main(){
   
    Person p("Rex", 19, 'M', 2023, 1, 1);
    p.show();
    cout << "---" << endl;
    Student s("Rex_Senior", 19, 'M', 2023, 1, 1,5,100);
    s.show();
    cout << "---" << endl;
    cout << "---" << endl;
    cout << "---" << endl;
    cout << "---" << endl;
    cout << "---" << endl;
    cout << "---" << endl;

    cout << "---" << endl;
    cout << "Hello World!\n";
}


// 选中 然后使用Ctrl+C，Ctrl+k进行批量注释
   //Date d(2023, 12, 17);
   //d.show();

   //Date d2 = d;//浅拷贝
   //d2.show();
   //Date d3;
   //d3 = d;
   //d3.show();
   //cout << "---" << endl;
   //Date* p;//定义对象指针
   //p = &d;
   //p->show();
   //(*p).show();
   //cout << "---" << endl;
   //Date q[3] = { Date(2024,1,1),Date(2024,1,2),Date(2024,1,3) };
   //q[2].show();
   //cout << "---" << endl;
   //Date& w = d;//对象的引用
   //w.show();
   //cout << "---" << endl;
   //Date* Dy = new Date(2004, 7, 27);//动态申请一个对象 
   //Dy->show();
   //delete Dy;
/*
const Person p1("Rex", 19, 'M', 2023, 1, 1);
    p1.show_c();//常对象只能调用常成员函数
    cout << "---" << endl;
    Person* p2 = new Person;
    p2->show();
    delete p2;
    cout << "---" << endl;
    Person p3("Rex", 19, 'M', 2023, 1, 1);
    p3.show();
    cout << "---" << endl;
    Person::showCount();//通过静态成员函数show静态private变量
    cout << "---" << endl;
    cout << "--" << p1 << endl;


*/