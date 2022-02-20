#include <iostream>
using namespace std;

// 菱形继承问题：
// 两个派生类继承同一个基类，又有某个类同时继承这两个派生类

// 利用虚继承可以解决菱形继承问题：在继承之前加上关键字 virtual

class Animal // 虚基类
{
public:
    int m_Age;
};

class Sheep : virtual public Animal
{
};

class Camel : virtual public Animal
{
};

class SheepCamel : public Sheep, public Camel
{
};

void test01()
{
    SheepCamel sc;

    // sc.Sheep::m_Age = 10;
    // sc.Camel::m_Age = 8;
    sc.m_Age = 8;
    // 菱形继承时，两个父类有相同数据，需要加以作用域区分
    cout << "sc.Sheep::m_Age = " << sc.Sheep::m_Age << endl;
    cout << "sc.Camel::m_Age = " << sc.Camel::m_Age << endl;
    cout << sc.m_Age << endl;

    // m_Age数据存储一份即可，菱形继承导致数据有两份，造成资源浪费
}

int main()
{
    test01();
    return 0;
}