#include <iostream>
#include <deque>
using namespace std;

// deque容器基本概念
/*
功能：
 - 双端数组，可以对头端进行插入删除操作

deque与vector区别：
 - vector 对头部的插入删除效率低，数据量越大，效率越低
 - deque对头部的插入删除速度快于vector
 - vector访问元素时速度更快

deque内部工作原理：
  内部有中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
  中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

deque容器的迭代器支持随机访问
*/

// deque构造函数
/*
 - deque<T> deqT;            // 默认构造形式
 - deque(beg, end);          // 构造函数将 [beg, end) 区间中的元素拷贝给本身
 - deque(n, elem);           // 构造函数将 n 个 elem 拷贝给本身
 - deque(const deque &deq);  // 拷贝构造函数
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

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);
}

int main()
{
    test01();
    return 0;
}