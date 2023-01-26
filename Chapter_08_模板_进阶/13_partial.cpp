/*
局部特化

- 全局特化是对类模板中的某个/全部成员函数做特化；局部特化是对类模板中的部分类型参数做特化
- 非必要，不做类模板的局部特化。因为特化版本过多容易引发编译器匹配歧义
*/

#include <iostream>

using namespace std;

template <class T, class D>
class CMath
{
public:
    static void foo()
    {
        cout << "1: CMath<T, D>::foo" << endl;
    }
};

// 局部特化
template <class T>
class CMath<T, short>
{
public:
    static void foo()
    {
        cout << "2: CMath<T, short>::foo" << endl;
    }
};
// 局部特化
template <class T>
class CMath<T, T>
{
public:
    static void foo()
    {
        cout << "3: CMath<T, T>::foo" << endl;
    }
};
// 局部特化
template <class T, class D>
class CMath<T *, D *>
{
public:
    static void foo()
    {
        cout << "4: CMath<T*, D*>" << endl;
    }
};

int main()
{

    CMath<int, double>::foo(); // 1: CMath<T, D>::foo
    CMath<int, short>::foo();  // 2: CMath<T, short>::foo
    // CMath<short, short>::foo(); // 2、3匹配程度相同，匹配歧义，会报错
    CMath<int *, double *>::foo(); // 1: CMath<T, D>::foo
    // CMath<int *, int *>::foo(); // 匹配歧义

    return 0;
}