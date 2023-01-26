/*
类模板的递归实例化

- 可以使用任何类型来实例化类模板
- 由类模板实例化产生的类也可以用来实例化类模板自身
  这种做法称之为类模板的递归实例化
- 通过这种方法可以构建空间上具有递归特性的数据结构（例如多维数组）
*/

#include <iostream>

using namespace std;

template <class T>
class Array
{
public:
    T &operator[](size_t i)
    {
        return m_arr[i];
    }

private:
    T m_arr[10];
};

/*
int main()
{
    Array<int> a;
    for (int i = 0; i < 10; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}
*/

int main()
{
    Array<Array<int>> m;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            m[i][j] = i + j;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}