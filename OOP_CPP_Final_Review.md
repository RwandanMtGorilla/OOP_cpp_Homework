# C++期末大复习

## [check on github](https://github.com/RwandanMtGorilla/OOP_cpp_Homework/blob/main/OOP_CPP_Final_Review.md)
- reference by wsy: https://namic00.github.io/tags/C-C/

## 题型
选择题 10道、20道或15道  每题2分 

填空题 题目通常涉及基本概念
例 四大强制类型转换 面向对象三大特征

程序阅读题 4-5道 完整写出输出 20分

程序填空题 10分

编程题 两道  例如 制定一个复数类 加减乘除 输出 的重载   字符串类 拷贝赋值  形状类 动物类 汽车类...

Todo: 自己试写一个虚数类

## 内容
### cpp独有的 面向过程的部分
-  引用(右值引用左值引用)
    引用必须被初始化
-  内联函数 inline
-  const
    const 和引用 一起使用 
    const 和指针 一起使用(指针本身是常量)(指针指向的对象是常量)(两个都是常量)
### 面向对象
- 面向对象的三大特征
- 类的定义&用法 见`ClassAndObject.cpp`
- new和delete
- `Myclass obj;` 和 `Myclass obj();` 有什么区别
-  类的三种访问控制属性 Public（公有）Private（私有） Protected（受保护的）
- 函数的重载
- 函数的签名 
- 成员函数/数据成员 前面+const const对象无法调用非const成员函数
- 成员初始化列表
- 一个指向const的类型的指针，不能够直接赋给一个普通的值
- 静态成员变量 static
- 类创建的对象 大小 由非静态的数据成员的大小之和组成的

- 三种继承方式
- 基类子对象的创建
- 继承的隐藏规则
- 继承的类型兼容

- 多态 虚函数
- 多态发生的条件
- this 指针
- 纯虚函数

- 模板
- 实例化

- 仿函数
- 运算符重载
- 特殊运算符

- 输入输出流
- 简单的格式控制

- 异常处理





## 异常处理
在C++中，异常处理是一种处理运行时错误的机制，允许程序在检测到问题时跳出正常的控制流程，并进行错误处理。异常处理使用以下三个关键字：`try`、`catch`和`throw`。

### 基本概念

1. **throw**：当程序遇到无法正常处理的情况时，可以通过`throw`语句抛出一个异常。这个异常可以是任何类型的对象，但通常是从`std::exception`派生的类。

    ```cpp
    throw std::runtime_error("发生错误");
    ```

2. **try**：`try`块定义了一个异常可能发生的代码区块。

    ```cpp
    try {
        // 可能抛出异常的代码
    }
    ```

3. **catch**：`catch`块用于捕获并处理特定类型的异常。可以有多个`catch`块来捕获不同类型的异常。

    ```cpp
    catch (const std::runtime_error& e) {
        // 处理异常
    }
    ```

### 异常处理流程

1. 当`try`块中的代码抛出异常时，程序的执行会跳到对应类型的`catch`块。
2. 如果没有对应类型的`catch`块，程序会向上回溯到调用堆栈中的上一个`try`块。
3. 如果没有找到合适的`catch`块，程序将调用`std::terminate`，默认行为通常是终止程序。

### 异常处理的执行流程

1. **执行`try`块内的代码**：当执行流进入`try`块时，如果`try`块内的代码顺利执行且没有异常发生，`catch`块将被忽略，程序继续向下执行。

2. **异常被抛出**：如果在`try`块内的代码执行过程中抛出了异常，程序会立即停止当前`try`块剩余代码的执行，并跳转到匹配该异常类型的`catch`块。

3. **寻找匹配的`catch`块**：程序会按照它们出现的顺序检查每个`catch`块，寻找一个与抛出的异常类型相匹配的块。一旦找到匹配的`catch`块，控制流就转入该块，开始执行异常处理代码。

4. **异常处理完成**：一旦异常被处理，程序会跳过剩余的`catch`块，继续执行`try-catch`结构之后的代码。

5. **未捕获的异常**：如果没有找到匹配的`catch`块，程序将调用`std::terminate()`，通常导致程序终止。

### 示例

```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        // 假设这里有可能抛出异常的代码
        throw std::runtime_error("发生了一个错误");
    } catch (const std::runtime_error& e) {
        std::cerr << "捕获到异常: " << e.what() << std::endl;
    }
    return 0;
}
```

### 异常匹配
```cpp
#include <iostream>
#include <stdexcept> // 包含标准异常类

int main() {
    try {
        // 假设这里的代码可能抛出多种类型的异常
        throw std::runtime_error("运行时错误发生了");
    } catch (const std::runtime_error& e) {
        // 捕获并处理 std::runtime_error 类型的异常
        std::cout << "捕获到运行时异常: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // 捕获并处理所有派生自 std::exception 的其他异常
        std::cout << "捕获到异常: " << e.what() << std::endl;
    } catch (...) {
        // 捕获所有其他类型的异常
        std::cout << "捕获到未知类型的异常" << std::endl;
    }

    return 0;
}
```
### 注意事项

- **异常安全**：编写异常安全的代码意味着即使发生异常，程序的状态也仍然保持一致和安全。这通常涉及资源管理和对象状态的维护。
- **资源泄漏**：在异常处理中，要注意避免资源泄漏。使用智能指针等RAII（Resource Acquisition Is Initialization）技术可以帮助确保资源被正确释放。
- **性能考虑**：异常处理有一定的运行时成本。在性能敏感的代码中，过度依赖异常处理可能会导致性能问题。
- **标准异常**：C++标准库提供了一系列标准异常类，如`std::runtime_error`、`std::invalid_argument`等，建议使用这些标准异常或从它们派生自定义异常。


## 简单的格式控制
在C++中，标准库提供了多种方式来控制输入/输出流（iostream）的格式。这些格式控制方法允许你更改数据的显示方式，例如设置精度、调整宽度、填充字符和显示基数等。以下是一些常用的格式控制方法：

### 1. 固定和科学记数法

使用`std::fixed`和`std::scientific`来设置浮点数的显示格式。

```cpp
#include <iostream>
#include <iomanip>

double num = 123.456789;

std::cout << std::fixed << num << std::endl;        // 显示固定小数点格式
std::cout << std::scientific << num << std::endl;   // 显示科学记数法格式
```

### 2. 设置精度

使用`std::setprecision`来设置显示的精度。

```cpp
std::cout << std::fixed << std::setprecision(2) << num << std::endl;  // 显示两位小数
```

### 3. 设置宽度和填充

使用`std::setw`来设置下一个输出字段的宽度，使用`std::setfill`来设置填充字符。

```cpp
std::cout << std::setw(10) << num << std::endl;            // 宽度为10
std::cout << std::setw(10) << std::setfill('*') << num << std::endl;  // 宽度为10，用'*'填充
```

### 4. 显示整数基数

