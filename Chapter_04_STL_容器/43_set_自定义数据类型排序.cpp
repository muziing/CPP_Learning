#include <iostream>
#include <set>
using namespace std;

// set 自定义数据类型排序

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class comparePerson
{
public:
    bool operator()(const Person &p1, const Person p2) const
    {
        return p1.m_Age > p2.m_Age;
    }
};

void test01()
{
    // 自定义数据类型都按指定规则排序
    set<Person, comparePerson> s;

    // 创建Person对象
    Person p1("A", 24);
    Person p2("B", 28);
    Person p3("C", 25);
    Person p4("D", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << it->m_Name
             << "  年龄：" << it->m_Age
             << endl;
    }
}

int main()
{
    test01();
    return 0;
}