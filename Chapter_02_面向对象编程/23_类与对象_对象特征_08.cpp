#include <iostream>
using namespace std;

// 静态成员

// 静态成员变量：
// - 所有对象共享同一份数据
// - 在编译阶段分配内存
// - 类内声明，类外初始化

// 静态成员函数
// - 所有对象共享同一个函数
// - 静态成员函数只能访问静态成员变量

class Person
{
public:
    // 静态成员变量
    static int m_A;

    // 静态成员函数
    static void func()
    {
        m_A = 10; // 静态成员函数可以访问静态成员变量
        // m_C = 20; // 静态成员函数不可以访问非静态成员变量
        cout << "static void func调用" << endl;
    }

    int m_C; // 非静态成员变量

private:
    //静态成员变量也是有访问权限的
    static int m_B;
    static void func2()
    {
        cout << "static void func2调用" << endl;
    }
};

int Person::m_A = 100;
int Person::m_B = 200;

void test01()
{
    Person p1;

    Person p2;
    p2.m_A = 200;
    cout << p1.m_A << endl;
}

void test02()
{
    // 静态成员变量不属于某个对象上，所有对象都共享同一份数据
    // 因此静态成员变量有两种访问方式

    // 1、通过对象进行访问
    Person p;
    cout << p.m_A << endl;

    // 2、通过类名进行访问
    cout << Person::m_A << endl;
    // cout << Person::m_B << endl; // 类外访问不到私有静态成员变量
}

// 测试静态成员函数
void test03()
{
    // 1、通过对象访问
    Person p;
    p.func();

    // 2、通过类名访问
    Person::func();
    // Person::func2(); // 类外访问不到私有静态成员函数
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}