使用`std::dec`、`std::oct`和`std::hex`来设置整数的显示基数。

```cpp
int n = 30;

std::cout << std::dec << n << std::endl;  // 十进制
std::cout << std::oct << n << std::endl;  // 八进制
std::cout << std::hex << n << std::endl;  // 十六进制
```

### 5. 布尔值显示格式

使用`std::boolalpha`和`std::noboolalpha`来控制布尔值的显示方式。

```cpp
bool flag = true;

std::cout << std::boolalpha << flag << std::endl;   // 显示 "true" 或 "false"
std::cout << std::noboolalpha << flag << std::endl;  // 显示 "1" 或 "0"
```

### 6. 左对齐、右对齐和内部对齐

使用`std::left`、`std::right`和`std::internal`来控制对齐方式。

```cpp
std::cout << std::setw(10) << std::left << n << std::endl;     // 左对齐
std::cout << std::setw(10) << std::right << n << std::endl;    // 右对齐
std::cout << std::setw(10) << std::internal << n << std::endl; // 内部对齐
```

### 注意

- 格式控制通常持续到被改变或流结束。
- 使用`<iomanip>`头文件中的功能时，需要包含该头文件。


## 输入输出流
在C++中，流（Stream）是一种用于表示数据的输入和输出序列的抽象概念。流提供了一种统一的方式来处理各种类型的输入输出（I/O），无论是文件I/O、控制台I/O，还是内存中的I/O操作。

流主要分为两大类：

### 1. 输入流（Input Stream）
输入流用于从数据源（如文件、控制台、内存缓冲区等）读取数据。在C++标准库中，常见的输入流类包括：

- `std::istream`：表示通用输入流的基类，常用于从标准输入（如键盘）读取数据。
- `std::ifstream`：从文件读取数据的输入文件流类。
- `std::istringstream`：从`std::string`对象读取数据的输入字符串流类。

### 2. 输出流（Output Stream）
输出流用于向数据目的地（如文件、控制台、内存缓冲区等）写入数据。在C++标准库中，常见的输出流类包括：

- `std::ostream`：表示通用输出流的基类，常用于向标准输出（如控制台）写入数据。
- `std::ofstream`：向文件写入数据的输出文件流类。
- `std::ostringstream`：向`std::string`对象写入数据的输出字符串流类。

### 流的特性

- **抽象和封装**：流提供了一种抽象，隐藏了底层的数据读写细节，允许程序员以统一的方式处理I/O操作。
- **操作符重载**：C++中的流类重载了输入运算符`>>`和输出运算符`<<`，使得数据的读取和写入更加直观。
- **缓冲**：大多数流在内部使用缓冲区来提高I/O操作的效率。
- **格式控制**：流提供了格式化功能，允许控制数据的显示格式，如设置精度、基数、对齐方式等。
- **状态管理**：流维护状态标志，以指示I/O操作的成功与否，这些状态可以被查询和控制。

### 示例

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 使用 ofstream 写入文件
    std::ofstream outfile("test.txt");
    outfile << "Hello, World!" << std::endl;
    outfile.close();

    // 使用 ifstream 读取文件
    std::ifstream infile("test.txt");
    std::string line;
    if (getline(infile, line)) {
        std::cout << line << std::endl;
    }
    infile.close();

    return 0;
}
```

在这个例子中，使用`std::ofstream`向文件写入字符串，然后使用`std::ifstream`读取文件内容并输出到控制台。


## 特殊运算符
在C++中，运算符重载允许自定义多种运算符的行为，包括`++`、`--`、`()`和`*`（解引用）。下面详细介绍这些特殊运算符的重载方法和常见用法。

### 1. 重载`++`和`--`运算符

这些运算符通常用于自增（`++`）和自减（`--`），可以重载为成员函数或全局函数。它们可以有前缀和后缀两种形式。

- **前缀**形式：`++obj`和`--obj`。前缀形式直接增加或减少对象的值。
- **后缀**形式：`obj++`和`obj--`。后缀形式增加或减少对象的值，但返回增加或减少前的值。

#### 示例

```cpp
class Counter {
public:
    Counter(int value) : value(value) {}

    // 前缀重载
    Counter& operator++() {
        ++value;
        return *this;
    }

    // 后缀重载
    Counter operator++(int) {
        Counter temp = *this;
        ++(*this);
        return temp;
    }

private:
    int value;
};
```

### 2. 重载`()`运算符
```cpp
class Adder {
public:
    int operator()(int a, int b) const {
        return a + b;
    }
};

Adder add;
int sum = add(3, 4);  // 调用重载的()运算符

```
详见`仿函数`

### 3. 重载`*`运算符

`*`运算符通常用于解引用指针。重载`*`运算符可以让对象的行为类似于指针。

#### 示例

```cpp
class SmartPointer {
public:
    SmartPointer(MyObject* ptr) : ptr(ptr) {}

    MyObject& operator*() const {
        return *ptr;
    }

private:
    MyObject* ptr;
};

SmartPointer myPtr(new MyObject());
MyObject& obj = *myPtr;  // 调用重载的*运算符
```

### 注意事项

- 当重载这些运算符时，应保持它们的语义直观和一致，以确保代码的可读性和可维护性。
- 运算符`++`、`--`和`*`通常作为成员函数重载，以访问和修改类的内部状态。
- 运算符`()`的重载非常灵活，可以接受任意数量和类型的参数，广泛用于创建仿函数。

运算符重载是C++提供的一种强大的自定义行为方式，但如果滥用可能导致代码逻辑复杂和难以理解。因此，应谨慎使用，确保重载的运算符行为直观且符合预期。
## 运算符重载
```cpp
class Point {
public:
    Point(int x, int y) : x(x), y(y) {}

    // 重载+运算符
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    int x, y;
};

Point p1(1, 2);
Point p2(3, 4);
Point p3 = p1 + p2;  // 使用重载的+运算符

```

### 基本概念

- **自定义操作**：通过重载，可以让标准运算符（如`+`、`-`、`*`、`/`、`==`等）在用户定义的类型上执行特定操作。
- **语法**：运算符重载通常通过定义一个特殊的成员函数或全局函数来实现。这个函数使用关键字`operator`后跟运算符的符号来命名。

### 成员函数和全局函数

- **成员函数**：如果运算符被定义为类的成员函数，它的左操作数就是调用它的对象实例。
- **全局函数**：如果运算符被定义为全局函数，需要两个操作数，除非它是一元运算符。

### 注意事项

- **不可重载的运算符**：有些运算符不能被重载，例如`.`、`::`、`.*`、`?:`。
- **保持直观性**：运算符重载应保持操作的直观性和一致性，以避免混淆。
- **重载不改变优先级**：重载一个运算符不会改变它的优先级。


## 仿函数
仿函数是泛型编程强大威力和纯粹抽象概念的又一例证。你可以说，任何东西，只要其行为像函数，它就是一个函数。
<!-- 就是重载了括号 -->
可以通过函数调用运算符`operator()`进行调用的对象。实质上，仿函数是一种使用类重载`operator()`的方式，使得该类的实例能像函数一样被调用。这是一种实现类似函数行为的面向对象技术。

### 定义和使用仿函数

要创建一个仿函数，你需要定义一个类，并为它提供一个或多个`operator()`的重载。例如：

```cpp
class Adder {
public:
    Adder(int n) : n(n) {}

