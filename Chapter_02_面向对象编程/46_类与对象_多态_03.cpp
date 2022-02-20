#include <iostream>
using namespace std;

// 纯虚函数与抽象类
// 纯虚函数写法： virtual 返回值类型 函数名 (参数列表) = 0;

// 当类中有了纯虚函数，该类也称为抽象类
// 抽象类特点：
// - 无法实例化对象
// - 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

class Base
{
public:
    // 纯虚函数
    virtual void func() = 0;
};

class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func函数调用" << endl;
    }
};

void test01()
{
    Base *base = new Son;
    base->func();
}

int main()
{
    test01();
    return 0;
}