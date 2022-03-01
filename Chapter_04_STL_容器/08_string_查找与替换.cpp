#include <iostream>
#include <string>
using namespace std;

// string 的查找与替换

/*

 - int find(const string& str, int pos = 0) const;     // 查找str第一次出现的位置，从pos开始查找
 - int find(const char* s, int pos = 0) const;         // 查找s第一次出现的位置，从pos开始查找
 - int find(const char* s, int pos, int n) const;      // 查找s的前n个字符第一次出现的位置，从pos开始
 - int find(const char c, int pos = 0) const;          // 查找字符c第一次出现位置
 - int rfind(const string& str, int pos = npos) const; // 查找str最后一次位置，从pos开始查找
 - int rfind(const char* s, int pos = npos) const;     // 查找s最后一次出现位置，从pos开始查找
 - int rfind(const char* s, int pos, int n) const;     // 查找s的前n个字符最后一次出现位置，从pos开始查找
 - int rfind(const char c, int pos = 0) const;         // 查找字符c最后一次出现位置
 - string& replace(int pos, int n, const string& str); // 替换从pos开始n个字符为字符串str
 - string& replace(int pos, int n, const char* s);     // 替换从pos开始的n个字符为字符串s

*/

// 查找
void test01()
{
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    // int pos = str1.find("df");  // 未找到，返回 -1
    if (pos == -1)
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "找到字符串, pos = " << pos << endl;
    }

    // rfind （从右向左查找）
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}

// 替换
void test02()
{
    string str1 = "abcdefg";
    // 从 1 起的 3 个字符替换为 11111
    str1.replace(1, 3, "11111");
    cout << str1 << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}