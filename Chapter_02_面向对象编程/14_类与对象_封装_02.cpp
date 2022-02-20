#include <iostream>
using namespace std;

// 封装 —— 访问权限
// 公共权限 public      成员 类内可以访问 类外可以访问
// 保护权限 protected   成员 类内可以访问 类外不可以访问 子类可访问
// 私有权限 private     成员 类内可以访问 类外不可以访问 子类不可访问

class Person
{
public:
    string m_Name;

protected:
    string m_Car;

private:
    int m_Password;

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "Nissan";
        m_Password = 123456;
    }
};

// class 与 struct 区别：默认访问权限不同，struct默认公共，class默认私有

int main()
{
    // 实例化
    Person p1;
    p1.m_Name = "李四";
    // p1.m_Car = "Ford"; // 保护权限，类外不能访问，无法修改
    // p1.m_Password = 123; // 私有权限，类外不能访问，无法修改
    return 0;
}