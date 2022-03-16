#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// replace
/*
将容器内指定范围的旧元素改为新元素

replace(iterator beg, iterator end, oldvalue, newvalue);
  将区间内旧元素替换为新元素
  beg 开始迭代器
  end 结束迭代器
  oldvalue 旧元素
  newvalue 新元素
*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(20);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(20);
    v.push_back(40);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), myPrint);

    // 将所有20替换为2000
    replace(v.begin(), v.end(), 20, 2000);
    cout << "替换后：" << endl;
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}