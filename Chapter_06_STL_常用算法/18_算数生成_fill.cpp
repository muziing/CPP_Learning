#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

// fill
/*
fill(iterator beg, iterator end, value);
  向容器中填充元素
  beg 开始迭代器
  end 结束迭代器
  value 填充的值
*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}