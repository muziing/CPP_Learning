#include <iostream>
using namespace std;

// 函数模板注意事项
// 1.自动类型推导，必须推导出一致的数据类型T才可以使用
// 2.模板必须要确定出T的数据类型，才可以使用

template <typename T> // typename 可以替换为 class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 1.自动类型推导，必须推导出一致的数据类型T才可以使用
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a, b); // 正确
    // mySwap(a, c); // 错误

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 2.模板必须要确定出T的数据类型，才可以使用
template <typename T>
void func()
{
    cout << "func() 调用" << endl;
}

void test02()
{
    // func(); // 错误
    func<int>(); // 可以运行
}

int main()
{
    test01();
    test02();
    return 0;
}