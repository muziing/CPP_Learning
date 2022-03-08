#include <iostream>
#include <set>
using namespace std;

// set排序
// 利用仿函数，可以改变排序规则

class MyCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void printSet(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    s1.insert(20);
    s1.insert(40);
    s1.insert(10);
    s1.insert(50);
    s1.insert(30);
    printSet(s1);

    // 指定排序规则为降序
    set<int, MyCompare> s2; // 在创建时指定排序规则
    s2.insert(20);          // 插入时已经无法更改排序规则
    s2.insert(40);
    s2.insert(10);
    s2.insert(50);
    s2.insert(30);

    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}