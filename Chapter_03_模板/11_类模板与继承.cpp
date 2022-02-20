#include <iostream>
using namespace std;

// 当类模板遇到继承情况时，需要注意以下几点：
// - 当子类继承的父类是一个类模板时，子类在声明的时候，要指出父类中T的类型
// - 如果不指定，编译器无法给子类分配内存
// - 如果想灵活指定出父类中T的类型，子类也需变为类模板

template <class T>
class Base
{
public:
    T m;
};

// class Child : public Base {}; // 错误，必须知道父类中T的类型，才能继承给子类
class Child : public Base<int>
{
};

// 如果想灵活指定父类中T类型，子类也需要变类模板
template <class T1, class T2>
class Child2 : public Base<T2>
{
public:
    Child2()
    {
        cout << "T1 的数据类型为 " << typeid(T1).name() << endl;
        cout << "T2 的数据类型为 " << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test01()
{
    Child c1;
}

void test02()
{
    Child2<int, char> c2;
}

int main()
{
    test01();
    test02();
    return 0;
}