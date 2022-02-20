#include <iostream>
using namespace std;

// 虚析构和纯虚析构

// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 解决方式：将父类中的析构函数改为虚析构或纯虚析构

/*
虚析构和纯虚析构共性：
- 可以解决父类指针释放子类对象
- 都需要有具体的函数实现

虚析构和纯虚析构区别：
- 如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：
virtual ~类名(){}

纯虚析构语法：
virtual ~类名() = 0;
类名::~类名(){}
*/

class Animal
{
public:
    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }

    // 利用虚析构可以解决父类指针释放子类对象时不彻底的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal析构函数调用" << endl;
    // }

    // 纯虚析构 需要声明也需要实现
    // 有纯虚析构后，该类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;

    // 纯虚函数 只需声明
    virtual void speak() = 0;
};

Animal::~Animal()
{
    cout << "Animal纯虚析构函数调用" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        m_Name = new string(name);
    }

    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    virtual void speak()
    {
        cout << *m_Name << "猫在说话" << endl;
    }
    string *m_Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时不会调用子类中析构函数，
    // 导致如果子类有堆区属性，则出现内存泄露
    delete animal;
}

int main()
{
    test01();
    return 0;
}