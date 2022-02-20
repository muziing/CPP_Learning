#include <iostream>
using namespace std;

// 多态案例 - 计算器类

// 多态的优点：
// - 代码组织结构清晰
// - 可读性强
// - 利于前期和后期的扩展以及维护

// 传统写法实现计算器（不使用多态）
class Calculator
{
public:
    int m_Num1; // 操作数1
    int m_Num2; // 操作数2

    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        else
        {
            return -1;
        }
        // 如果想扩展新的功能，需要修改源码

        // 在真实开发中，提倡开闭原则：对扩展进行开放，对修改进行关闭
    }
};

// 利用多态实现计算器
// 实现计算器抽象类
class AbstractCalculator
{
public:
    int m_Num1;
    int m_Num2;

    virtual int getResult()
    {
        return 0;
    }
};

// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器类
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器类
class Mulalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test01()
{
    // 创建计算器对象
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
    cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
    cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}

void test02()
{
    // 多态使用条件：父类指针或引用指向子类对象

    // 加法运算
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;

    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;

    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;

    cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;

    abc = new Mulalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
    delete abc;
}

int main()
{
    // test01();
    test02();
    return 0;
}