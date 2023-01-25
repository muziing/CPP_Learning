/*
函数模板的重载

- 普通函数和可实例化出该函数的函数模板构成重载关系
  在数据类型匹配度相同情况下编译器优先选择普通函数
  除非函数模板可以产生具有更好的数据类型匹配度的实例
- 函数模板的实例化不支持隐式类型转换，但普通函数支持
  在传递参数时如果需要编译器做隐式类型转换，则编译器选择普通函数
- 可以在实例化时用<>强行告知编译器选择函数模板
*/

#include <iostream>

using namespace std;

void Max(int x, int y)
{
    cout << "1: Max(int, int)" << endl;
}

template <class T>
void Max(T x, T y)
{
    cout << "2: Max(T, T)" << endl;
}

int main()
{
    int nx = 10, ny = 20;
    Max(nx, ny); // 在数据类型匹配度相同情况下编译器优先选择普通函数

    double dx = 12.3, dy = 45.6;
    Max(dx, dy); // 除非函数模板可以产生具有更好的数据类型匹配度的实例
    Max(nx, dy); // 在传递参数时如果需要编译器做隐式类型转换，则编译器选择普通函数

    Max<>(nx, ny); // 可以在实例化时用<>强行告知编译器选择函数模板

    return 0;
}