#include <iostream>
#include <deque>
using namespace std;

// deque 大小操作
/*
 - deque.empty();            // 判断容器是否为空
 - deque.size();             // 返回容器中元素的个数
 - deque.resize(num);        // 重新指定容器的长度为num；若容器变长则以默认值填充新位置；若容器变短则删除末尾超出长度的元素
 - deque.resize(num, elem);  // 同上，变长时使用elem填充新位置
*/

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
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    if (d1.empty())
    {
        cout << "d1 为空" << endl;
    }
    else
    {
        cout << "d1 不为空" << endl;
        cout << "d1 的大小为 " << d1.size() << endl;
        // deque 没有容量概念
    }

    // d1.resize(15);
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main()
{
    test01();
    return 0;
}