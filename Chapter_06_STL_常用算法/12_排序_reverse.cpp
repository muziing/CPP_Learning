#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// reverse
/*
reverse(iterator beg, iterator end);
  反转指定范围的元素
  beg 开始迭代器
  end 结束迭代器

*/

void myPrint(int val)
{
    cout << val << "\t";
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(60);

    cout << "反转前：" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    reverse(v.begin(), v.end());
    cout << "反转后：" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}