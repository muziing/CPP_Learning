#include <iostream>
#include <map>
using namespace std;

// map/multimap 容器简介
/*

简介：
 - map 中所有元素都是 pair
 - pair 中第一个元素为 key（键值），起到索引作用；第二个元素为 value（实值）
 - 所有元素都会根据元素的键值自动排序

本质：
  map/multimap 属于关联式容器，底层结构用二叉树实现

优点：
  可以根据 key 快读找到 value 值

map 和 multimap 区别：
 - map 不允许容器中有重复 key 值元素
 - multimap 允许容器中有重复 key 值元素

*/

// map 构造与赋值
/*

构造：
 - map<T1, T2> mp;      // map 默认构造函数
 - map(const map &mp);  // 拷贝构造函数

赋值：
 - map& operator= (const map &mp);  // 重载等号操作符

*/

void printMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "Key = " << (*it).first << " Value = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    // 创建map容器
    map<int, int> m;

    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(1, 10));

    printMap(m);

    // 拷贝构造
    map<int, int> m2(m);
    printMap(m2);

    // 赋值
    map<int, int> m3;
    m3 = m2;
    printMap(m3);
}

int main()
{
    test01();
    return 0;
}