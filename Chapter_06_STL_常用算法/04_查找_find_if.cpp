#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// find_if

/*
按条件查找元素

find_if(iterator beg, iterator end, _Pred);
  按条件查找元素，找到返回指定位置迭代器，找不到返回结束迭代器
  beg 开始迭代器
  end 结束迭代器
  _Pred 函数或谓词

*/

// 查找内置数据类型

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到大于5的数字为: " << *it << endl;
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

class Greater21
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age > 20;
    }
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

    // 找年龄大于21的人
    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater21());

    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到了，姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}