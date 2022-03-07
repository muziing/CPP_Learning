#include <iostream>
#include <set>
using namespace std;

// set 与 multiset 区别
/*
 - set 不可以插入重复数据，multiset 可以
 - set 插入数据的同时会返回插入结果，表示是否插入成功
 - multiset 不会检测数据，因此可以插入重复数据
*/

void showResult(const pair<set<int>::iterator, bool> &ret)
{
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
}

void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    showResult(ret);
    showResult(s.insert(10));
}

void test02()
{
    multiset<int> ms;
    ms.insert(10); // 返回插入位置的迭代器
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}