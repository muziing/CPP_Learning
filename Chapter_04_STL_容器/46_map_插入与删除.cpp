#include <iostream>
#include <map>
using namespace std;

// map 插入与删除
/*

 - insert(elem);     // 在容器中插入元素
 - clear();          // 清除所有元素
 - erase();          // 删除pos迭代器所指的元素，返回下一个元素的迭代器
 - erase(beg, end)   // 删除区间[beg, end)的所有元素，返回下一个元素的迭代器
 - erase(key);       // 删除容器中值为key的元素

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
    map<int, int> m;

    // 插入
    // 第一种
    m.insert(pair<int, int>(1, 10));

    // 第二种
    m.insert(make_pair(2, 20));

    // 第三种
    m.insert(map<int, int>::value_type(3, 30));

    // 第四种
    m[4] = 40;            // 不建议
    cout << m[5] << endl; // 会创建Key为5，Value为默认值0的元素
    cout << m[4] << endl; // 可以返回 Key = 4 对应的 Value

    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3); // 按照Key删除
    printMap(m);

    // 清空
    // m.erase(m.begin(), m.end());
    m.clear();
}

int main()
{
    test01();
    return 0;
}