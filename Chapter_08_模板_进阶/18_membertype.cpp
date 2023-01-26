/*
模板技巧

- 模板型成员类型
  类模板中嵌套的类模板
*/

#include <iostream>

using namespace std;

template <class X>
class A
{
public:
    template <class Y>
    class B
    {
    public:
        template <class Z>
        class C;
    };
};

template <class X>
template <class Y>
template <class Z>
class A<X>::B<Y>::C
{
public:
    template <class T>
    void foo()
    {
        cout << "foo()" << endl;
    }
};

int main()
{
    A<int>::B<double>::C<float> c;
    c.foo<string>();
    return 0;
}
