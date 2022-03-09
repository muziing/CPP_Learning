#include <iostream>
#include <map>
using namespace std;

// map 排序

// 利用仿函数修改排序规则
class MyCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void test01()
{
    map<int, int, MyCompare> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "Key = " << (*it).first << " Value = " << it->second << endl;
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}