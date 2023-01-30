/*
类模板中的成员虚函数

- 类模板中的普通成员函数可以是虚函数
  即可以为类定义成员虚函数，和普通类的成员虚函数一样，类模板的成员虚函数
  也可以表现出多态性
- 类模板中的成员函数模板不可以是虚函数
  根据成员虚函数的多态机制，需要一个虚函数表（表中保存成员虚函数的入口地址），
  而这个表是编译器在实例化类模板时就产生，类的成员函数模板的实例化（即产生真
  正的函数实体）需要编译器处理完调用后才会完成，这时才出现成员虚函数的地址
- 总结：成员函数模板的延迟编译阻碍了虚函数表的静态构建
*/

#include <iostream>
using namespace std;

template <typename T>
class Base
{
public:
    virtual void foo()
    {
        cout << "Base<T>::foo()" << endl;
    }
};

template <typename T, typename D>
class Derived : public Base<T>
{
public:
    void foo()
    {
        cout << "Derived<T, D>::foo()" << endl;
    }

    // virtual template <typename M>
    // void bar()
    // {
    // }
};

int main()
{
    Derived<int, int> d;
    Base<int> *pBase = &d;
    pBase->foo();
    return 0;
}