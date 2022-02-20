#include <iostream>
using namespace std;

int main()
{
    // const 修饰指针

    // 1. const 修饰指针 —— 常量指针
    // 2. const 修饰常量 —— 指针常量
    // 3. const 既修饰指针，又修饰常量

    int a = 10;
    int b = 10;

    // 常量指针
    // 指针的指向可以修改，但指针指向的值不能修改
    // const int *p = &a;

    //*p = 20; // 会报错
    // p = &b; // 可以改指向

    // 指针常量
    // 指针指向不能改，指针指向的值可以修改

    int *const p = &a;
    // *p = 20; // 可以改
    // p = &b; // 不能改指向

    // const int *const p = &a;
    // *p = 20; // 不可改
    // p = &b; // 不能改指向

    return 0;
}