#include <iostream>
#include <functional>
using namespace std;

// 内建函数对象
/*
概念：
  STL内建的一些函数对象

分类：
  - 算数仿函数
  - 关系仿函数
  - 逻辑仿函数

用法：
  - 这些仿函数产生的对象，用法和一般函数完全相同
  - 使用内建函数对象，需要引入头文件 <functional>
*/

// 算数仿函数
// 实现四则运算。其中negate是一元运算，其他都是二元运算
/*
  - template<class T> T plus<T>        // 加法仿函数
  - template<class T> T minus<T>       // 减法仿函数
  - template<class T> T multiplies<T>  // 乘法仿函数
  - template<class T> T divides<T>     // 除法仿函数
  - template<class T> T modulus<T>     // 取模仿函数
  - template<class T> T negate<T>      // 取反仿函数
*/

void test01()
{
    // 取反仿函数
    negate<int> n;
    cout << n(50) << endl;
}

void test02()
{
    plus<int> p;
    cout << p(10, 10) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}