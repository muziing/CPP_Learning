#include <iostream>
#include <vector>
using namespace std;

// vector 容量与大小

/*
 - empty();         // 判断容器是否为空
 - capacity();      // 容器的容量
 - size();          // 返回容器中元素的个数
 - resize(int num); // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置；若变短，则末尾超出容器长度的元素被删除
 - resize(int num, elem);  // 重新指定容器的长度为num，若变长则以elem填充新位置；若变短则删末尾超出
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
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1 为空" << endl;
    }
    else
    {
        cout << "v1 不为空" << endl;
        cout << "v1 容量为 " << v1.capacity() << endl;
        cout << "v1 大小为 " << v1.size() << endl;
    }

    // 重新指定大小
    // v1.resize(15); // 如果新size大于原来的，默认用0填充
    v1.resize(15, 10); // 也可以指定用elem填充
    printVector(v1);

    v1.resize(5); // 如果新size小于原来的，超出的部分会被删除
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}