#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// find
/*
查找指定元素，找到则返回指定元素的迭代器，找不到则返回结束迭代器end()

find(iterator beg, iterator end, value);
  beg 开始迭代器
  end 结束迭代器
  value 查找的元素
*/

// 查找内置数据类型
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    // vector<int>::iterator it = find(v.begin(), v.end(), 50);
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了 " << *it << endl;
    }
}

// 查找自定义数据类型

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    // 重载 == 底层 find 知道如何对比 Person 数据类型
    bool operator==(const Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

void test02()
{
    vector<Person> v;

    Person p1("a", 20);
    Person p2("b", 21);
    Person p3("c", 22);
    Person p4("d", 23);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pp("b", 21);

    vector<Person>::iterator it = find(v.begin(), v.end(), pp);

    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到元素, 姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}