#include <iostream>
using namespace std;

// 类对象作为类成员

class Phone
{
public:
    Phone(string pName)
    {
        cout << "Phone的构造函数调用" << endl;
        m_PName = pName;
    }
    string m_PName;
    ~Phone()
    {
        cout << "Phone的析构函数调用" << endl;
    }
};

class Person
{
public:
    string m_Name;
    Phone m_Phone;
    Person(string name, string pName) : m_Name(name), m_Phone(pName)
    {
        cout << "Person的构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};

void test01()
{
    Person p("张三", "HUAWEI");
    cout << p.m_Name << "拿着" << p.m_Phone.m_PName << endl;
}

int main()
{
    test01();
    return 0;
}