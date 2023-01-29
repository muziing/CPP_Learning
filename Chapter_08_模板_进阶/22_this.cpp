/*
常见问题：子模板访问基类模板

- 问题：在子类模板中访问基类模板的成员，编译器第一次编译时只在子类模板和
  全局域中搜索使用的标识符号，不会到基类模板中搜索
- 解决：在子类模板中可以通过使用作用域限定符或显示使用this指针
*/

#include <iostream>
using namespace std;

template <typename T>
class Base
{
public:
    int m_i;
    void foo()
    {
        cout << "Base<T>::foo()" << endl;
    }
};

template <typename T, typename D>
class Derived : public Base<T>
{
public:
    void bar()
    {
        Base<T>::m_i = 100;
        // Base<T>::foo();
        this->foo();
    }
};

int main()
{
    Derived<int, double> d;
    d.bar();
    return 0;
}