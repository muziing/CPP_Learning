#include <iostream>
using namespace std;

// 继承 - 构造和析构顺序
// 构造：先构造父类，再构造子类
// 析构：与构造顺序相反

class Base
{
public:
    Base()
    {
        cout << "Base 构造函数!" << endl;
    }
    ~Base()
    {
        cout << "Base 析构函数!" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son 构造函数!" << endl;
    }
    ~Son()
    {
        cout << "Son 析构函数!" << endl;
    }
};

void test01()
{
    // Base b;
    Son s;
}

int main()
{
    test01();
    return 0;
}