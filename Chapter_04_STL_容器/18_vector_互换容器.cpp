#include <iostream>
#include <vector>
using namespace std;

// vector 互换容器

// swap(vec);  // 将vec与本身的元素互换

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 基本使用
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 9; i >= 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    // 交换
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

// 实际用途：巧用swap可以收缩内存空间
void test02()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v 容量为 " << v.capacity() << endl;
    cout << "v 大小为 " << v.size() << endl;

    v.resize(3);
    cout << "v 容量为 " << v.capacity() << endl;
    cout << "v 大小为 " << v.size() << endl;

    // 巧用swap收缩内存
    vector<int>(v).swap(v);
    // vector<int>(v) 匿名对象，拷贝构造
    cout << "v 容量为 " << v.capacity() << endl;
    cout << "v 大小为 " << v.size() << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}