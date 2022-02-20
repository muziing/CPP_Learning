#include <iostream>
using namespace std;

// 构造函数调用规则

/*
创建一个类，C++编译器会给每个类都添加至少3个函数
默认构造（空实现）
析构函数（空实现）
拷贝构造（值拷贝）
*/

// - 如果用户定义有参构造函数，C++不再提供默认无参构造，但会提供默认拷贝构造
// - 如果用户定义拷贝构造函数，C++不会再提供其他构造函数

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }

    Person(int age)
    {
        cout << "Person的有参构造函数调用" << endl;
        m_Age = age;
    }

    Person(const Person &p)
    {
        m_Age = p.m_Age;
        cout << "Person的拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    int m_Age;
};

// void test01()
// {
//     Person p1;
//     p1.m_Age = 18;
//     Person p2(p1);
//     cout << p2.m_Age << endl;
// }

void test02()
{
    // Person p; // 报错：无默认构造函数
    Person p1(20);
    Person p2(p1);
    cout << p2.m_Age << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}