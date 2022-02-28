#include <iostream>
#include <string>
using namespace std;

/*

 - string& operator+= (const char* str);     // 重载 += 操作符
 - string& operator+= (const char c);        // 重载 += 操作符
 - string& operator+= (const string& str);   // 重载 += 操作符
 - string& append(const char *s);            // 将字符串 s 连接到当前字符串末尾
 - string& append(const char *s, int n);     // 将字符串 s 的前n个字符连接到当前字符串结尾
 - string& append(const string &s);          // 同 operator+= (const string& str);
 - string& append(const string &s, int pos, int n);  // 将字符串 s 中从pos开始的n个字符连接到字符串的结尾

*/

void test01()
{
    string str1 = "https://muzing";
    str1 += ".top";
    cout << "str1 = " << str1 << endl;

    str1 += '/';
    cout << "str1 = " << str1 << endl;

    string str2 = "about/";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "https://";
    str3.append("domm.");
    str3.append("muzing.top", 6);
    string str4 = ".top";
    str3.append(str4);
    str3.append(str2, 5, 1); // 从第5个字符开始截取，取长度为1的
    cout << "str3 = " << str3 << endl;
}

int main()
{
    test01();
    return 0;
}