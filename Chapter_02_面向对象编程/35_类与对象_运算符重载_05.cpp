#include <iostream>
using namespace std;

// 关系运算符重载：可以让两个自定义类型对象进行比较操作

class Person
{
public:
    string m_Name;
    int m_Age;

    Person(string name, int age) : m_Name(name), m_Age(age)
    {
    }

    // 重载==号
    bool operator==(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
};

void test01()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);

    if (p1 == p2)
    {
        cout << "p1 与 p2 相等" << endl;
    }
    else
    {
        cout << "p1 与 p2 不相等" << endl;
    }
}

int main()
{
    test01();
    return 0;
}