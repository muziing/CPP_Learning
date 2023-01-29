/*
常见错误：依赖模板参数访问成员函数模板

- 问题：利用未知类定义的对象来访问成员函数模板时，编译器在第一次编译时无法
  解析成员函数模板的类型参数列表的<>而报告编译错误
- 解决方法：在成员函数模板之前增加template关键字，意在告诉编译器其后是一个
  函数模板实例，编译器就可以正确理解<>了。
*/

#include <iostream>
using namespace std;

class A
{
public:
    template <typename T>
    void foo()
    {
        cout << "A::foo<T>()" << endl;
    }
};

template <typename D>
void Func()
{
    D d;
    // d.foo<int>(); // 依赖模板参数访问成员函数模板
    d.template foo<int>();
}

int main()
{
    Func<A>();
    return 0;
}