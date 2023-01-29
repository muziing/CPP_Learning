/*
常见错误：嵌套依赖

- 问题：由于模板要经过两次编译，在第一次编译模板的代码时，类型形参的具体
类型尚不明确，编译器将把类型形参的嵌套类型理解为某个未知类型的静态成员变
量，因此编译器会报错
- 解决方法：在类型形参的前面添加一个 typename 标识符，意在告诉编译器
  其后是一个类模板的嵌套使用
*/

#include <iostream>

using namespace std;

class A
{
public:
    class B
    {
    public:
        void foo()
        {
            cout << "A::B::foo()" << endl;
        }
    };
};

template <typename T>
void Func()
{
    // T::B b; // 嵌套依赖，报错
    typename T::B b;
    b.foo();
}

int main()
{
    Func<A>();
    return 0;
}