/*
类模板的声明

- 形式：template<class 类型形参1, ...> class 类模板名 {...};

- 如果在类模板外实现成员函数：
  temlpate <class 类型形参1, ...>
  返回值类型 类模板名 <类型形参1, ...>::函数名(调用形参1, ...){ 函数体实现; }

类模板的使用（上）
- 使用类模板必须对类模板进行实例化（产生真正的类）
  类模板本身并不代表一个确定的类型（即不能用于定义对象），只有通过类型实参
  实例化成真正的类后才具备类的语义（即可以定义对象）
*/

#include <iostream>

using namespace std;

// 类模板
template <class T>
class CMath
{
public:
    CMath(T const &t1, T const &t2) : m_t1(t1), m_t2(t2) {}
    T add();
    // T add()
    // {
    //     return m_t1 + m_t2;
    // }

private:
    T m_t1;
    T m_t2;
};

// 在类模板外部写成员函数实现：
template <class T>
T CMath<T>::add()
{
    return m_t1 + m_t2;
}

int main()
{
    int nx = 10, ny = 20;
    CMath<int> m1(nx, ny);
    cout << m1.add() << endl;

    double dx = 12.3, dy = 45.6;
    CMath<double> m2(dx, dy);
    cout << m2.add() << endl;

    string sx = "hello", sy = "world";
    CMath<string> m3(sx, sy);
    cout << m3.add() << endl;

    return 0;
}