    int operator()(int x) const {
        return n + x;
    }

private:
    int n;
};
```

在这个例子中，`Adder`类重载了`operator()`，可以像函数一样调用它的实例：

```cpp
Adder add5(5);
int result = add5(3);  // 调用 add5.operator()(3)，结果为 8
```

### 为什么使用仿函数

1. **状态保持**：与普通函数相比，仿函数可以维护状态信息。在上面的例子中，`Adder`对象存储了一个`n`值，每次调用都会使用它。

2. **内联调用**：仿函数的调用通常可以被编译器内联，从而提高效率。

3. **泛型编程**：仿函数非常适合用于泛型编程，比如作为算法的参数。在C++标准模板库（STL）中，很多算法接受函数对象作为参数。

4. **可定制性**：通过重载`operator()`，你可以提供多种执行相同任务的方法，增加了代码的灵活性和可重用性。

### 与Lambda表达式的关系

C++11引入了Lambda表达式，它提供了一种更简洁的方式来创建匿名函数对象。实际上，每个Lambda表达式都是一个编译器生成的仿函数类的匿名对象。
例如，以下Lambda表达式：

```cpp
auto add5 = [](int x) { return 5 + x; };
int result = add5(3);  // 结果为 8
```

在底层，这个Lambda表达式是一个匿名类的实例，这个类重载了`operator()`。

### 总结

仿函数在C++中是一种强大的抽象，允许对象像函数一样工作。它们在提高代码的灵活性、表达性和在某些场景下的性能方面发挥着重要作用。

## 实例化
隐式实例化 用到的时候再实例化
显示实例化 不管怎样都放在那里，不管你用不用

- **实例化**是一个编译时过程，涉及到从模板生成具体代码的步骤。
- **调用**是一个运行时过程，指的是执行函数的步骤。
- 在模板的上下文中，实例化是创建具体实现的过程，而调用则是在实例化之后，使用这些生成的实现。对于普通函数和类，只有调用的概念，因为它们在编写时已经是具体实现。

在C++模板编程中，隐式实例化（Implicit Instantiation）和显式实例化（Explicit Instantiation）是两种模板实例化的方法。它们指的是编译器如何从模板生成具体代码的过程。

### 隐式实例化

隐式实例化发生在模板被实际使用时。编译器根据模板使用的上下文自动确定模板参数的具体类型，并生成相应的实例。这是最常见的模板实例化方式。

#### 函数模板的隐式实例化

当你调用一个模板函数时，编译器根据提供的参数类型自动实例化一个具体的函数。

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

// 隐式实例化 add<int>
int sum = add(5, 10);
```

#### 类模板的隐式实例化

当你声明一个模板类的对象时，编译器根据提供的类型参数自动实例化一个具体的类。

```cpp
template <typename T>
class Box {
public:
    T value;
};

// 隐式实例化 Box<int>
Box<int> intBox;
```

### 显式实例化

显式实例化是当你明确告诉编译器要为特定类型生成模板实例的过程。这是通过使用`template`关键字和模板参数来完成的。

#### 函数模板的显式实例化

你可以显式地实例化一个特定类型的模板函数。

```cpp
template int add<int>(int, int);  // 显式实例化 add<int>
```

#### 类模板的显式实例化

类模板也可以被显式实例化。

```cpp
template class Box<double>;  // 显式实例化 Box<double>
```

显式实例化的主要好处是它确保模板对于特定类型只被实例化一次，这可以减少编译时间和生成的二进制文件大小。显式实例化通常在模板定义的源文件中进行。

### 总结
- **隐式实例化**是根据模板的使用自动进行的，适用于大多数情况。
- **显式实例化**是程序员明确指定的，用于控制模板实例化的具体时间和方式，有助于优化编译过程和管理模板实例。

## 模板
样例见`template.cpp`
模板的调用1.隐式2.显示
### 隐式调用
隐式调用 是指编译器根据函数调用或类实例化时提供的参数类型自动推断模板参数的过程。这是使用模板最常见的方式。

### 显式调用


### 类模板
调用必须显式
对于C++中的类模板，其实例化通常需要显式指定模板参数。这是因为编译器无法自动推断出要创建对象的具体类型。

### 类模板的实例化

对于类模板，编译器需要明确知道模板参数的类型才能生成类的实例。因此，必须在声明类模板实例时显式提供这些类型信息。

#### 示例

一个简单的类模板：
```cpp
template <typename T>
class Box {
public:
    T value;
    void set(T newValue) { value = newValue; }
    T get() { return value; }
};
```

为了使用这个模板创建对象，需要显式指定`T`的类型：

```cpp
Box<int> intBox; // 显式指定模板参数为 int
Box<double> doubleBox; // 显式指定模板参数为 double
```

### 函数模板
可隐式可显示（隐式会有一个类型推断不能冲突）



## 虚函数工作机制
C++中的虚函数机制是通过一种名为虚函数表（Virtual Table，通常简称为vtable）的特殊机制实现的。这个机制是实现运行时多态性的关键。

### 虚函数表（vtable）

每个使用虚函数的类都有一个对应的虚函数表。这个表是一个编译时构建的静态数组，包含了指向类中所有虚函数的指针。如果派生类覆盖了某个虚函数，则vtable中对应该函数的指针会被更新为指向派生类中的函数。

### 虚指针（vptr）

每个对象实例中，如果其类含有虚函数，都会隐含一个指针（称为虚指针，vptr），指向其类的虚函数表。这个指针是对象运行时的一部分，因此对象的大小会因为这个指针而增加。

### 虚函数的调用机制

当调用一个对象的虚函数时，实际上发生了以下步骤：

1. **定位vtable**：通过对象的虚指针（vptr）找到它的虚函数表。
2. **索引vtable**：查找vtable中对应该虚函数的条目。
3. **调用函数**：通过vtable中的指针调用适当的函数。

这个过程是在运行时发生的，因此它允许多态性——基类指针或引用可以用来调用实际派生类对象的函数。

### 例子

```cpp
class Base {
public:
    virtual void func() { cout << "Base::func()" << endl; }
};

class Derived : public Base {
public:
    void func() override { cout << "Derived::func()" << endl; }
};

Base* obj = new Derived();
obj->func();  // 调用 Derived::func()
```
- `Base`有一个虚函数`func`，因此它有一个vtable，其中包含指向`Base::func`的指针。
- `Derived`覆盖了`func`，所以它的vtable中的`func`条目指向`Derived::func`。
- 当通过`Base`类型的指针调用`func`时，实际调用的函数是`Derived::func`，因为vptr指向`Derived`的vtable。


