#include <iostream>
using namespace std;

// 空指针访问成员函数

class Person
{
public:
    void showClassName()
    {
        cout << "This is Person class." << endl;
    }

    int m_Age;
    void showPersonAge()
    {
        // 报错原因是因为传入的指针是NULL
        if (this == NULL)
        {
            return;
        }
        cout << "age = " << m_Age << endl;
    }
};

void test01()
{
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}

int main()
{
    test01();
    return 0;
}