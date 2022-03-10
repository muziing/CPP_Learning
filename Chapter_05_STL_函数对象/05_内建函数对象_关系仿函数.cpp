#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

// 关系仿函数
// 实现关系对比
/*
  - template<class T> bool equal_to<T>       // 等于
  - template<class T> bool not_equal_to<T>   // 不等于
  - template<class T> bool greater<T>        // 大于
  - template<class T> bool greater_equal<T>  // 大于等于
  - template<class T> bool less<T>           // 小于
  - template<class T> bool less_equal<T>     // 小于等于
*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(10);
    v.push_back(40);
    printVector(v);

    // 实现降序排序
    // sort(v.begin(), v.end(), MyCompare());
    sort(v.begin(), v.end(), greater<int>()); // 等效于上一行
    printVector(v);
}

int main()
{
    test01();
    return 0;
}