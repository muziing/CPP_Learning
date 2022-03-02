#include <iostream>
#include <string>
using namespace std;

// string 子串获取

// 返回由pos开始的n个字符组成的字符串
// string substr(int pos = 0, int n = npos) const;

void test01()
{
    string str = "abcdefg";
    string subStr = str.substr(1, 3);

    cout << "subStr = " << subStr << endl;
}

// 实用操作
void test02()
{
    string email = "muzi2001@foxmial.com";
    // 从邮件地址中获取用户名信息
    int pos = email.find("@");
    string userName = email.substr(0, pos);
    cout << userName << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}