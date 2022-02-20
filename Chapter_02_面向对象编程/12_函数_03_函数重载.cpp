#include <iostream>
using namespace std;

// 函数重载
/*
作用：函数名可以相同，提高复用性

条件：
- 同一个作用域下
- 函数名称相同
- 函数参数类型不同或个数不同或顺序不同

注意：函数的返回值不可以作为函数重载的条件

*/

void func()
{
    cout << "调用了func" << endl;
}

void func(int a)
{
    cout << "调用了func(int a)" << endl;
}

void func(double a)
{
    cout << "调用了func(double a)" << endl;
}

// 函数重载遇到引用
// 有无 const 可以作为重载条件

void func2(int &a) //func2(10) 等效于 int &a = 10; 不合法，故不使用本实现
{
    cout << "调用了func2(int &a)" << endl;
}

void func2(const int &a) //func2(10) 等效于 const int &a = 10; 合法,使用本实现
{
    cout << "调用了func2(const int &a)" << endl;
}

// 函数重载遇到默认参数

void func3(int a)
{
    cout << "调用了func3(int a)" << endl;
}

void func3(int a, int b = 10)
{
    cout << "调用了func3(int a, int b = 10)" << endl;
}

int main()
{
    func();
    func(10);
    func(3.14);

    int a = 10;
    func2(a);  // 对应 int &a
    func2(10); // 对应 const int &a

    // func3(10); // 出错，同时满足两种实现的参数情况，出现二义性，需要避免
    func3(10, 20); // 可以执行

    return 0;
}