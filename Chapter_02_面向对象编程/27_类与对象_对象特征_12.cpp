#include <iostream>
using namespace std;

// const修饰成员函数

// 常函数
// - 成员函数后加const后我们称其为常函数
// - 常函数内不可以修改成员属性
// - 成员属性声明时加关键字mutable后，在常函数中依然可以修改

class Person
{
public:
    Person()
    {
    }

    // this指针的本质是指针常量，指针的指向是不可以修改的
    // Person * const this; // this 指针相当于本行
    // const Person * const this; // 在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
    void showPerson() const
    {
        // this->m_A = 100;
        this->m_B = 100;
        // this = NULL; // this指针不可以修改指针的指向
    }
    int m_A;
    mutable int m_B; // 特殊变量，即使在常函数中也可以修改这个值，加关键字 mutable

    void func()
    {
    }
};

void test01()
{
    Person p;
    p.showPerson();
}

// 常对象
// - 声明对象前加const称该对象为常对象
// - 常对象只能调用常函数

void test02()
{
    const Person p; // 在对象前加const，变为常对象
    // p.m_A = 100; // 报错，不允许修改
    p.m_B = 100; // m_B 特殊，在常对象下也可以修改

    // 常对象只能调用常函数
    p.showPerson();
    // p.func(); // 不能调用普通成员函数，以防普通成员函数修改属性
}

int main()
{
    // test01();
    test02();
    return 0;
}