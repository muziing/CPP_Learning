/*
利用宏构建通用函数框架
- 通过实例化宏，让预处理器将这个宏代换为针对不同数据类型的真正函数
- 将宏的通用性和函数的类型安全性完美结合起来
*/

#include <iostream>
using namespace std;

#define MAX(T)                \
    T max_##T(T x, T y)       \
    {                         \
        return x > y ? x : y; \
    }

MAX(int) // 预编译器会将其替换为如下内容
// int max_int(int x, int y)
// {
//     return x > y ? x : y;
// }

MAX(double)
// double max_double(double x, double y)
// {
//     return x > y ? x : y;
// }

MAX(string)
// 缺陷：代码可读性差，难以理解max_int()等函数的来历

#define Max(T) max_##T // 小技巧，用于解决可读性问题

int main()
{
    int nx = 10, ny = 20;
    // cout << max_int(nx, ny) << endl;
    cout << Max(int)(nx, ny) << endl;

    double dx = 12.3, dy = 45.6;
    // cout << max_double(dx, dy) << endl;
    cout << Max(double)(dx, dy) << endl;

    string sx = "world", sy = "hello";
    // cout << max_string(sx, sy) << endl;
    cout << Max(string)(sx, sy) << endl;

    char cx[256] = "wrold", cy[256] = "hello";
    cout << Max(string)(cx, cy) << endl; // 会触发类型转换，也能正确处理了
    //      max_string(cx, cy)

    return 0;
}