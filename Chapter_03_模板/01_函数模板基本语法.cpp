#include <iostream>
using namespace std;

/*

函数模板作用：
建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表

语法：
template<typename T>
函数声明或定义

语法解释：
- template 声明创建模板
- typename 表明其后的符号是一种数据类型，可以用class代替
- T 通用的数据类型，名称可以更换，通常为大写字母

*/

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;

    // 利用函数模板交换
    // 使用函数模板方式
    // 1、自动类型推导
    // mySwap(a, b);
    // 2、显式指定类型
    mySwap<int>(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    test01();
    return 0;
}
