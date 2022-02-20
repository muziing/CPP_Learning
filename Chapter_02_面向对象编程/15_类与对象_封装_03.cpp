#include <iostream>
using namespace std;

// 成员属性设置为私有
// 1、可以自己控制读写权限
// 2、对于写可以检测数据的有消息

class Person
{
public:
    // 设置姓名
    void setName(string name)
    {
        m_Name = name;
    }
    // 获取姓名
    string getName()
    {
        return m_Name;
    }
    // 获取年龄
    int getAge()
    {
        m_Age = 0;
        return m_Age;
    }
    // 设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 150) // 限制年龄范围
        {
            m_Age = 0;
            return;
        }
        m_Age = age;
    }

    void setLover(string lover)
    {
        m_Lover = lover;
    }

private:
    string m_Name;  // 姓名 可读可写
    int m_Age;      // 年龄 可读，写有限制
    string m_Lover; //情人 只写
};

int main()
{
    Person p;
    p.setName("张三");
    cout << p.getName() << endl;
    cout << p.getAge() << endl;
    return 0;
}