#include <iostream>
#include <vector>
using namespace std;

// vector 预留空间

// reserve(int len);  // 容器预留len个元素长度，预留位置不初始化，元素不可访问

void test01()
{
    vector<int> v;

    // 利用 reserve 预留空间
    v.reserve(100000);

    int num = 0; // 统计开辟次数
    int *p = NULL;

    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);

        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "开辟内存次数为 " << num << endl;
}

int main()
{
    test01();
    return 0;
}