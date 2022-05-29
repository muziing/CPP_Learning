#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "computerRoom.h"

using namespace std;

// 身份抽象类
class Identity
{
public:
    // 操作菜单 纯虚函数
    virtual void operMenu() = 0;

    string m_Name; // 用户名
    string m_Pwd;  // 密码
};
