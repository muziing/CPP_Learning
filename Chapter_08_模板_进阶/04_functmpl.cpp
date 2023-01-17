/*
函数模板的定义
- 函数模板的定义形式：
  template<class 类型形参1, class 类型形参2, ...>
  返回值类型 函数模板名(调用形参1, 调用形参2, ...)
  {
    ......
  }
- 可以使用任何标识符作为类型形参的名称，出于习惯一般使用"T"，
  "T" 表示调用者在使用这个函数模板时指定的任意数据类型

函数模板的使用
- 使用函数模板必须对函数模板进行实例化
- 形式：函数模板名<类型实参1, 类型实参2, ...>(调用参数1, ...);

函数模板的分析
- 编译器并不是把函数模板编译成一个可以处理任何数据类型的单一实体
- 编译器在实例化函数模板时根据类型实参从函数模板中产生一个真正的函数实体
- 函数模板并不是一个函数实体，通过实例化才能产生真正的函数实体
- 函数模板可以视为只是编译器产生函数实体的依据
- 实例化：用具体数据类型替换函数模板类型形参的过程，这将产生一个函数模板的实例（函数实体）
- 只要使用函数模板，就会自动引发编译器的实例化过程，程序员不需要额外请求对函数模板的实例化

实例化函数模板的条件
- 原则上来说可以使用任何类型来实例化函数模板，不管其为基本类型还是类类型
- 但前提是该类型必须支持函数模板所要执行的操作

*/

#include <iostream>

using namespace std;

// 函数模板
template <class T>
T Max(T x, T y)
{
    return x > y ? x : y;
}

// 自定义的类
class Integer
{
public:
    Integer(int i) : m_i(i) {}
    bool operator>(Integer const &that) const
    {
        return m_i > that.m_i;
    }

private:
    int m_i;
};

int main()
{
    int nx = 10, ny = 20;
    cout << Max<int>(nx, ny) << endl;
    double dx = 12.3, dy = 45.6;
    cout << Max<double>(dx, dy) << endl;
    string sx = "world", sy = "hello";
    cout << Max<string>(sx, sy) << endl;

    Integer ix = 100, iy = 200;
    Max<Integer>(ix, iy); // 当Integer类实现了>之后就可以使用了

    return 0;
}
