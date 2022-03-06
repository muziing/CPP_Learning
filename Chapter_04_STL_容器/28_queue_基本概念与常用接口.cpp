#include <iostream>
#include <queue>
using namespace std;

// queue 基本概念
/*
先进先出（First In First Out, FIFO）的数据结构，一个入口一个出口

允许从一端新增元素，从另一端移除元素
队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
进数据 --- 入队 push
出数据 --- 出队 pop
*/

// queue 常用接口
/*

构造函数
 - queue<T> que;             // queue采用模板类实现，queue对象的默认构造形式
 - queue(const queue &que);  // 拷贝构造函数

赋值操作
 - queue& operator= (const queue &que);  // 重载等号运算符

数据存取
 - push(elem);    // 往队尾添加元素
 - pop();         // 从队头移除第一个元素
 - back();        // 返回最后一个元素
 - front();       // 返回第一个元素

大小操作
 - empty();      // 判断堆栈是否为空
 - size();       // 返回栈的大小

*/

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void test01()
{
    // 创建队列
    queue<Person> q;

    // 准备数据
    Person p1("张三", 30);
    Person p2("李四", 32);
    Person p3("王五", 29);
    Person p4("赵六", 28);

    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << "队列大小为 " << q.size() << endl;

    // 队列不为空，则查看队头队尾，然后出队
    while (!q.empty())
    {
        cout << "队头元素：" << q.front().m_Name << " " << q.front().m_Age << endl;
        cout << "队尾元素：" << q.back().m_Name << " " << q.back().m_Age << endl;
        // 出队
        q.pop();
        cout << endl;
    }
    cout << "队列大小为 " << q.size() << endl;
}

int main()
{
    test01();
    return 0;
}