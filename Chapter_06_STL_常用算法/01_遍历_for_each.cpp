#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// STL 常用算法
/*
 - 算法主要由头文件 <algorithm> <functional> <numeric> 组成
 - <algorithm> 是所有STL头文件中最大的一个，包括比较、交换、查找、遍历、复制、修改等等
 - <numeric> 体积很小，只包括几个在序列上进行简单数学运算的模板函数
 - <functional> 定义了一些模板类，用以声明函数对象
*/

// for_each
/*
for_each(iterator beg, iterator end, _func);
  遍历算法，遍历容器元素
  beg 开始迭代器
  end 结束迭代器
  _func 函数或函数对象
*/

// 普通函数
void print01(int val)
{
    cout << val << endl;
}

// 仿函数
class print02
{
public:
    void operator()(int val)
    {
        cout << val << endl;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // for_each(v.begin(), v.end(), print01);
    for_each(v.begin(), v.end(), print02());
}

int main()
{
    test01();
    return 0;
}