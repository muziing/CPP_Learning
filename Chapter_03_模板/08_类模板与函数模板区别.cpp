#include <iostream>
using namespace std;

// 类模板与函数模板区别：
// 1.类模板没有自动类型推导的使用方式
// 2.类模板在模板参数列表中可以有默认参数

template <class NameType, class AgeType = int> // 可以有默认参数
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name
             << "\tage: " << this->m_Age
             << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

// 1.类模板没有自动类型推导的使用方式（？）
void test01()
{
    // Person p("Tom", 20);

    // 因为已经有了默认参数，AgeType可以不显式指定数据类型
    Person<string> p("Tom", 20);

    p.showPerson();
}

int main()
{
    test01();
    return 0;
}