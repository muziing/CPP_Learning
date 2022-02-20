#include "MyArray.hpp"

void test01()
{
    MyArray<int> arr1(5);
    // MyArray<int> arr2(arr1);
    MyArray<int> arr3(40);
    arr3 = arr1;
}

void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test02()
{
    MyArray<int> arr(5);

    for (int i = 0; i < 5; i++)
    {
        // 利用尾插法向数组中插入数据
        arr.Push_Back(i);
    }
    cout << "-------尾删前-------" << endl;
    cout << "arr的打印输出为" << endl;
    printIntArray(arr);
    cout << "arr的容量为 " << arr.getCapacity() << endl;
    cout << "arr的大小为 " << arr.getSize() << endl;

    cout << "-------尾删后-------" << endl;
    arr.Pop_Back();
    cout << "arr的打印输出为" << endl;
    printIntArray(arr);
    cout << "arr的容量为 " << arr.getCapacity() << endl;
    cout << "arr的大小为 " << arr.getSize() << endl;
}

// 测试自定义数据类型
class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "姓名 " << arr[i].m_Name
             << "\t年龄" << arr[i].m_Age
             << endl;
    }
}

void test03()
{
    MyArray<Person> arr(10);

    Person p1("张三", 20);
    Person p2("李四", 22);
    Person p3("王五", 21);
    Person p4("周六", 19);

    // 将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);

    printPersonArray(arr);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}