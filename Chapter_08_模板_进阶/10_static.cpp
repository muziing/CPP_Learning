/*
类模板的静态成员

- 类模板中的静态成员即不是每个对象拥有一份
- 也不是类模板拥有一份
- 而应该是由类模板实例化出的每一个真正的类各有一份
- 且为该实例化类定义的所有对象共享
*/

#include <iostream>

using namespace std;

template <class T>
class A
{
public:
    static void print()
    {
        cout << "&m_i: " << &m_i << "\t"
             << "&m_t: " << &m_t << endl;
    }
    static int m_i;
    static T m_t;
};

template <class T>
int A<T>::m_i = 0;

template <class T>
T A<T>::m_t; // = ??

int main()
{
    A<int> x, y, z;
    x.print();
    y.print();
    z.print();
    A<int>::print();

    cout << "====================" << endl;

    A<double> m, n, t;
    m.print();
    n.print();
    t.print();
    A<double>::print();

    return 0;
}