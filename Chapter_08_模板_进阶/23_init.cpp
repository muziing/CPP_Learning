/*
常见问题：零值初始化

- 问题：基本数据类型不存在缺省构造函数，未被初始化的局部变量都具有一个不确定
  的值。类类型由于存在缺省构造函数，在未被初始化的情况下可以有一个确定的缺省
  初始化状态。基于以上两点，就会在模板实现中产生不一致的语法语义
- 解决：如果希望模板中所有类型参数的变量，无论是类类型还是基本类型都以缺省方
  式获得初始化，就必须对其进行显式的缺省构造 T()
*/

#include <iostream>
using namespace std;

class Integer
{
public:
    Integer() : m_i(0) {}

private:
    int m_i;
    friend ostream &operator<<(ostream &os, Integer const &that);
};

ostream &operator<<(ostream &os, Integer const &that)
{
    return os << that.m_i;
}

template <typename T>
void Func()
{
    // T t;    // 语义不一致，可能导致行为异常
    T t = T(); // 对于类取无参构造；对于基本类型取0值
    cout << "t=" << t << endl;
}

int main()
{
    Func<int>();
    Func<Integer>();
    return 0;
}