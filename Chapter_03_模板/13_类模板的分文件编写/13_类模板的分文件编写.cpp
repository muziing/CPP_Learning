// 第一种解决方式：直接包含源文件
// #include "13_Person.cpp"

// 第二种解决方式（常用）：将.h和.cpp中的内容写在一起，将后缀名改为.hpp
#include "13_Person.hpp"

// 类模板分文件编写

void test01()
{
    Person<string, int> p("Jerry", 18);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}