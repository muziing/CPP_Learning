#include <iostream>
using namespace std;

// 初始化列表
// 语法： 构造函数():属性1(值1),属性2(值2) ... {函数体}

class Person
{
public:
    int m_A;
    int m_B;
    int m_C;

    // 传统初始化操作
    // Person(int a, int b, int c)
    // {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    // 初始化列表初始化属性
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c)
    {
    }
};

void test01()
{
    Person p(10, 20, 30);
    cout << p.m_A << p.m_B << p.m_C << endl;
}

int main()
{
    test01();
    return 0;
}