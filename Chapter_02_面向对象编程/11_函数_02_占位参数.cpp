#include <iostream>
using namespace std;

// 函数占位参数，占位参数也可以有默认参数
// 语法： 返回值类型 函数名 (数据类型) {函数体}

void func(int a, int = 10)
{
    cout << "This is func" << endl;
}

int main()
{

    func(10, 10); // 占位参数必须填补
    func(10);     // 占位参数可以有默认值

    return 0;
}