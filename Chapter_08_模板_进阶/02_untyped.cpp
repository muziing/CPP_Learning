/*
宏可摆脱数据类型的限制：
- 宏是在预处理阶段针对代码的纯文本替换
- 宏本身没有函数的语义（不会对数据类型进行检查）
- 因此借助参数宏虽然可以摆脱类型的约束和限制，但也同时丧失了对数据类型的检查
*/

#include <iostream>
using namespace std;

#define Max(x, y) (x > y ? x : y)

int main()
{
    int nx = 10, ny = 20;
    cout << Max(nx, ny) << endl;
    //     (nx > ny ? nx : ny)

    double dx = 12.3, dy = 45.6;
    cout << Max(dx, dy) << endl;

    string sx = "world", sy = "hello";
    cout << Max(sx, sy) << endl;

    char cx[256] = "world", cy[256] = "hellow";
    cout << Max(cx, cy) << endl; // 会出现错误
    //     (cx>cy?cx:cy)  不是比较字符串大小，而是指针大小

    return 0;
}