## 纯虚函数
### 定义纯虚函数

纯虚函数在基类中这样定义，末尾有`= 0`的语法：

```cpp
class Base {
public:
    virtual void pureVirtualFunction() = 0;
};
```

这里的`pureVirtualFunction`是一个纯虚函数。由于它的存在，`Base`类成为一个抽象类。

### 抽象类

- 一个包含至少一个纯虚函数的类被称为抽象类。
- 你不能创建抽象类的实例，因为抽象类是不完整的。
- 通常用作基类，派生类必须实现所有的纯虚函数，否则它们也将成为抽象类。

### 派生类实现纯虚函数

派生类必须实现基类中的所有纯虚函数，才能创建该派生类的对象：

```cpp
class Derived : public Base {
public:
    void pureVirtualFunction() override {
        // 实现纯虚函数
    }
};
```

### 使用场景

纯虚函数主要用于两个目的：

1. **定义接口**：它们提供了一种方式来定义接口，派生类必须实现该接口才能成为具体类。这强制保证了派生类遵循特定的协议。

2. **多态性**：通过指向基类的指针或引用，可以调用实现在派生类中的函数，从而实现运行时多态。

### 示例

```cpp
class Shape {
public:
    virtual double area() const = 0; // 纯虚函数
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
private:
    double radius;
};

int main() {
    // Shape shape; // 错误：不能实例化抽象类
    Circle circle(5);
    std::cout << "Area: " << circle.area(); // 正确：使用派生类
}
```

在这个例子中，`Shape`是一个抽象类，因为它有一个纯虚函数`area`。`Circle`类继承自`Shape`并实现了`area`函数。因此，你不能创建`Shape`的实例，但可以创建`Circle`的实例。
- 详见`Polymorphism.cpp`


## this指针

在C++中，`this`指针是一个特殊的指针，它被每个非静态成员函数（包括构造函数和析构函数）隐式地使用。`this`指针指向调用函数的对象本身。这允许成员函数访问调用它的对象的成员变量和其他成员函数。

### 主要特性和用途

1. **指向对象本身**：在成员函数内部，`this`指针指向调用该函数的对象实例。

2. **隐式传递**：当你调用一个对象的成员函数时，`this`指针被隐式传递给函数。你不需要显式地提供它。

3. **成员访问**：`this`指针常用于明确指出成员变量或成员函数是属于对象实例的，特别是在可能存在命名冲突的情况下。

4. **链式调用**：`this`指针可以用于实现链式方法调用。通过在成员函数中返回`*this`，可以让函数返回调用它的对象，从而允许连续调用。

5. **返回自身的引用**：成员函数可以通过返回`*this`来返回调用它的对象的引用。

### 示例

```cpp
class MyClass {
public:
    MyClass(int value) : value(value) {}

    MyClass& setValue(int value) {
        this->value = value;  // 明确指出成员变量 value
        return *this;         // 返回*this允许链式调用
    }

    int getValue() const {
        return this->value;   // 使用this指针访问成员变量
    }

private:
    int value;
};

int main() {
    MyClass obj(5);
    obj.setValue(10).setValue(15); // 链式调用
    std::cout << obj.getValue();   // 输出: 15
}
```

在这个示例中，`setValue`函数使用`this->value`明确地访问成员变量`value`，并返回`*this`以支持链式调用。

### 注意事项

- 在静态成员函数中不能使用`this`指针，因为静态成员函数不与任何对象实例关联。
- `this`是一个指针，而不是引用。因此，`this`本身是不可修改的（即你不能让`this`指向另一个对象）。


## 一个类中只有一个虚函数，没有数据成员，那么用该类创建一个对象，那么这个对象的 size 等于多少
含有虚函数的类需要存储额外的信息来支持运行时多态，这通常是通过虚函数表（vtable）实现的。

```cpp
class MyClass {
public:
    virtual void myFunction() {}
};
```

该类的每个对象将包含一个指向虚函数表的指针（虚指针，vptr）。虚指针的大小通常等于指针的大小，这在大多数平台上是4个字节（32位系统）或8个字节（64位系统）。

因此，这样一个类的对象大小至少是虚指针的大小。不过，实际的大小可能受到编译器实现、对齐要求等因素的影响。要精确地了解对象的大小，可以使用`sizeof`运算符：

```cpp
std::cout << "Size of MyClass: " << sizeof(MyClass) << std::endl;
```

这将给出在你的特定系统和编译器配置下的确切大小。在大多数现代系统上，这通常是4或8字节，取决于你的系统是32位还是64位。

## 多态发生的条件

### 多态的类型

在C++中，多态通常有两种类型：

1. **编译时多态**（静态多态）：通过函数重载和模板实现。

2. **运行时多态**（动态多态）：通过虚函数实现。运行时多态更灵活，允许在运行时根据对象的实际类型确定调用哪个函数。
在C++中，实现多态性通常需要满足以下几个条件：

1. **继承**：必须有两个或更多的类通过继承关系相互关联。通常，多态性涉及一个基类和一个或多个派生类。

2. **虚函数**：在基类中必须有虚函数（使用`virtual`关键字声明的函数）。这些虚函数在派生类中可以被覆盖（重写），以提供特定于派生类的行为。

3. **指针或引用**：多态性是通过基类的指针或引用来实现的。对虚函数的调用是通过基类的指针或引用进行的。

4. **覆盖（重写）虚函数**：派生类重写基类中的虚函数，提供特定的实现。在C++11中，可以在派生类中使用`override`关键字显式指明函数重写。

### 示例

```cpp
class Base {
public:
    virtual void print() {
        cout << "Base" << endl;
    }
    virtual ~Base() {}  // 虚析构函数
};

class Derived : public Base {
public:
    void print() override {  // 覆盖基类的虚函数 override可以不写
        cout << "Derived" << endl;
    }
};

void function(Base* base) {
    base->print();  // 多态性的表现
}

int main() {
    Base* b = new Base();
    Base* d = new Derived();

    function(b);  // 输出 "Base"
    function(d);  // 输出 "Derived"

    delete b;  // 清理资源
    delete d;
}
```

在这个示例中，`function`接受一个指向`Base`类对象的指针。当传递`Base`类对象时，调用`Base::print`；当传递`Derived`类对象时，由于多态性，调用`Derived::print`。


## 虚函数
在基类中声明一个函数为虚函数时，你允许它在派生类中被覆盖（重写），使得通过基类指针或引用调用该函数时，可以执行派生类中相应的函数版本。这种行为被称为多态性，是面向对象编程的一个核心概念。

### 基本概念

- **声明虚函数**：使用关键字`virtual`在基类中声明函数。

  ```cpp
  class Base {
  public:
      virtual void show() {
          cout << "Base show" << endl;
      }
  };
  ```

