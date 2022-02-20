#include <iostream>
using namespace std;

// 多态
// - 静态多态：函数重载和运算符重载，复用函数名
// - 动态多态：派生类和虚函数实现运行时多态

// 静态多态与动态多态区别：
// 静态多态的函数地址早绑定 - 编译阶段确定函数地址
// 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal
{
public:
    // 重写：函数返回值、函数名、参数列表完全相同
    void speak()
    {
        cout << "猫在说话" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "狗在说话" << endl;
    }
};

// 地址早绑定 在编译阶段确定函数地址
// 如果想执行让猫说话，那么函数地址不能提前绑定，需要在运行阶段绑定（晚绑定）
void doSpeak(Animal &animal) // Animal & animal = cat;
{
    animal.speak();
}

// 动态多态满足条件
// 1、有继承关系
// 2、子类重写父类的虚函数（重写：函数返回值、函数名、参数列表完全相同）

// 动态多态使用：父类的引用/指针执行子类对象

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02()
{
    Animal animal;
    cout << sizeof(animal) << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}