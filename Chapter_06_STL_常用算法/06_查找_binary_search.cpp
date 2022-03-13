#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// binary_search  二分查找法
/*
bool binary_search(iterator beg, tierator end, value);
  查找指定的元素，查到返回true，否则返回false
  注意：在无序序列中不可用
  beg 开始迭代器
  end 结束迭代器
  value 查找的元素

*/

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // v.push_back(2); // 如果是无序序列，则查找结果未必准确

    // 查找容器中是否有9
    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret)
    {
        cout << "找到了元素" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{
    test01();
    return 0;
}