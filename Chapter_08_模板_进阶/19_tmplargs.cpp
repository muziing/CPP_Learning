/*
模板技巧

- 模板型模板参数
  类模板的模板形参也可以是类模板，可以有缺省值
*/

#include <iostream>

using namespace std;

template <class T>
class Array
{
public:
    T &operator[](size_t i)
    {
        return m_arr[i];
    }

private:
    T m_arr[10];
};

// 求和器
template <class D, template <class M> class C>
class Sum
{
public:
    Sum(C<D> &s) : m_s(s) {}
    D add()
    {
        // 求和
        D d = 0;
        for (int i = 0; i < 10; i++)
        {
            d += m_s[i];
        }
        return d;
    }

private:
    C<D> m_s; // 模板型成员变量
};

int main()
{
    Array<int> a;
    for (int i = 0; i < 10; i++)
    {
        a[i] = i + 1;
    }
    Sum<int, Array> s(a);
    cout << s.add() << endl;

    return 0;
}