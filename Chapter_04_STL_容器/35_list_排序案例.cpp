#include <iostream>
#include <list>
using namespace std;

// list 排序案例
// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
// 排序规则：按照年龄进行升序，如果年龄相同则按身高进行降序

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};

void printPersonList(const list<Person> &lst)
{
    for (list<Person>::const_iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name
             << "  年龄：" << it->m_Age
             << "  身高：" << it->m_Height
             << endl;
    }
}

// 指定排序顺序
bool comparePerson(Person &p1, Person &p2)
{
    // 按年龄升序
    if (p1.m_Age == p2.m_Age)
    {
        // 年龄相同，按身高降序
        return p1.m_Height > p2.m_Height;
    }
    return p1.m_Age < p2.m_Age;
}

void test01()
{
    list<Person> L;

    Person p1("A", 35, 175);
    Person p2("B", 25, 178);
    Person p3("C", 40, 170);
    Person p4("D", 38, 180);
    Person p5("E", 35, 165);
    Person p6("F", 35, 170);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    printPersonList(L);

    cout << "------排序后------" << endl;

    L.sort(comparePerson);
    printPersonList(L);
}

int main()
{
    test01();
    return 0;
}