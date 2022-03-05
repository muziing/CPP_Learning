#include <iostream>
#include <deque>
using namespace std;

// deque 数据存取

/*
 - at(int idx);    // 返回索引idx所指的数据
 - operator[];     // 返回索引idx所指的数据
 - front();        // 返回容器中第一个数据元素
 - back();         // 返回容器中最后一个数据元素
*/

void test01()
{
    deque<int> d;
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    d.push_front(10);

    // 通过[]方式访问元素
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    // 通过at访问元素
    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "第一个元素为 " << d.front() << endl;
    cout << "最后一个元素为 " << d.back() << endl;
}

int main()
{
    test01();
    return 0;
}