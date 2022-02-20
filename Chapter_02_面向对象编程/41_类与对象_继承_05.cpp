#include <iostream>
using namespace std;

// 继承 - 同名静态成员处理方式
// 访问子类同名成员 直接访问即可
// 访问父类同名成员 需要加作用域

class Base
{
public:
    static int m_A;

    static void func()
    {
        cout << "Base - func() 调用" << endl;
    }
};

int Base::m_A = 100;

class Son : public Base
{
public:
    static int m_A;

    static void func()
    {
        cout << "Son - func() 调用" << endl;
    }
};

int Son::m_A = 200;

// 同名静态成员属性处理方式
void test01()
{
    // 1、通过对象访问
    Son s;
    cout << "Son m_A = " << s.m_A << endl;
    // 如果通过子类对象访问到父类中同名成员，需要加作用域
    cout << "Base m_A = " << s.Base::m_A << endl;

    // 2、通过类名访问
    cout << "Son m_A " << Son::m_A << endl;
    // 第一个 :: 代表通过类名方式访问，第二个代表访问父类作用域下
    cout << "Base m_A " << Son::Base::m_A << endl;
}

// 同名静态成员函数处理
void test02()
{
    // 1、通过对象访问
    Son s;
    s.func();
    s.Base::func();
    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数

    // 2、通过类名访问
    Son::func();
    Son::Base::func();
}

int main()
{
    // test01();
    test02();
    return 0;
}
