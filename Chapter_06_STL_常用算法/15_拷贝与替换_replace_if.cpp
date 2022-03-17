#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// replace_if
/*
replace_if(iterator beg, iterator end, _pred, newvalue);
  按条件替换元素，满足条件的替换成指定元素
  beg 开始迭代器
  end 结束迭代器
  _pred 谓词
  newvalue 替换的新元素
*/

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << endl;
    }
};

class MyGreater
{
public:
    bool operator()(int val)
    {
        return val >= 30;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);
    v.push_back(30);
    v.push_back(60);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), MyPrint());

    // 将大于等于30的替换为3000
    replace_if(v.begin(), v.end(), MyGreater(), 3000);
    cout << "替换后：" << endl;
    for_each(v.begin(), v.end(), MyPrint());
}

int main()
{
    test01();
    return 0;
}