#include <iostream>
#include <vector>
using namespace std;

// vector 数据存取

/*
 - at(int idx);   // 返回索引idx所指的数据
 - operator[];    // 返回索引idx所指的数据
 - front();       // 返回容器中第一个数据元素
 - back();        // 返回容器中最后一个数据元素
*/

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    // 利用operator[]访问vector中元素
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // 利用at访问元素
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // 容器中第一个数据元素
    cout << "v1 的首元素为 " << v1.front() << endl;

    // 容器中最后一个元素
    cout << "v1 的末元素为 " << v1.back() << endl;
}

int main()
{
    test01();
    return 0;
}