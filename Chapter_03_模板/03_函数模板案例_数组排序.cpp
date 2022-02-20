#include <iostream>
using namespace std;

// 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
// 排序规则：降序，算法：选择排序
// 分别利用char数组和int数组进行测试

// 交换的函数模板
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 排序函数模板
template <typename T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            mySwap(arr[max], arr[i]);
        }
    }
}

// 打印数组模板
template <typename T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "";
    }
    cout << endl;
}

void test01()
{
    // 测试char数组
    char charArr[] = "badfec";
    int ArrLen = sizeof(charArr) / sizeof(char);
    mySort(charArr, ArrLen);
    printArray(charArr, ArrLen);
}

void test02()
{
    // 测试int数组
    int intArr[] = {5, 7, 3, 0, 4, 2, 9, 1, 8, 6};
    int ArrLen = sizeof(intArr) / sizeof(int);
    mySort(intArr, ArrLen);
    printArray(intArr, ArrLen);
}

int main()
{
    test01();
    test02();
    return 0;
}