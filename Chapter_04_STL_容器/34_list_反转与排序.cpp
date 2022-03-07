#include <iostream>
#include <list>
using namespace std;

// list 反转与排序
// reverse();  // 反转链表
// sort();     // 链表排序

void printList(const list<int> &lst)
{
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int v1, int v2)
{
    // 降序 就让第一个数大于第二个数
    return v1 > v2;
}

void test01()
{
    // 反转
    list<int> L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(30);
    L1.push_back(40);
    cout << "反转前：" << endl;
    printList(L1);

    L1.reverse();
    cout << "反转后：" << endl;
    printList(L1);

    // 排序
    L1.sort();
    cout << "排序后：" << endl;
    printList(L1);
    // 所有不支持随机访问迭代器的容器不能用标准sort()算法
    // 降序排序
    L1.sort(myCompare); // 提供回调函数
    printList(L1);
}

int main()
{
    test01();
    return 0;
}