#include <iostream>
using namespace std;

// 继承中的对象模型

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C; // 私有成员只是被隐藏了，但还是会继承下去
};

// 公共继承
class Son : public Base
{
public:
    int m_D;
};

void test01()
{
    cout << "size of Son = " << sizeof(Son) << endl;
    // 父类中所有非静态成员属性都会被子类继承下去
}

int main()
{
    test01();
    return 0;
}