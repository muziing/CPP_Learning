#include <iostream>
#include <string>
using namespace std;

// string字符存取

// - char& operator[] (int n);  // 通过[]方式取字符
// - char& at(int n);           // 通过at方法获取字符

void test01()
{
    string str = "hello";
    // cout << "str = " << str << endl;

    // 通过[]访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    // 通过at()访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 修改单个字符
    str[0] = 'x';    // xello
    str.at(1) = 'y'; // xyllo
    cout << "str = " << str << endl;
}

int main()
{
    test01();
    return 0;
}