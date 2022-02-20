#include <iostream>
using namespace std;

// 在堆区开辟数据

int *func()
{
    // 利用new关键字 可以将数据开辟到堆区
    int *a = new int(10); // 用指针存储new返回的内存地址
    // 指针本质上也是局部变量，放在栈上 指针保存的数据放在堆区
    return a;
}

int main()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}