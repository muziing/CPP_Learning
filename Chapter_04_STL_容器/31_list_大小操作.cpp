#include <iostream>
#include <list>
using namespace std;

// list 大小操作

/*

 - size();             // 返回容器中元素的个数
 - empty();            // 判断容器是否为空
 - resize(num);        // 重新指定容器的长度为num；若容器变长则以默认值填充新位置；若容器变短则删除末尾超出长度的元素
 - resize(num, elem);  // 同上，变长时使用elem填充新位置

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
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    if (L1.empty())
    {
        cout << "L1 为空" << endl;
    }
    else
    {
        cout << "L1非空" << endl;
        cout << "L1 的元素个数为" << L1.size() << endl;
    }

    // 重新指定大小
    // L1.resize(10);
    L1.resize(10, 1);
    printList(L1);

    L1.resize(2);
    printList(L1);
}

int main()
{
    test01();
    return 0;
}