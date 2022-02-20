#include <iostream>
using namespace std;

// 用const来防止误操作

struct student
{
    string name;
    int age;
    int score;
};

// 将函数中的形参改为指针，可减小内存开销（不会复制一份整个结构体）
void printStudent(const student *stu) // 加const防止函数体中的误操作
{
    //stu->age = 100; // 操作失败，因为加了const修饰
    cout << stu->name << stu->age << stu->score << endl;
}

int main()
{
    student stu = {"张三", 18, 100};
    printStudent(&stu);
    return 0;
}