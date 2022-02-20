// 自定义的通用数组类
#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
    // 有参构造
    MyArray(int capacity)
    {
        // cout << "调用了MyArray有参构造" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 析构函数
    ~MyArray()
    {
        // cout << "调用了MyArray析构函数" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        // cout << "调用了MyArray拷贝构造" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity]; // 深拷贝
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝问题
    MyArray &operator=(const MyArray &arr)
    {
        // cout << "调用了MyArray的operator=" << endl;
        // 先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    // 尾插法
    void Push_Back(const T &val)
    {
        // 判断大小是否等于容量
        if (this->m_Capacity == this->m_Size)
        {
            cout << "容量已满, 插入失败" << endl;
            return;
        }
        this->pAddress[this->m_Size] = val; // 在数组末尾插入数据
        this->m_Size++;                     // 更新数组大小
    }

    // 尾删法
    void Pop_Back()
    {
        // 让用户访问不到最后一个元素，即为尾删
        if (this->m_Size == 0)
        {
            cout << "已空, 尾删失败" << endl;
            return;
        }
        this->m_Size--;
    }

    // 通过下标方式访问
    T &operator[](int index)
    {
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

private:
    T *pAddress;    //指针指向堆区开辟的真实数组
    int m_Capacity; // 数组容量
    int m_Size;     // 数组大小
};