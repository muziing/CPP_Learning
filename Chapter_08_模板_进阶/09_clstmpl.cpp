/*
类模板的使用（下）
- 类模板被实例化时类模板中的成员函数并没有被实例化，成员函数只有在被调用时
  才会被实例化（即产生真正成员函数）注意：成员虚函数除外
- 某些类型虽然并没有提供类模板所需要的全部功能，但照样可以实例化类模板，
  只要不调用那些未提供功能的成员函数即可
*/

#include <iostream>

using namespace std;

class Integer
{
public:
    Integer(int i) : m_i(i) {}

    Integer operator+(Integer const &that) const
    {
        return m_i + that.m_i;
    }

private:
    int m_i;
};

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

/* 当编译器第一次读到 CMath<int> 时，会将其实例化为如下内容：
class CMath<int>
{
public:
private:
    int m_t1;
    int m_t2;
};
只有成员变量，没有成员函数
后续调用了哪个模板中的成员函数，实例中才出现对应的成员函数
*/

int main()
{
    int nx = 10, ny = 20;
    CMath<int> m1(nx, ny);
    cout << m1.add() << endl;

    Integer ix = 100, iy = 200;
    CMath<Integer> m2(ix, iy);
    // Integer 类并不能实现类模板中的add()，但只要不调用就不会报错
    // m2.add(); // 一旦调用add()，则类实例中出现add()，报错
    m2.add(); // 修改Integer类，使其支持+运算符，即可使用了

    return 0;
}