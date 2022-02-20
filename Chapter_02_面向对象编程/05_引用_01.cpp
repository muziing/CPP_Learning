#include <iostream>
using namespace std;

int main()
{
    // 引用基本语法
    // 数据类型 &别名 = 原名

    int a = 10;
    // 创建引用
    int &b = a;

    // 引用必须初始化
    // int &c; //错误，未初始化

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 20;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 引用在初始化后，不可以更改
    int d = 100;
    b = d; // 这行代码为赋值，而不能将b改为d的引用

    cout << a << endl;

    return 0;
}