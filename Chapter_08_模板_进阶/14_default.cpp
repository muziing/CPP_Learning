/*
类型形参的缺省值

- 类模板的类型形参可以带缺省值
  实例化类模板时，如果提供了类型实参则用所提供的类型实参来实例化类模板，
  如果没有提供类型实参则用相应的类型形参的缺省类型来实例化类模板
- 如果类模板的某个类型形参带有缺省值，那么它后面的类型形参都必须带缺省值
*/

#include <iostream>
#include <typeinfo>

using namespace std;

template <class T = short, class D = int>
class CMath
{
public:
    void print()
    {
        cout << "m_t: " << typeid(m_t).name() << "\t"
             << "m_d: " << typeid(m_d).name() << endl;
    }

private:
    T m_t;
    D m_d;
};

int main()
{
    CMath<float, double> m;
    m.print();

    CMath<> m2;
    m2.print();

    return 0;
}