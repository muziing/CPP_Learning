#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 逻辑仿函数
// 实现逻辑运算
/*
  - template<class T> bool logical_and<T>    // 逻辑与
  - template<class T> bool logical_or<T>     // 逻辑或
  - template<class T> bool logical_not<T>    // 逻辑非
*/

void printVector(const vector<bool> &v)
{
    for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    printVector(v);

    // 利用逻辑非，将容器v搬运到容器v2中，并执行取反操作
    vector<bool> v2;
    v2.resize(v.size());

    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    printVector(v2);
}

int main()
{
    test01();
    return 0;
}