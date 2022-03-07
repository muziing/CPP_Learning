#include <iostream>
#include <list>
using namespace std;

// list数据存取
// front();    // 返回第一个元素
// back();     // 返回最后一个元素

void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // L1[0];   不可以用[]或at访问list容器中的元素
    // list本质是列表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的

    cout << "L1.front() = " << L1.front() << endl;
    cout << "L1.back() = " << L1.back() << endl;

    // 验证迭代器是不支持随机访问的
    list<int>::iterator it = L1.begin();
    it++; // 可以
    // it += 1;  // 报错
    // it = it + 1; // 报错
    it--; //支持双向
}

int main()
{
    test01();
    return 0;
}