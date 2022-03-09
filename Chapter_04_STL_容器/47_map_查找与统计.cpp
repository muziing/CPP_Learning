#include <iostream>
#include <map>
using namespace std;

// map 查找与统计
// find(key);    // 查找key是否存在，存在则返回该键的元素的迭代器；若不存在，则返回set.end()
// count(key);   // 统计key的元素个数，对于map，结果为0或1；multimap的结果可以大于1

void test01()
{
    // 查找
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(3, 40)); // map不允许插入key相同的元素，插入失败

    map<int, int>::iterator pos = m.find(3);
    // map<int, int>::iterator pos = m.find(4);

    if (pos != m.end())
    {
        cout << "查到了元素：" << (*pos).first << ": " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }

    // 统计
    int num = m.count(3);
    cout << "num = " << num << endl;
}

int main()
{
    test01();
    return 0;
}