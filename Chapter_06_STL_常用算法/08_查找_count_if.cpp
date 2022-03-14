#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// count_if
/*
按条件统计元素个数

count_if(iterator beg, iterator end, _Pred);
  按条件统计元素出现次数
  beg 开始迭代器
  end 结束迭代器
  _Pred 谓词

*/

// 1、内置数据类型

class Greater20
{
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);

    int num = count_if(v.begin(), v.end(), Greater20());
    cout << "大于20元素个数为: " << num << endl;
}

// 2、自定义数据类型

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

class AgeGreater22
{
public:
    bool operator()(const Person &p) const
    {
        return p.m_Age > 22;
    }
};

void test02()
{
    vector<Person> v;
    Person p1("a", 20);
    Person p2("b", 21);
    Person p3("c", 22);
    Person p4("d", 23);
    Person p5("d", 24);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 统计大于22的人数
    int num = count_if(v.begin(), v.end(), AgeGreater22());
    cout << num << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}