#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// random_shuffle
/*
将指定范围内的元素随机调整次序（洗牌）

random_shuffle(iterator beg, iterator end);
  beg 开始迭代器
  end 结束迭代器

*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();
    return 0;
}