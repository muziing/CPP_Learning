#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

// sort
/*
对容器内元素进行排序

sort(iterator beg, iterator end, _Pred);
  按值查找元素，找到返回指定位置迭代器，找不到返回结束位置迭代器
  beg 开始迭代器
  end 结束迭代器
  _Pred 谓词

*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);

    sort(v.begin(), v.end());
    // for_each(v.begin(), v.end(), myPrint);

    // 改变为降序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}