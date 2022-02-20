#include <iostream>
using namespace std;

// 多继承：一个类继承多个类
// 语法： class 子类名 : 继承方式 父类1, 继承方式 父类2 ...
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分
// 实际开发中不建议用多继承

class Base1
{
public:
    int m_A;

    Base1()
    {
        m_A = 100;
    }
};

class Base2
{
public:
    int m_A;

    Base2()
    {
        m_A = 200;
    }
};

// 子类 需要继承 Base1 和 Base2
class Son : public Base1, public Base2
{
public:
    int m_C;
    int m_D;

    Son()
    {
        m_C = 300;
        m_D = 400;
    }
};

void test01()
{
    Son s;
    cout << "size of Son = " << sizeof(s) << endl;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;
}

int main()
{
    test01();
    return 0;
}