#include <iostream>
using namespace std;

// 函数默认参数

int func(int a, int b = 10, int c = 10)
{
    return a + b + c;
}

// 注意：如果某个位置参数有默认值，那么从这个位置往后都必须有默认值
// 语法： 返回值类型 函数名 (形参 = 默认值) {函数体}

// 如果函数声明有默认值，函数实现时就不能有默认参数
int func2(int a = 10, int b = 10);

int func2(int a, int b)
{
    return a + b;
}

int main()
{
    cout << func(10, 20, 30) << endl;
    cout << func(10) << endl;
    return 0;
}