#include <iostream>
using namespace std;

// 友元：让一个函数或类访问另一个类中的私有成员

// 全局函数做友元

class Building
{
    // goodFriend全局函数是Building的friend，可以访问Building中的私有成员
    friend void goodFriend(Building *building);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

    string m_SittingRoom;

private:
    string m_BedRoom;
};

// 全局函数
void goodFriend(Building *building)
{
    cout << building->m_SittingRoom << endl;
    cout << building->m_BedRoom << endl;
}

void test01()
{
    Building building;
    goodFriend(&building);
}

int main()
{
    test01();
    return 0;
}