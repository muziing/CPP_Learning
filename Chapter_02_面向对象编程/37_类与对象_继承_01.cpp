#include <iostream>
using namespace std;

// 继承好处：减少重复代码
// 语法：  class 子类 : 继承方式 父类

// 继承方式：
// - 公共继承
// - 保护继承
// - 私有继承

// 公共继承
class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Child1 : public Base1
{
public:
    void func()
    {
        m_A = 10; // 父类中的公共权限成员到子类中依然是公共权限
        m_B = 10; // 父类中的保护权限成员到子类中依然是保护权限
        // m_C = 10; // 父类中的私有权限成员子类访问不到
    }
};

void test01()
{
    Child1 c1;
    c1.m_A = 100;
    // c1.m_B = 100; // 保护权限，类外访问不到
}

// 保护继承
class Base2
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Child2 : protected Base2
{
public:
    void func()
    {
        m_A = 100; // 父类中公共成员，到子类中变为保护权限
        m_B = 100; // 父类中保护成员，到子类中变为保护权限
        // m_C = 100; // 父类中的私有权限成员子类访问不到
    }
};

void test02()
{
    Child2 c2;
    // c2.m_A = 1000; // 在 Child2 中 m_A 变为保护权限，类外访问不到
    // c2.m_B = 1000;
}

// 私有继承
class Base3
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Child3 : private Base3
{
public:
    void func()
    {
        m_A = 100; // 父类中公共成员，到子类中变为私有成员
        m_B = 100; // 父类中保护成员，到子类中变为私有成员
        // m_C = 100; // 父类中的私有权限成员子类访问不到
    }
};

void test03()
{
    Child3 c3;
    // c3.m_A = 1000; // 私有权限，类外访问不到
    // c3.m_B = 1000;
}

class CChild : public Child3
{
public:
    void func()
    {
        // m_A = 1000;
        // m_B = 1000;
    }
};

int main()
{

    return 0;
}