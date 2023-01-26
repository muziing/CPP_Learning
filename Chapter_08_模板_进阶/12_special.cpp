/*
类模板的全局特化

- 全类特化：特化一个类模板可以特化该类模板所有的成员函数，
  相当于重新写了一个针对某种特定数据类型的具体类
  声明形式：template<> class 类模板名<类型参数1, ...>{...};
- 成员特化：可以只针对某部分成员函数进行特化
  声明形式：template<> 返回值类型 类模板名<类型参数1, ...>::成员函数名(调用参数1, ...){...}
*/

#include <iostream>
#include <cstring>

using namespace std;

// 类模板
template <class T>
class CMath
{
public:
    CMath(T const &t1, T const &t2) : m_t1(t1), m_t2(t2) {}
    T add()
    {
        return m_t1 + m_t2;
    }

private:
    T m_t1;
    T m_t2;
};

/*
// 全类特化
template <>
class CMath<char *const>
{
public:
    CMath<char *const>(char *const &t1, char *const &t2) : m_t1(t1), m_t2(t2) {}
    char *const add()
    {
        return strcat(m_t1, m_t2);
    }

private:
    char *const m_t1;
    char *const m_t2;
};
*/

// 成员特化
template <>
char *const CMath<char *const>::add()
{
    return strcat(m_t1, m_t2);
}

int main()
{
    int nx = 10, ny = 20;
    CMath<int> m1(nx, ny);
    cout << m1.add() << endl;

    double dx = 12.3, dy = 45.6;
    CMath<double> m2(dx, dy);
    cout << m2.add() << endl;

    string sx = "hello", sy = "world";
    CMath<string> m3(sx, sy);
    cout << m3.add() << endl;

    char cx[256] = "hello", cy[256] = " world";
    CMath<char *const> m4(cx, cy);
    cout << m4.add() << endl;

    return 0;
}