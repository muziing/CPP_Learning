#include <iostream>
#include <string>
using namespace std;

/*

 - string& operator= (const char* s);   // 将char* 类型字符串赋值给当前的字符串
 - string& operator= (const string &s); // 将字符串s赋给当前的字符串
 - string& operator= (char c);          // 将字符赋值给当前的字符串
 - string& assign(const char *s);        // 将字符串s赋值给当前的字符串
 - string& assign(const char *s, int n); // 将字符串s的前n个字符赋给当前的字符串
 - string& assign(const string &s);      // 将字符串s赋给当前字符串
 - string& assign(int n, char c);        // 用n个字符c给当前字符串赋值

*/

void test01()
{
    string str1;
    str1 = "Hello world!";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("Hello CPP!");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("Hello CPP! Something very very long.", 5);
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(10, 'm');
    cout << "str7 = " << str7 << endl;
}

int main()
{
    test01();
    return 0;
}