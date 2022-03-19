#pragma once
#include <iostream>

using namespace std;

// 设计演讲比赛管理类
/*
 - 提供菜单界面与用户交互
 - 对演讲比赛流程进行控制
 - 与文件的读写交互
*/

class SpeechManager
{
public:
    SpeechManager();

    void show_Menu();

    ~SpeechManager();
};