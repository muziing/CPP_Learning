#include <iostream>
using namespace std;

// 返回局部变量引用
// int &test01()
// {
//     int a = 10; // 局部变量 存放在内存四区中的栈区
//     return a;
// }

// 返回静态变量引用
int &test02()
{
    static int a = 20;
    return a;
}

int main()
{
    // 引用可以作为函数返回值
    // 注意：不要返回局部变量引用
    // 用法：函数调用作为左值

    // int &ref = test01(); // 编译时会报错
    int &ref = test02(); // 编译时会报错

    cout << "ref = " << ref << endl;

    test02() = 1000; // 相当于 a = 1000;

    // 如果函数的返回值是引用，则该函数调用可以作为左值

    cout << "ref = " << ref << endl;

    return 0;
}