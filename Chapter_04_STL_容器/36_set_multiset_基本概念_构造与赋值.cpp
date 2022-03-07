#include <iostream>
#include <set>
using namespace std;

// set基本概念
/*

简介：
  所有元素都会在插入时自动排序
本质：
  set/mutiset 属于关联式容器，底层结构是用二叉树实现

set与 multiset 区别：
  - set 不允许容器中有重复的元素
  - multiset 允许容器中有重复的元素

*/

// set构造与赋值
/*

构造：
 - set<T> st;           // 默认构造函数
 - set(const set &st);  // 拷贝构造函数

赋值：
 - set& operator= (const set &st);  // 重载等号操作符

*/

void printSet(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    // 插入数据只有 insert 方式
    s1.insert(10);
    s1.insert(20);
    s1.insert(10);
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);

    // 遍历容器
    printSet(s1);
    // set容器特点：所有元素插入时自动排序，不允许插入重复值

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
}

int main()
{
    test01();
    return 0;
}