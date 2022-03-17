#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// set_difference
/*
set_difference(iterator beg1, iterator end1, iterator beg2, tierator end2, iterator dest);
  求两个集合的差集
  注意两个集合必须是有序序列
  dest 目标容器开始迭代器
*/

void test01()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    vTarget.resize(max(v1.size(), v2.size()));

    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    cout << "v1 与 v2 差集为：" << endl;
    for (vector<int>::iterator it = vTarget.begin(); it != itEnd; it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    cout << "v2 与 v1 差集为：" << endl;
    for (vector<int>::iterator it = vTarget.begin(); it != itEnd; it++)
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