#include <iostream>
using namespace std;

#define name "muzing"

int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

int main()
{

    // int arr[2][2] = {10, 20, 30, 40};

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //         cout << arr[i][j] << endl;
    // }

    // cout << arr << endl;

    // cout << add(2, 3) << endl;

    // int a = 10;
    // int *p = &a;

    // cout << &a << endl;
    // cout << p << endl;
    // cout << *p << endl;
    // cout << sizeof(p) << endl;

    // 空指针
    // int *p = NULL;
    // cout << p << endl;

    // 野指针
    int *p = (int *)0x1111;
    cout << *p << endl;  // 运行时会报错

    return 0;
}