- **在派生类中覆盖虚函数**：在派生类中重写基类中的虚函数。

  ```cpp
  class Derived : public Base {
  public:
      void show() override { // 'override' 是 C++11 中的新关键字，用于显式指明覆盖
          cout << "Derived show" << endl;
      }
  };
  ```

- **多态性**：通过基类的指针或引用调用虚函数时，将根据对象的实际类型调用适当的函数版本。

  ```cpp
  Base* b = new Derived();
  b->show();  // 调用 Derived::show
  ```

### 虚函数的工作原理

- **虚函数表（vtable）**：每个含有虚函数的类都有一个虚函数表。这个表是一个函数指针数组，每个指针指向类中的一个虚函数。

- **虚指针（vptr）**：每个含有虚函数的对象都有一个隐藏的指针（称为虚指针），指向它所属类的虚函数表。当通过基类指针调用虚函数时，会根据虚指针找到正确的函数。

### 虚析构函数

在基类中声明虚析构函数也很重要，尤其是在基类指针指向派生类对象并需要适当清理资源时。

```cpp
class Base {
public:
    virtual ~Base() {
        // 资源清理代码
    }
};
```

如果基类的析构函数不是虚的，那么通过基类指针删除派生类对象可能不会调用派生类的析构函数，可能导致资源泄漏。

### 注意事项

- 如果一个类有任何虚函数，它应该有一个虚析构函数，即使它是空的。
- 虚函数的使用会带来一定的性能开销，因为需要通过虚函数表进行间接调用，但这通常是多态性的必要代价。
- 当不需要多态性时，应避免使用虚函数，以提高性能。

## 继承的类型兼容
在C++中，继承的类型兼容性是一个重要的概念，它涉及到基类和派生类对象之间的关系以及如何相互操作。这个概念主要体现在两个方面：向上转型（Upcasting）和向下转型（Downcasting）。

### 向上转型（Upcasting）

向上转型是指将派生类的指针或引用转换为基类的指针或引用。这是一种安全的转换，因为派生类对象是基类对象的超集，包含了基类的所有成员。

- **隐式转换**：C++允许派生类对象或指针隐式转换为基类的对象或指针。
- **多态性**：向上转型是实现多态性的关键。通过向上转型，可以使用基类指针或引用来调用在派生类中重写的方法。

例如：

```cpp
class Base { /* ... */ };
class Derived : public Base { /* ... */ };

Derived d;
Base *b = &d; // 向上转型，派生类指针转换为基类指针
```

### 向下转型（Downcasting）

向下转型是指将基类的指针或引用转换为派生类的指针或引用。这种转换通常是不安全的，因为基类对象可能不包含派生类特有的成员。

- **显式转换**：向下转型需要显式转换，如使用`dynamic_cast`。
- **运行时检查**：`dynamic_cast`在运行时检查转换的安全性，如果转换不安全（例如，基类指针实际上并不指向派生类对象），则返回`nullptr`。

例如：

```cpp
Base *b = /* ... */;
Derived *d = dynamic_cast<Derived*>(b); // 向下转型
if (d) {
    // 转型成功
} else {
    // 转型失败
}
```


## 继承的隐藏规则
### 名称隐藏的原因
当派生类重新定义了与基类中同名的成员（不论这个成员是数据成员还是成员函数），基类中的同名成员会被隐藏。这是因为C++使用名称查找来决定哪个成员应该被访问。当在派生类中找到了名称匹配的成员时，搜索过程停止，不会继续在基类中查找。

### 函数隐藏
尤其是在成员函数方面，继承的隐藏表现得更明显。即使派生类中的函数与基类中的函数参数不同，基类中所有同名函数也会被隐藏。
```cpp
class Base {
public:
    void func(int x) {
        // ...
    }
};

class Derived : public Base {
public:
    void func(double x) {  // 隐藏了 Base 中的 func(int x)
        // ...
    }
};
```

在这个例子中，尽管`Derived::func(double x)`和`Base::func(int x)`参数类型不同，`Derived`类的`func`函数仍然隐藏了`Base`类的`func`函数。

### 如何访问被隐藏的成员

如果你需要从派生类访问被隐藏的基类成员，你可以：

1. 使用基类的名称来限定成员：

   ```cpp
   Derived d;
   d.Base::func(10);  // 调用 Base 类中的 func(int x)
   ```

2. 在派生类中使用`using`声明，将基类中的成员引入派生类的作用域：

   ```cpp
   class Derived : public Base {
   public:
       using Base::func;  // 引入 Base 类中的 func
       void func(double x) {
           // ...
       }
   };
   ```

   这样做可以使基类中被隐藏的成员在派生类中可见。

### 避免无意的隐藏

为了避免无意中隐藏基类成员，最好的做法是：

- 在派生类中尽量避免使用与基类成员同名的成员。
- 明确地使用`using`声明，表明你打算在派生类中使用基类的成员。
- 使用覆盖（对于虚函数）并确保使用正确的函数签名。

名称隐藏是C++中一个重要但有时会引起混淆的特性，了解它如何工作对于编写清晰和可维护的代码非常重要。

## 基类子对象的创建
在C++中，当一个派生类继承自基类时，派生类的每个对象实际上包含了一个基类的子对象。这个基类子对象表示派生类对象中的基类部分。基类子对象的创建和初始化在派生类对象的创建和初始化过程中自动发生，遵循特定的规则和顺序。

### 创建过程

1. **构造函数的调用顺序**：当创建派生类的对象时，首先调用的是基类的构造函数，然后才是派生类的构造函数。这确保了基类子对象在派生类的任何进一步初始化之前已经被正确地初始化。

2. **成员初始化列表**：在派生类的构造函数中，可以使用成员初始化列表显式地调用基类的构造函数。如果没有显式地调用基类的构造函数，将自动调用基类的默认构造函数（无参数的构造函数）。

3. **析构函数的调用顺序**：与构造函数相反，当派生类对象被销毁时，首先调用的是派生类的析构函数，然后才是基类的析构函数。

### 示例

假设我们有一个基类`Base`和一个从`Base`派生的类`Derived`：

```cpp
class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }

    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor" << std::endl;
    }

    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};
```

当创建`Derived`类的对象时：

```cpp
Derived obj;
```

输出将会是：

```
Base Constructor
Derived Constructor
```

当对象`obj`被销毁时，输出将会是：

```
Derived Destructor
Base Destructor
```
### 指定创建基类子对象的创建方式 
```cpp
class Base {
public:
    Base() {
        // 默认构造函数
    }

    Base(int x) {
        // 带参数的构造函数
    }
};

class Derived : public Base {
public:
    Derived() : Base() {
        // 调用基类的默认构造函数
    }

    Derived(int x) : Base(x) {
        // 调用基类的带参数的构造函数
    }
};

```
## 三种继承方式

