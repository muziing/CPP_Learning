#include <iostream>
using namespace std;

int main()
{
    //利用指针访问数组中的元素
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *p = arr; //arr 即为数组首地址
    // cout << *p << endl;
    // p++; //让指针向后偏移
    // cout << *p << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << *p << endl;
        p++;
    }
    return 0;
}