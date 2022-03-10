#include <iostream>
using namespace std;

// 函数对象概念
/*
概念：
 - 重载函数调用操作符的类，其对象成为函数对象
 - 函数对象使用重载的()时，行为类似函数调用，故也叫仿函数

本质：
  函数对象（仿函数）是一个类，不是一个函数
*/

// 函数对象的使用
/*
 - 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
 - 函数对象超出普通函数的概念，函数对象可以有自己的状态
 - 函数对象可以作为参数传递
*/

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

// 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

// 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }

    int count; // 内部自己状态
};

void test02()
{
    MyPrint myPrint;
    myPrint("Hello world.");
    myPrint("Hello world.");
    myPrint("Hello world.");
    cout << "myPrint调用次数为: " << myPrint.count << endl;
}

// 函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}

void test03()
{
    MyPrint myPrint;
    doPrint(myPrint, "Hello C++.");
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}