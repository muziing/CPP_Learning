#include <iostream>
using namespace std;

// 成员函数做友元

class Building;
class GoodFriend
{
public:
    GoodFriend();

    void visit();  // 让visit函数可以访问Building中私有成员
    void visit2(); // 让visit2函数不可以访问Building中私有成员

    Building *building;
};

class Building
{
    // GoodFriend类下的visit成员函数为本类的friend，可以访问私有成员
    friend void GoodFriend::visit();

public:
    Building();
    string m_SittingRoom;

private:
    string m_BedRoom;
};

// 类外实现成员函数

Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodFriend::GoodFriend()
{
    building = new Building;
}

void GoodFriend::visit()
{
    cout << "visit函数正在访问" << building->m_SittingRoom << endl;
    cout << "visit函数正在访问" << building->m_BedRoom << endl;
}

void GoodFriend::visit2()
{
    cout << "visit2函数正在访问" << building->m_SittingRoom << endl;
    // cout << "visit2函数正在访问" << building->m_BedRoom << endl;
}

void test01()
{
    GoodFriend gf;
    gf.visit();
    gf.visit2();
}

int main()
{
    test01();
    return 0;
}