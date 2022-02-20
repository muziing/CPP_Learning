#include <iostream>
using namespace std;

// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型

// 1、创建语法： struct 类型名称 {成员列表};
// 2、通过学生类型创建具体学生

struct Student
{
    //成员列表
    string name;
    int age;
    int score;
} s3; //顺便创建结构体变量,不建议用

int main()
{
    // 2.1 struct Student s1
    // struct Student s1;
    // struct 关键字可以省略
    Student s1;
    // 给 s1 赋值，通过.访问结构体变量中的属性
    s1.name = "muzing";
    s1.age = 21;
    s1.score = 61;

    cout << s1.name << endl;

    // 2.2 struct Student s2 = {...} 创建时赋值
    struct Student s2 = {"张三", 19, 80};
    cout << s2.age << endl;

    // 2.3 在定义结构体时顺便创建结构体变量
    s3.name = "李四";
    cout << s3.name << endl;

    return 0;
}