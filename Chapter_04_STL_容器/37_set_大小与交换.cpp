#include <iostream>
#include <set>
using namespace std;

// set 大小与交换
/*
 - size();    // 返回容器中元素的数目
 - empty();   // 判断容器是否为空
 - swap(st);  // 交换两个集合容器
*/

void printSet(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    // 判断是否为空
    if (s1.empty())
    {
        cout << "s1 为空" << endl;
    }
    else
    {
        cout << "s1 不为空" << endl;
        cout << "s1 大小为 " << s1.size() << endl;
    }
}

// 交换
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);

    cout << "交换前：" << endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);
    cout << "交换后：" << endl;
    printSet(s1);
    printSet(s2);
}

int main()
{
    test01();
    test02();
    return 0;
}