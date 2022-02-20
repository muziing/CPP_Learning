#include <iostream>
using namespace std;

// 构造函数的分类及调用

// 分类：
// 按照参数分类： 无参构造 与 有参构造
// 按照类型分类： 普通构造 与 拷贝构造

class Person
{
public:
    int age;

    // 无参构造（默认构造）
    Person()
    {
        cout << "Person的无参构造函数调用" << endl;
    }

    // 有参构造
    Person(int a)
    {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }

    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的人身上的所有属性，拷贝过来
        age = p.age;
        cout << "Person的拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }
};

// 调用
void test01()
{
    // 1、括号法
    // Person p1; //默认构造函数调用
    // Person p2(10); // 有参构造函数
    // Person p3(p2); // 拷贝构造函数

    // 注意事项：调用默认构造函数时，不要加()（避免和函数声明语法冲突）
    // cout << p2.age << endl;
    // cout << p3.age << endl;

    // 2、显式法
    // Person p1;
    Person p2 = Person(10); // 调用有参构造
    Person p3 = Person(p2); // 拷贝构造

    // Person(10); // 匿名对象 特点：当前执行结束后，系统会立即回收掉匿名对象
    // 注意事项：不要利用拷贝构造函数来初始化匿名对象

    // 3、隐式转换法
    Person p4 = 10; // 相当于 Person p4 = Person(10);
    Person p5 = p4; // 拷贝构造
}

int main()
{
    test01();
    return 0;
}