C++提供了三种不同的继承方式：公有继承（public）、保护继承（protected）和私有继承（private）。

### 1. 公有继承（Public Inheritance）

公有继承是最常见的继承方式，用于表示“是一个（is-a）”关系。在公有继承中，基类的公有和保护成员在派生类中保持其访问级别。

- 基类的公有成员在派生类中也是公有的。
- 基类的保护成员在派生类中也是保护的。
- 基类的私有成员在派生类中不能直接访问。

公有继承用于表示派生类是基类的一种特殊形式。例如，如果`Dog`是`Animal`的派生类，那么可以说“每个Dog都是一个Animal”。

### 2. 保护继承（Protected Inheritance）

保护继承将基类的公有和保护成员都作为派生类的保护成员。这意味着这些成员在派生类的外部不可访问，但在派生类及其子类中可访问。

- 基类的公有和保护成员在派生类中都是保护的。
- 基类的私有成员在派生类中不能直接访问。

保护继承用得相对较少，它用于限制对基类成员的访问，同时允许进一步的派生。

### 3. 私有继承（Private Inheritance）

私有继承将基类的公有和保护成员都作为派生类的私有成员。这意味着这些成员不再能在派生类的外部访问，即使是派生类的子类也不能访问。

- 基类的公有和保护成员在派生类中都是私有的。
- 基类的私有成员在派生类中不能直接访问。

私有继承表示的是一种“有一个（has-a）”关系或实现细节的继承，而不是“是一个（is-a）”关系。这种继承方式通常用于实现细节的复用，而不是接口的复用。

### 总结

- **公有继承**：用于实现“是一个”关系，表示派生类是基类类型的一个特殊版本。
- **保护继承**：限制对基类成员的访问，同时允许进一步的派生。
- **私有继承**：用于实现细节的复用，表示“有一个”关系，而不是“是一个”关系。


## 静态成员static
在C++中，`static`关键字用于类的成员变量和成员函数，使它们成为类的静态成员。静态成员与类的具体实例无关，而是与类本身关联。

### 静态成员变量

1. **共享**：静态成员变量由该类的所有实例共享。不管你创建了多少个类的对象，都只有一个静态成员变量的副本。
2. **类范围**：静态成员变量存在于类的所有对象之外，但仍然是类的一部分。
3. **初始化**：静态成员变量需要在类定义外部进行初始化（除非它是`const`的整型或枚举类型，在C++17中还包括内联变量）。
4. **访问**：即使没有创建类的实例，也可以访问静态成员变量，只需使用类名和作用域解析运算符`::`。

### 静态成员函数

1. **无法访问非静态成员**：静态成员函数不能访问类的非静态成员变量，也不能调用非静态成员函数。
2. **类范围**：静态成员函数不与类的某个特定对象相关联。
3. **访问**：可以通过类名和作用域解析运算符`::`调用静态成员函数，也可以通过类的对象调用。
### 示例

```cpp
class MyClass {
public:
    static int staticVar; // 静态成员变量

    static void staticFunction() { // 静态成员函数
        // 可以访问 staticVar
        // 不能访问非静态成员
    }

    void nonStaticFunction() {
        // 可以访问 staticVar 和非静态成员
    }
};

int MyClass::staticVar = 0; // 静态成员变量的初始化

int main() {
    MyClass::staticVar = 5; // 通过类名访问
    MyClass::staticFunction(); // 通过类名调用

    MyClass obj;
    obj.nonStaticFunction(); // 通过对象调用
    return 0;
}
```

### 使用场景

- **共享数据**：当需要在类的所有实例间共享数据时，可以使用静态成员变量。
- **工具函数**：当类需要提供一些与其实例无关的功能时，可以使用静态成员函数。

##  一个指向`const`的类型的指针，不能够直接赋给一个普通的值
```cpp
const int ci = 10;
const int *pci = &ci;

// 假设以下赋值是合法的
int *pi = pci; // 错误：试图将const int* 转换为 int*

*pi = 20; // 如果上面的赋值合法，这将修改 const 变量 ci 的值

```
## 成员初始化列表
在C++中，成员初始化列表是类`构造函数`的一部分，用于在构造函数体执行之前初始化类的数据成员。这种初始化方式比在构造函数体内赋值更高效，特别是对于非基本类型的成员。成员初始化列表直接调用成员的构造函数，而不是先默认构造然后赋值。

### 语法
位于构造函数的参数列表之后，由一个冒号(`:`)引导，后跟一个或多个用逗号分隔的初始化器。每个初始化器包括成员变量的名称和用于初始化该成员的括号或花括号括起来的值。

```cpp
class MyClass {
public:
    MyClass(int x, double y) : a(x), b(y) {
        // 构造函数体
    }

private:
    int a;
    double b;
};
```

在这个例子中，`MyClass`的构造函数使用成员初始化列表来初始化其两个成员：`a`和`b`。

### 为什么使用成员初始化列表

1. **效率**：对于非基本类型的成员，使用成员初始化列表比在构造函数体中赋值更有效率，因为它避免了先调用默认构造函数然后再赋值的额外开销。

2. **初始化`const`和引用成员**：`const`成员和引用成员必须在成员初始化列表中初始化，因为它们一旦被定义就必须被初始化，而无法在构造函数体中赋值。

3. **初始化父类成员**：如果类是从另一个类派生的，那么基类的构造函数可以通过成员初始化列表来调用。

4. **初始化成员对象**：如果类的成员是对象，并且这些对象的类只有带参数的构造函数，那么必须在成员初始化列表中初始化这些对象。

### 示例

考虑一个更复杂的例子，包含基类初始化和成员对象初始化：

```cpp
class Base {
public:
    Base(int val) : value(val) {}
private:
    int value;
};

class Member {
public:
    Member(double val) : value(val) {}
private:
    double value;
};

class Derived : public Base {
public:
    Derived(int x, double y) : Base(x), member(y) {}
private:
    Member member;
};
```

在这个例子中，`Derived`类的构造函数使用成员初始化列表来初始化其基类`Base`和成员对象`member`。

## 函数的签名
在编程中，特别是在C++中，函数的签名（Function Signature）是指能够唯一标识函数的那部分信息。函数的名称、参数列表的类型（数量、类型和顺序），但不包括返回类型和参数名。函数的签名用来在函数重载时区分不同的函数。

### 函数签名包括：
1. **函数名称**：函数的名字是其标识的一部分。
2. **参数列表**：
   - **参数的类型**：这是函数签名的关键部分。不同类型的参数会产生不同的签名。
   - **参数的数量**：参数的数量也是函数签名的一部分。
   - **参数的顺序**：参数的顺序可以影响函数签名。

### 函数签名不包括：
1. **返回类型**：函数的返回类型不是函数签名的一部分。这意味着你不能仅仅通过改变函数的返回类型来重载函数。
2. **参数名**：参数的名称不影响函数签名，只有参数的类型、数量和顺序才是重要的。

