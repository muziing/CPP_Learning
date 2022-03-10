#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二元谓词

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
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(10);

    sort(v.begin(), v.end());
    printVector(v);

    // 使用函数对象，改变排序规则为降序
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);
}

int main()
{
    test01();
    return 0;
}