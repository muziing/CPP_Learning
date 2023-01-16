/*
模板起源：
C++为静态类型语言，在效率与类型安全方面有极大优势。但这种语言也在很大程度上为程序员编写通用性更强的
代码带来瓶颈：即使是抽象层面一致的，也不得不为每一种数据类型各自编写一份（近乎）完全相同的代码实现
*/

#include <iostream>
using namespace std;

int max_int(int x, int y)
{
    return x > y ? x : y;
}

double max_double(double x, double y)
{
    return x > y ? x : y;
}

string max_string(string x, string y)
{
    return x > y ? x : y;
}

int main()
{
    int nx = 10, ny = 20;
    cout << max_int(nx, ny) << endl;

    double dx = 12.3, dy = 45.6;
    cout << max_double(dx, dy) << endl;

    string sx = "world", sy = "hello";
    cout << max_string(sx, sy) << endl;

    return 0;
}