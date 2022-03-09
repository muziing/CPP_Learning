#include <iostream>
#include <map>
using namespace std;

// map 大小与交换
/*

 - size();    // 返回容器中元素的数目
 - empty();   // 判断容器是否为空
 - swap(st);  // 交换两个容器

*/

void printMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "Key = " << (*it).first << " Value = " << it->second << endl;
    }
    cout << endl;
}

// 大小
void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(1, 10));

    if (m.empty())
    {
        cout << "m为空" << endl;
    }
    else
    {
        cout << "m非空" << endl;
        cout << "m的大小为 " << m.size() << endl;
    }
}

// 交换
void test02()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(1, 10));

    map<int, int> m2;
    m2.insert(pair<int, int>(2, 200));
    m2.insert(pair<int, int>(4, 400));
    m2.insert(pair<int, int>(3, 300));
    m2.insert(pair<int, int>(1, 100));

    cout << "交换前：" << endl;
    printMap(m1);
    printMap(m2);

    m1.swap(m2);
    cout << "交换后：" << endl;
    printMap(m1);
    printMap(m2);
}

int main()
{
    // test01();
    test02();
    return 0;
}