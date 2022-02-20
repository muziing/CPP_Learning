#include <iostream>
using namespace std;

/*
类模板作用：
- 建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表

语法：
template <class T>
类

解释：
- temple 声明创建模板
- class 表明其后的符号是一种数据类型，可以用typename代替
- T 通用的数据类型，名称可以替换，通常为大写字母
*/

template <class NameType, class AgeType>
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
             << "age: " << this->m_Age
             << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    Person<string, int> p1("Tom", 10);
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}