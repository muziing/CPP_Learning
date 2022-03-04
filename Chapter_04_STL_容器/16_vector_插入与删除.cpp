#include <iostream>
#include <vector>
using namespace std;

// vector 插入与删除

/*
 - push_back(ele);      // 尾部插入元素ele
 - pop_back();          // 删除最后一个元素
 - insert(const_iterator pos, ele);           // 迭代器指向位置pos插入元素ele
 - insert(const_iterator pos, int count,ele); // 迭代器指向位置pos插入count个元素ele
 - erase(const_iterator pos);                 // 删除迭代器指向的元素
 - erase(const_iterator start, const_tierator end);  // 删除迭代器从start到end之间的元素
 - ckear();            // 删除容器中所有元素
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
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    printVector(v1);

    // 尾删
    v1.pop_back();
    printVector(v1);

    // 插入（第一个参数是迭代器）
    v1.insert(v1.begin(), 100);
    printVector(v1);
    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除（参数为迭代器）
    v1.erase(v1.begin());
    printVector(v1);

    // 删除区间
    // v1.erase(v1.begin(), v1.end());

    // 清空
    v1.clear();
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}