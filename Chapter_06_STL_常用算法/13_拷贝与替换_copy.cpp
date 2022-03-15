#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// copy
/*
copy(iterator beg, iterator end,iterator dest);
  将容器内指定范围的元素拷贝到另一容器中
  beg 开始迭代器
  end 结束迭代器
  dest 目标起始迭代器

*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int> v2;
    v2.resize(v1.size());

    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}