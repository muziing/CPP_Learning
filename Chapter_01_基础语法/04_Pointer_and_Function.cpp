#include <iostream>
using namespace std;

// 实现两个数字进行交换

void swap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "swap01 a = " << a << endl; //交换了（形参）
    cout << "swap01 b = " << b << endl;
}

void swap02(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // 指针与函数

    int a = 10;
    int b = 20;

    //1、值传递
    swap01(a, b);
    // cout << "a = " << a << endl; //其实并没有交换（实参）
    // cout << "b = " << b << endl;

    // 2、地址传递
    // 如果是地址传递，可以修饰实参
    swap02(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //案例：封装一个函数，利用冒泡排序，实现对整型数组的升序排列

    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(arr) / sizeof(arr[0]); //数组长度
    bubbleSort(arr, len);
    cout << arr[0] << endl;

    return 0;
}