#pragma once
#include <vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"

class Manager : public Identity
{
public:
    // 默认构造
    Manager();

    // 有参构造
    Manager(string name, string pwd);

    // 选择菜单
    virtual void operMenu();

    // 添加帐号
    void addPerson();

    // 查看帐号
    void showPerson();

    // 查看机房信息
    void showComputer();

    // 清空预约记录
    void cleanFile();

    // 检测重复
    bool checkRepeat(int id, int type);

private:
    // 学生容器
    vector<Student> vStu;

    // 教师容器
    vector<Teacher> vTea;

    // 初始化容器
    void initVector();
};