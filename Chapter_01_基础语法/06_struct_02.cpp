#include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

int main()
{
    // 结构体数组
    // 作用：将自定义的结构体放入到数组中方便维护
    // 语法： struct 结构体名 数组名[元素个数] = { {}, {}, ... {}}

    struct student stuArr[3] =
        {
            {"张三", 18, 60},
            {"李四", 19, 90},
            {"王五", 19, 61}};

    stuArr[2].name = "赵六";

    for (int i = 0; i < 3; i++)
    {

        cout << stuArr[i].name << endl;
        cout << stuArr[i].age << endl;
        cout << stuArr[i].score << endl;
    }

    // 结构体指针
    // 作用：通过指针访问结构体中的成员
    // 可以利用操作符 -> 通过结构体指针访问结构体属性

    struct student stu = {"muzing", 18, 100};
    // 通过指针指向结构体变量
    struct student *p = &stu;
    // 通过指针访问结构体变量中的数据
    cout << p->name << endl;
    return 0;
}
