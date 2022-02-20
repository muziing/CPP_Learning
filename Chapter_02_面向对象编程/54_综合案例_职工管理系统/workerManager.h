#pragma once // 防止头文件重复包含
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    // 构造函数
    WorkerManager();

    // 展示菜单
    void Show_Menu();

    // 退出功能
    void exitSystem();

    // 析构函数
    ~WorkerManager();

    // 增加职工
    void Add_Emp();

    // 保存文件
    void save();

    // 统计文件中人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 显示职工
    void Show_Emp();

    // 删除职工
    void Del_Emp();

    // 按职工编号判断职工是否存在
    int IsExist(int id);

    // 修改职工
    void Mod_Emp();

    // 查找职工
    void Find_Emp();

    // 清空文件
    void Clean_File();

    int m_EmpNum;        // 记录文件中的人数个数
    Worker **m_EmpArray; // 员工数组的指针
    bool m_FileIsEmpty;  // 文件是否为空的标志
};
