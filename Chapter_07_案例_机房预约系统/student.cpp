#include "student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

// 菜单界面
void Student::operMenu()
{
}

// 申请预约
void Student::applyOrder()
{
}

// 查看自己的预约
void Student::showMyOrder()
{
}

// 查看所有预约
void Student::showAllOrder()
{
}

// 取消预约
void Student::cancelOrder()
{
}