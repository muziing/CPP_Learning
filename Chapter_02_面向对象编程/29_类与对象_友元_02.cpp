#include <iostream>
using namespace std;

// 类做友元

class Building;
class goodFriend
{
public:
    goodFriend();
    void visit(); //参观函数访问Building中的属性

    Building *building;
};

class Building
{
    // goodFriend类是Building类的friend，可以访问到私有内容
    friend class goodFriend;

public:
    Building();
    string m_SittingRoom;

private:
    string m_BedRoom;
};

// 类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

goodFriend::goodFriend()
{
    // 创建建筑物对象
    building = new Building;
}

void goodFriend::visit()
{
    cout << building->m_SittingRoom << endl;
    cout << building->m_BedRoom << endl;
}

void test01()
{
    goodFriend gf;
    gf.visit();
}

int main()
{
    test01();
    return 0;
}