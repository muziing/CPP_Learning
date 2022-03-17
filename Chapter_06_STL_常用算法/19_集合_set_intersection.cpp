#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// set_intersection
/*
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
  求两个集合的交集
  注意两个集合必须是有序序列
  dest 目标容器的开始迭代器
*/

void test01()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);     // 0~9
        v2.push_back(i + 5); // 5~ 14
    }

    vector<int> vTarget;
    // 对于交集运算，最极端情况为交集大小等于两容器中较小容器的大小
    vTarget.resize(min(v1.size(), v2.size()));

    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for (vector<int>::iterator it = vTarget.begin(); it != itEnd; it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    test01();
    return 0;
}