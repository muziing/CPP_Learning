#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// transform: 搬运容器到另一个容器中
/*
transform(iterator beg1, iterator end1, tierator beg2, _func);
  beg1 源容器开始迭代器
  end1 源容器结束迭代器
  beg2 目标容器开始迭代器
  _func 函数或函数对象
*/

class Transform
{
public:
    int operator()(int v)
    {
        // return v;
        return v + 100; // 示例：可以在搬运元素时对元素进行一些运算
    }
};

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << endl;
    }
};

void test01()
{
    vector<int> v; // 源容器
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> vTarget;      // 目标容器
    vTarget.resize(v.size()); // 目标容器提前开辟空间

    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
}

int main()
{
    test01();
    return 0;
}