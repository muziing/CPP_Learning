#include <iostream>
using namespace std;

// 继承 - 同名成员处理方式
// 访问子类同名成员 直接访问即可
// 访问父类同名成员 需要加作用域

class Base
{
public:
    int m_A;

    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base - func() 调用" << endl;
    }

    void func(int a)
    {
        cout << "Base - func(int a) 调用" << endl;
    }
};

class Son : public Base
{
public:
    int m_A;

    Son()
    {
        m_A = 200;
    }

    void func()
    {
        cout << "Son - func() 调用" << endl;
    }
};

// 同名成员属性处理方式
void test01()
{
    Son s;
    cout << "Son m_A = " << s.m_A << endl;
    // 如果通过子类对象访问到父类中同名成员，需要加作用域
    cout << "Base m_A = " << s.Base::m_A << endl;
}

// 同名成员函数处理
void test02()
{
    Son s;
    s.func();
    s.Base::func();
    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    // s.func(100);
    s.Base::func(100);
}

int main()
{
    // test01();
    test02();
    return 0;
}