### 示例
```cpp
int add(int a, int b);
double add(double a, double b);
```
这两个函数虽然具有相同的名称（`add`），但它们具有不同的签名，因为它们的参数类型不同。第一个函数的签名是`add(int, int)`，而第二个函数的签名是`add(double, double)`。

### 在重载中的作用
函数签名在函数重载中非常重要。在C++中，如果两个函数具有相同的名称但不同的签名，则它们被认为是重载的。如果两个函数具有相同的名称和相同的签名，但返回类型不同，则会产生编译错误，因为这被视为同一个函数的两个定义。

## 函数的重载
三个关键点: `同一个作用域中` `同名的函数` `不同的函数签名`.

1. **不同的参数列表**：重载的函数必须在参数类型、数量或顺序上有所不同。返回类型不能用来区分重载的函数。

2. **自动类型转换**：在重载解析过程中，编译器可能会进行自动类型转换，以匹配一个重载。但如果有多个重载都适用，且都需要类型转换，那么代码会产生编译错误（称为模棱两可的调用）。

3. **作用域**：重载的函数必须在同一作用域中。

### 示例
```cpp
#include <iostream>

void print(int i) {
    std::cout << "Integer: " << i << std::endl;
}

void print(double f) {
    std::cout << "Float: " << f << std::endl;
}

void print(const std::string &str) {
    std::cout << "String: " << str << std::endl;
}

int main() {
    print(5);            // 调用 print(int)
    print(3.14);         // 调用 print(double)
    print("Hello, C++"); // 调用 print(const std::string &)

    return 0;
}
```
在这个例子中，函数`print`被重载了三次：一次接受`int`类型的参数，一次接受`double`类型的参数，另一次接受`std::string`类型的参数。当调用`print`时，编译器根据传递的参数类型来确定应该调用哪个版本的`print`。

## 类的三种访问控制属性
- **`public`**：定义类的接口，可被任何人访问。
- **`private`**：隐藏类的实现细节，只允许类自己的成员和友元访问。
- **`protected`**：允许类及其派生类访问，但对其他外部类隐藏。
举例
```cpp
class Base {
private:
    int privateVar; // 私有成员

protected:
    int protectedVar; // 保护成员

public:
    Base() : privateVar(0), protectedVar(0) {}

    int getPrivateVar() const { // 公有成员函数访问私有变量
        return privateVar;
    }
};

class Derived : public Base {
public:
    void func() {
        // privateVar = 1; // 错误：不能访问基类的私有成员
        protectedVar = 1; // 正确：可以访问基类的保护成员
    }
};
```cpp
class Base {
private:
    int privateVar; // 私有成员变量

public:
    Base(int val) : privateVar(val) {}

    int getPrivateVar() const { return privateVar; } // 公有成员函数访问私有变量
};

class Derived : public Base {
public:
    Derived(int val) : Base(val) {}

    void displayPrivateVar() {
        std::cout << "Private Var: " << getPrivateVar() << std::endl; // 间接访问私有成员
    }
};

```
```

## `Myclass obj;` 和 `Myclass obj();` 有什么区别
在C++中，`MyClass obj;`和`MyClass obj();`看起来非常相似，但它们实际上有非常重要的区别。这种区别源于C++的语法规则，尤其是与对象声明和函数声明相关的规则。
1. **`MyClass obj;`**：
   - 这是一个对象声明。
   - 它声明了一个名为`obj`的`MyClass`类型的对象。
   - 此时会调用`MyClass`的默认构造函数（无参数的构造函数）来初始化`obj`。
2. **`MyClass obj();`**：
   - 这看起来像是在声明一个对象，但实际上是一个函数声明。
   - 它声明了一个名为`obj`的函数，这个函数无参数，并返回`MyClass`类型的对象。
   - 这是由于C++的最令人困惑的部分之一——最小惊讶原则（Most Vexing Parse）。当语法可以以多种方式理解时，编译器会选择最不可能的方式，即在这种情况下，它假定`obj`是一个函数声明。


## new和delete
在C++中，`new`和`delete`是用于动态内存分配和释放的操作符。与C语言中的`malloc`和`free`相比，`new`和`delete`不仅处理内存的分配和释放，还涉及对象的构造和析构。

### new

`new`操作符用于动态分配内存，并自动调用对象的构造函数（如果有的话）。它返回指向新分配的内存的指针。如果内存分配失败，`new`会抛出一个`std::bad_alloc`异常，除非使用了`nothrow`版本，这种情况下它会返回一个空指针。

基本语法：

```cpp
TypeName* variable = new TypeName;
```

如果`TypeName`是一个类类型，则这会调用`TypeName`的默认构造函数。对于非基本类型，你还可以在`new`表达式中提供构造函数的参数：

```cpp
TypeName* variable = new TypeName(arguments);
```

对于数组类型：

```cpp
TypeName* array = new TypeName[arraySize];
```

### delete

与`new`相对应，`delete`操作符用于释放由`new`操作符分配的内存，并在释放前自动调用对象的析构函数（如果有的话）。如果尝试`delete`一个未经`new`分配的指针，或者重复`delete`同一个指针，将导致未定义行为。

基本语法如下：

```cpp
delete variable;
```

对于数组类型，需要使用`delete[]`：

```cpp
delete[] array;
```

### 注意事项

- **配对使用**：每个`new`都应该有一个相对应的`delete`，每个`new[]`应该有一个相对应的`delete[]`。不这样做将导致内存泄漏。
- **异常安全**：在涉及`new`的代码中，应该注意异常安全性，确保在抛出异常时能正确地释放已分配的内存。
- **初始化**：`new`操作符还有一个变体`new(std::nothrow)`，它不会在失败时抛出异常，而是返回空指针。这在异常处理不是必需的场合中很有用。
- **避免裸指针**：在现代C++编程中，推荐使用智能指针（如`std::unique_ptr`和`std::shared_ptr`）来自动管理动态分配的内存，这有助于减少内存泄漏的风险。

`new`和`delete`提供了一种灵活的方式来控制对象的生命周期和内存分配，但同时也需要程序员负责确保内存管理的正确性。

## inline

内联函数在适当使用时可以提高程序的性能，特别是对于小型、高频调用的函数。
### 优点
1. **减少函数调用的开销**：由于不需要常规函数调用（如参数传递、栈帧管理等）的开销，程序可能运行得更快。
2. **代码内聚**：有助于保持小型函数的定义与使用在一起，提高代码的可读性。
3. **避免宏的副作用**：内联函数比预处理器宏更安全，因为它们遵循正常的类型检查和作用域规则。
4. **更好的调试体验**：与宏相比，内联函数在调试时通常更容易处理，因为它们遵循正常的函数调用规则。

