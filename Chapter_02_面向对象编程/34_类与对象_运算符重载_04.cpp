#include <iostream>
using namespace std;

/*
C++ 编译器至少给一个类添加4个函数：
1.默认构造函数（无参，函数体为空）
2.默认析构函数（无参，函数体为空）
3.默认拷贝构造函数，对属性进行值拷贝
4.赋值运算符 opeartor= ，对属性进行值拷贝
*/

// 赋值运算符重载

class Person
{
public:
    int *m_Age;

    Person(int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    // 重载赋值运算符
    Person &operator=(Person &p)
    {
        // 编译器提供浅拷贝，类似 m_Age = p.m_Age;

        // 应该先判断是否有属性在堆区，如有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age);
        return *this;
    }
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1; // 赋值操作

    cout << *p1.m_Age << endl;
    cout << *p2.m_Age << endl;
    cout << *p3.m_Age << endl;
}

int main()
{
    test01();
    return 0;
}