#include <iostream>
#include <list>
using namespace std;

// list容器基本概念
/*

功能：将数据进行链式存储
链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

链表的组成：链表由一系列结点组成
结点的组成：存储数据元素的数据域、存储下一个结点地址的指针域

STL 中的链表是一个双向循环链表

由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

list的优点：
 - 采用动态存储分配，不会造成内存浪费和溢出
 - 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
list的缺点：
 - 链表灵活，但空间（需要存储指针域）和时间（遍历）额外消耗较大

list重要特性：插入操作和删除操作都不会造成原有list迭代器的失效，这与vector不同

*/

// list构造函数
/*

 - list<T> lst;             // list采用模板类实现，对象的默认构造形式
 - list(beg, end);          // 构造函数将 [beg, end) 区间中的元素拷贝给本身
 - list(n, elem);           // 构造函数将n个elem拷贝给本身
 - list(const list &lst);   // 拷贝构造函数

*/

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // 创建容器
    list<int> L1; // 默认构造

    // 添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // 遍历打印
    printList(L1);

    // 区间方式
    list<int> L2(L1.begin(), L1.end());
    printList(L2);

    // 拷贝构造
    list<int> L3(L2);
    printList(L3);

    // n个elem
    list<int> L4(10, 1000);
    printList(L4);
}

int main()
{
    test01();
    return 0;
}