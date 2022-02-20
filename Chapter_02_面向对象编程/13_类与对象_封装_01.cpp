#include <iostream>
using namespace std;

// 设计一个圆类，求圆的周长

// 圆周率
const double Pi = 3.14;

class Circle
{
    // 访问权限：公共权限
public:
    // 属性
    int m_r; // 半径

    // 行为
    // 获取圆的周长
    double calculate()
    {
        return 2 * Pi * m_r;
    }
};

int main()
{
    // 通过圆类 创建具体的圆（对象）
    // 实例化
    Circle c1;
    // 为圆对象的属性进行赋值
    c1.m_r = 10;

    cout << "圆的周长为 " << c1.calculate() << endl;
    return 0;
}