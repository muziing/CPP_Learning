#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// count
/*
count(iterator beg, iterator end, value);
  统计元素出现次数
  beg 开始迭代器
  end 结束迭代器
  value 统计的元素

*/

// 统计内置数据类型
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(10);
    v.push_back(40);

    int num = count(v.begin(), v.end(), 40);
    cout << "40 的元素个数为: " << num << endl;
}

// 统计自定义数据类型

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    // 重载 == 底层 find 知道如何对比 Person 数据类型
    bool operator==(const Person &p) const
    {
        if (this->m_Age == p.m_Age)
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
    Person p2("b", 22);
    Person p3("c", 22);
    Person p4("d", 23);
    Person p5("e", 23);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person pp("f", 22);

    int num = count(v.begin(), v.end(), pp);
    cout << num << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}