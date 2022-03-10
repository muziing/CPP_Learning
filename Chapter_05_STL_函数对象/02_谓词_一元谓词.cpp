#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 谓词概念
/*
 - 返回bool类型的仿函数称为谓词
 - 如果operator() 接受一个参数，那么称为一元谓词
 - 如果operator() 接受两个参数，那么称为二元谓词
*/

class GreaterFive
{
public:
    // 一元谓词
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中有无大于5的数字
    // GreaterFive() 创建匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了大于5的数字, 为: " << *it << endl;
    }
}

int main()
{
    test01();
    return 0;
}