#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// deque 排序

// sort(iterator beg, tierator end)  // 对beg和end区间内元素进行排序

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        // *it = 100; // 加 const 防止对传入的数据误修改
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d;
    d.push_back(20);
    d.push_back(40);
    d.push_back(30);
    d.push_front(10);
    d.push_front(100);
    d.push_front(50);

    // 50 100 10 20 40 30
    printDeque(d);

    // 排序
    sort(d.begin(), d.end()); // 默认升序
    // 10 20 30 40 50 100
    printDeque(d);
}

int main()
{
    test01();
    return 0;
}