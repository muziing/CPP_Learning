#include <iostream>
#include <vector>
using namespace std;

// vector容器中存放自定义数据类型

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

void test01()
{
    vector<Person> v;
    Person p1("a", 20);
    Person p2("b", 21);
    Person p3("c", 22);
    Person p4("d", 23);
    Person p5("e", 23);

    // 向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名: " << (*it).m_Name
             << "\t年龄" << it->m_Age
             << endl;
    }
}

// 存放自定义数据类型 指针
void test02()
{
    vector<Person *> v;
    Person p1("a", 20);
    Person p2("b", 21);
    Person p3("c", 22);
    Person p4("d", 23);
    Person p5("e", 23);

    // 向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍历容器
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名: " << (*it)->m_Name
             << "\t年龄" << (*it)->m_Age
             << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}