#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// merge
/*
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
  将两个有序容器元素合并，并存储到另一容器中，且仍然是有序序列
  注意：两个容器必须是有序的
  beg1 容器1开始迭代器
  end1 容器1结束迭代器
  beg2 容器2开始迭代器
  end2 容器2结束迭代器
  dest 目标容器开始迭代器

*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }

    // 目标容器
    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}