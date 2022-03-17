#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// set_union
/*
set_union(iterator beg1, iterator end1, iterator beg2, tierator end2, iterator dest);
  求两个集合的并集
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
    vTarget.resize(v1.size() + v2.size());

    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

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