#pragma once
#include "identity.h"

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
};