#include <iostream>
using namespace std;

// new的基本语法

int *func()
{
    // 在堆区创建整形数据
    // new返回的是该数据类型的指针
    int *p = new int(10);
    return p;
}

// 在堆区开辟数组

void test02()
{
    // 在堆区创建长度为10的整形数据的数组
    int *arr = new int[10]; // 此处的10代表数组中有10个元素
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i; // 为元素赋值
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    delete[] arr; // 释放数组时需要加[]
}

int main()
{
    int *p = func();
    cout << *p << endl;
    // 堆区的数据由程序员开辟，程序员释放
    delete p;           // 释放
    cout << *p << endl; // 会报错（读写权限冲突异常）或读出其他数（乱码）

    test02();

    return 0;
}