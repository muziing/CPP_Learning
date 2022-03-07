#include <iostream>
#include <set>
using namespace std;

// set 查找与统计
// find(key);    // 查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end()
// count(key);   // 统计key的元素个数

void test01()
{
    set<int> s1;
    s1.insert(40);
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);

    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
    {
        cout << "找到元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }
}

void test02()
{
    set<int> s1;
    s1.insert(40);
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);
    s1.insert(30);
    s1.insert(30);

    // 统计30的个数
    int num = s1.count(30);
    // 对于set，统计结果只可能为0或1
    cout << "num = " << num << endl;
    num = s1.count(300);
    cout << "num = " << num << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}