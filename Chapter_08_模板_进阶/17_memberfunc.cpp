/*
模板技巧

- 模板型成员函数
  类模板的成员函数模板
*/

#include <iostream>

using namespace std;

template <class T>
class CMath
{
public:
    /*
    template <class D>
    void foo() // 成员 函数模板
    {
        cout << "CMath<T>::foo<D>()" << endl;
    }
    */
    template <class D>
    void foo();
};

template <class T>
template <class D>
void CMath<T>::foo()
{
    cout << "CMath<T>::foo<D>()" << endl;
}

int main()
{
    CMath<int> m;
    m.foo<double>();

    return 0;
}