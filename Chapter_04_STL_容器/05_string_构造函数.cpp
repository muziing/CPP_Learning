#include <iostream>
#include <string>
using namespace std;

/*
string 与 char * 的区别：
 - char * 是一个指针
 - string 是一个类，类内部封装了char*，管理字符串，是一个char*类型的容器

string 特点：
 - 封装了查找（find）、拷贝（copy）、删除（delete）、替换（replace）、插入（insert）等成员方法
 - string管理char*所分配的内存，不用担心复制越界取值越界等

构造函数：
 - string();                  //创建一个空的字符串。例如 string str;
   string(const char* s);     // 使用字符串s初始化
 - string(const string& str); // 使用一个string对象初始化另一个string对象
 - string(int n, char c);    // 使用n个字符串c初始化
*/

void test01()
{
    string s1; //默认构造

    const char *str = "hello world";
    string s2(str);
    cout << "s2 = " << s2 << endl;

    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}

int main()
{
    test01();
    return 0;
}