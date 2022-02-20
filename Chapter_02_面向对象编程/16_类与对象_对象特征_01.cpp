#include <iostream>
using namespace std;

// 对象的初始化与清理
// 1、构造函数 进行初始化操作
// 2、析构函数 进行清理操作

class Person
{
public:
    // 构造函数
    // 没有返回值 不用写 void
    // 函数名与类名相同
    // 构造函数可以有参数，可以发生重载
    // 创建对象时，构造函数会自动调用，且只调用一次
    Person()
    {
        cout << "Person 构造函数的调用" << endl;
    }
    // 析构函数 进行清理的操作
    // 没有返回值 不写 void
    // 函数名和类名相同 在名称前加 ~
    // 析构函数无参数，因此不可以重载
    // 对象在销毁前会自动调用析构函数，且只调用一次
    ~Person()
    {
        cout << "Person 析构函数的调用" << endl;
    }
};

void test01()
{
    Person p; // 栈上的数据，test01执行完后会被释放
}

int main()
{
    test01();
    return 0;
}