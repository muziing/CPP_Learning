#include <iostream>
using namespace std;

// pair 对组创建
// pair<type, type> p (value1, value2);
// pair<type, type> p = make_pair(value1, value2);

void test01()
{
    // 第一种方式创建
    pair<string, int> p("Tom", 20);
    cout << "姓名：" << p.first << " 年龄：" << p.second << endl;

    // 第二种方式
    pair<string, int> p2 = make_pair("Jerry", 18);
    cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}

int main()
{
    test01();
    return 0;
}