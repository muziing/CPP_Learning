#include <iostream>
using namespace std;

// this指针是隐含每一个非静态成员函数内的一种指针
// this指针不需要定义，直接使用即可

// this指针的用途

// - 当形参和成员变量同名时，可用this指针来区分
// - 在类的非静态成员函数中返回对象本身，可使用 return *this

class Person
{
public:
    int age;
    Person(int age)
    {
        // this指针指向被调用的成员函数所属的对象
        this->age = age;
    }

    Person& PersonAddAge(Person &p)
    {
        this->age += p.age;
        return *this;
    }
};

// 1、解决名称冲突
void test01()
{
    Person p1(18);
    cout << p1.age << endl;
}

// 2、返回对象本身用*this
void test02()
{
    Person p1(10);
    Person p2(10);

    // 链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

    cout << p2.age << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}