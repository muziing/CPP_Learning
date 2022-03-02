#include <iostream>
#include <vector>
using namespace std;

// vector 基本概念与构造函数

/*
vector 基本概念
  vector 数据结构与数组非常相似，也称为单端数组。
  不同之处在于数组是静态空间，vector可以动态扩展

  动态扩展：并非在原空间之后续接新空间，而是找更大的内存空间，然后将原有的数据拷贝到新空间，释放原空间

  vector容器的迭代器支持随机访问
*/

/*
vector 构造函数

 - vector<T> v;                  // 采用模板实现类实现，默认构造函数
 - vector(v.begin(), v.end());   // 将 v[begin(), end()) 区间中的元素拷贝给本身
 - vector(n, elem);              // 构造函数将 n 个 elem 拷贝给本身
 - vector(const vector &vec);    // 拷贝构造函数
*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    // 默认构造：无参构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个elem方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}