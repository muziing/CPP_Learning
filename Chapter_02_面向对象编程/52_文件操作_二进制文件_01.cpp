#include <iostream>
#include <fstream>
using namespace std;

// 二进制文件 - 写文件

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    ofstream ofs("person.txt", ios::out | ios::binary);
    // ofs.open("person.txt", ios::out | ios::binary);
    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));
    ofs.close();
}

int main()
{
    test01();
    return 0;
}