### 缺点
1. **增加二进制文件大小**：如果内联函数在多处被使用，每个调用点都会插入函数体的副本，从而增加最终可执行文件的大小。
2. **可能的性能损失**：过度使用内联可能会导致程序的整体性能下降，特别是当内联大型函数时，可能导致缓存不命中率增高。
3. **编译器可能忽略内联请求**：内联仅仅是一个对编译器的建议，编译器可以选择忽略这个建议。尤其是对于复杂或大型的函数，编译器可能不会进行内联。
4. **编译时间可能增加**：因为编译器需要花费额外的时间来处理内联函数的展开。
5. **代码管理复杂度**：如果内联函数定义在头文件中，任何对内联函数的修改都需要重新编译所有包含该头文件的源文件，这可能导致编译依赖性增加。


## const
在C++中，`const`关键字用于声明变量为常量，意味着一旦初始化后，其值就不能被修改。`const`可以与引用和指针结合使用，但它的意义会根据其位置不同而有所不同。

### `const` 和 引用

当`const`和引用一起使用时，它创建了一个对常量的引用，也就是说，引用的对象不能通过这个引用被修改。

```cpp
int value = 5;
const int& ref = value; // ref 是对整数的常量引用
// ref = 10; // 错误：不能通过常量引用修改值
```

在这个例子中，尽管`value`本身不是`const`，你仍然不能通过`const`引用`ref`来修改它的值。这种引用通常用于函数参数，以确保函数不会修改传入的参数。

### `const` 和 指针

当`const`与指针一起使用时，情况就更复杂一些，因为它可以应用于指针所指向的数据，也可以应用于指针本身，甚至两者都适用。

#### 指针本身是常量

如果`const`放在`*`的左边，则指针指向的对象是常量，不能通过这个指针来修改所指向的数据。

```cpp
int value = 5;
const int* ptr = &value; // ptr 是指向常量的指针
// *ptr = 10; // 错误：不能通过指向常量的指针修改值
ptr = nullptr; // 正确：可以修改指针本身
```

#### 指针指向的对象是常量

如果`const`放在`*`的右边，指针本身是常量，不能修改指针的值，但可以修改指针指向的数据。

```cpp
int value = 5;
int* const ptr = &value; // ptr 是一个常量指针
*ptr = 10; // 正确：可以修改指针所指向的数据
// ptr = nullptr; // 错误：不能修改常量指针的值
```

#### 两者都是常量

当然，也可以使指针本身和它所指向的对象都成为常量。

```cpp
int value = 5;
const int* const ptr = &value; // ptr 是一个指向常量数据的常量指针
// *ptr = 10; // 错误：不能通过指向常量的指针修改值
// ptr = nullptr; // 错误：不能修改常量指针的值
```

在这种情况下，既不能通过指针修改其指向的数据，也不能修改指针本身的值。这种类型的指针通常用于指向不应该被修改的数据的场景，同时确保指针本身也不会被意外改变。



## 引用
### 左值引用
左值引用通常用于：

- 函数参数传递，使得函数可以直接修改传入的参数。
- 函数返回值，使得函数可以返回一个对象的引用而非副本。
- 创建对象的别名，提高代码可读性和效率。

```cpp
int a = 5;
int& ref = a; // ref 是变量 a 的左值引用
ref = 10; // 现在 a 的值是 10
```

### 右值引用
右值引用是C++11中引入的新特性，它必须绑定到一个右值，即一个临时对象或即将被销毁的对象。右值引用的主要目的是支持移动语义（Move Semantics）和完美转发（Perfect Forwarding）。它们使得资源（如动态分配的内存）可以从一个对象转移到另一个对象，从而提高性能并减少不必要的资源复制.

语法示例：
```cpp
int&& rref = 5; // rref 是一个右值引用
```
当函数返回一个右值引用时，它通常返回一个临时对象：
```cpp
int&& foo() {
    return 5;
}
```
#### 移动语义（Move Semantics）
移动语义允许资源的所有权从一个对象转移到另一个对象，这通常在使用右值引用作为函数参数时发生：
```cpp
class MyClass {
public:
    MyClass(MyClass&& other) { // 移动构造函数
        // 接管 other 的资源
    }
};
```
#### 完美转发（Perfect Forwarding）
完美转发是指在函数模板中，完全以其接收的参数的形式将参数转发给另一个函数。这通常通过使用模板和右值引用实现：
```cpp
template <typename T>
void wrapper(T&& arg) {
    foo(std::forward<T>(arg)); // 完美转发 arg 给 foo
}
```


## 四大强制类型转换
1. **`static_cast`**：
   - **定义**：用于非多态类型的转换。
   - **用法**：基本类型间的转换，类层次中向上转换（子类到基类）。
    ```cpp
    double d = 9.5;
    int i = static_cast<int>(d); // 将 double 转换为 int
    ```

2. **`dynamic_cast`**：
   - **定义**：用于多态类型的安全转换。
   - **用法**：类层次中的向下转换（基类到子类），需要基类有虚函数。
    ```cpp
    class Base { virtual void dummy() {} };
    class Derived : public Base { int a; };

    Base *base_ptr = new Derived;
    Derived *derived_ptr = dynamic_cast<Derived*>(base_ptr); // 向下转换
    ```
3. **`const_cast`**：
   - **定义**：用于移除或添加`const`属性。
   - **用法**：去除或添加对象的`const`或`volatile`属性。
    ```cpp
    const int a = 10;
    int* b = const_cast<int*>(&a);
    *b = 20; // 去除了 a 的 const 属性
    ```
4. **`reinterpret_cast`**：
   - **定义**：用于各种不同类型的指针或引用之间的低级转换。
   - **用法**：进行任意指针类型之间的转换，或指针与足够大的整数类型之间的转换。
    ```cpp
    int *a = new int(65);
    char *b = reinterpret_cast<char*>(a); // 将 int* 转换为 char*
    ```

## 面向对象编程的三大基本特征

1. **封装（Encapsulation）**：
   - 封装是将对象的数据（属性）和操作该数据的方法（函数）捆绑在一起的过程。
   - 它隐藏了类的内部实现细节，只对外暴露必要的接口。这有助于减少系统的复杂性，并增加其可重用性和安全性。
   - 在C++中，通常通过将类成员声明为`private`或`protected`来实现封装。

2. **继承（Inheritance）**：
   - 继承允许一个类（称为子类或派生类）继承另一个类（称为基类或父类）的属性和方法。
   - 这使得可以在现有代码的基础上创建新类，提高了代码的可重用性。
   - 继承还支持多态性的实现。在C++中，继承可以是公有的（public）、保护的（protected）或私有的（private）。

3. **多态（Polymorphism）**：
   - 多态性是指允许不同类的对象对同一消息作出不同的响应。
   - 在编程中，它通常通过方法重载（Compile-time Polymorphism）和方法重写（Runtime Polymorphism）来实现。
   - 在C++中，运行时多态通常通过使用虚函数来实现。当一个基类声明一个虚函数时，派生类可以重写这个函数，实现不同的行为。
