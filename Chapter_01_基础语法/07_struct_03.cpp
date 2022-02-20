#include <iostream>
using namespace std;

// 结构体嵌套结构体
struct student
{
    string name;
    int age;
    int score;
};

struct teacher
{
    int id;
    string name;
    struct student stu; // 子结构体，学生
};

// 结构体做函数参数

// 值传递
void printStudent1(student stu)
{
    stu.age = 21;
    cout << "printStudent1" << stu.name << stu.age << stu.score << endl;
}

// 地址传递
void printStudent2(struct student *p)
{
    p->age = 25;
    cout << "printStudent1" << p->name << endl;
}

int main()
{
    // 结构体嵌套
    teacher t;
    t.id = 10086;
    t.name = "老王";
    t.stu.name = "张三";
    t.stu.age = 20;
    t.stu.score = 60;

    // cout << t.name << endl;
    // cout << t.stu.name << endl;

    // 结构体做函数参数
    struct student s;
    s.name = "李四";
    s.age = 20;
    s.score = 70;

    printStudent1(s);
    cout << s.age << endl; // 仍为20,修改形参不影响实参

    printStudent2(&s);
    cout << s.age << endl; // 已改为25

    return 0;
}