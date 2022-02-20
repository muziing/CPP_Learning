#include <iostream>
using namespace std;

// 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    // 作用：函数传参时，可以利用引用的技术让形参修饰实参
    // 优点：可以简化指针修改实参

    int a = 10;
    int b = 20;

    // mySwap01(a, b); // 值传递，形参不会修饰实参
    // mySwap02(&a, &b);
    mySwap03(a, b); // 引用传递，形参会修饰实参

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}