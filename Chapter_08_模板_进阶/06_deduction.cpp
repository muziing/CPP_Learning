/*
隐式推断类型实参

- 如果函数模板的调用形参与类型形参相关，
- 那么在实例化函数模板时即使不显式指明函数模板的类型实参，编译器
  也有能力根据调用实参的类型隐式推断出正确的类型实参的类型
- 获得和调用普通函数一致的语法表现形式
- 三种不能做隐式推断的情况：
  1.调用参数 和 类型参数 不完全相关
  2.隐式推断不支持隐式类型转换
  3.返回值类型不支持隐式推断

*/

#include <iostream>

using namespace std;

// 函数模板
template <class T>
T Max(T x, T y)
{
    return x > y ? x : y;
}

template <class T, class D>
void Func(D x)
{
    // 调用参数和类型参数不完全相关，无法隐式推断T的类型
}

template <class R, class T>
R Hum(T x)
{
    R r;
    // 返回值类型不支持隐式推断
    return r;
}

int main()
{
    int nx = 10, ny = 20;
    cout << Max<>(nx, ny) << endl;
    //      Max<int>(nx, ny)

    double dx = 12.3, dy = 45.6;
    cout << Max(dx, dy) << endl;
    //      Max<double>(dx, dy)

    string sx = "world", sy = "hello";
    cout << Max(sx, sy) << endl;

    // Func(nx); // 调用参数和类型参数不完全相关，无法隐式推断T的类型
    Func<string>(nx);
    // Func<string, int>(nx)

    // Max(nx, dy); // 隐式推断不支持隐式类型转换
    Max(nx, (int)dy);

    // Hum(nx); // 返回值类型不支持隐式推断
    Hum<double>(nx);

    return 0;
}