#include <iostream>
using namespace std;

/*
- 普通函数调用时可以发生自动类型转换（隐式类型转换）
- 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
- 如果利用显式指定类型的方式，可以发生隐式类型转换
*/

int myAdd(int a, int b)
{
    return a + b;
}

template <typename T>
T myAdd02(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c'; // 被隐式转换成了 int 类型的 99;
    cout << myAdd(a, b) << endl;
    cout << myAdd(a, c) << endl; // 也可以运行，会发生隐式类型转换
}

void test02()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    // cout << myAdd02(a, c) << endl; // 报错
    cout << myAdd02<int>(a, c) << endl; // 显式指定类型，可以运行，发生隐式类型转换
}

int main()
{
    // test01();
    test02();
    return 0;
}