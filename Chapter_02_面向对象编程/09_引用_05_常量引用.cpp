#include <iostream>
using namespace std;

// 引用使用的场景：通常用来修饰形参
void showValue(const int &v)
{
    // v += 10; // 不能修改
    cout << v << endl;
}

int main()
{
    int a = 10;
    // int &ref = 10; // 引用必须引一块合法的内存空间，本行为错误
    const int &ref = 10; //合法，编译器会将代码修改为 int temp = 10; const int & ref = temp;
    // ref = 20; // 加入const后为只读，不可修改

    showValue(a);
    return 0;
}