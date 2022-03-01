#include <iostream>
#include <string>
using namespace std;

// 字符串比较
/*

字符串比较是按字符的ASCII码进行对比

 - = 返回 0
 - > 返回 1
 - < 返回 -1

 - int compare(const string &s) const;   // 与字符串s比较
 - int compare(const char *s) const;     // 与字符串s比较
*/

void test01()
{
    // string str1 = "hello";
    string str1 = "xello";
    // string str2 = "hello";
    string str2 = "zello";

    if (str1.compare(str2) == 0)
    {
        cout << "str1 等于 str2" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1 大于 str2" << endl;
    }
    else if (str1.compare(str2) < 0)
    {
        cout << "str1 小于 str2" << endl;
    }
}

int main()
{
    test01();
    return 0;
}