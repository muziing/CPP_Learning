#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "speaker.h"

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

    // 比赛选手容器 12人
    vector<int> v1;

    // 第一轮晋级容器 6人
    vector<int> v2;

    // 胜利前三名容器 3人
    vector<int> vVictory;

    // 存放编号以及对应的具体选手容器
    map<int, Speaker> m_Speaker;

    // 记录比赛轮数
    int m_Index;

    void exitSystem();

    // 初始化
    void initSpeech();

    // 初始化创建12名选手
    void creatSpeaker();

    // 开始比赛-比赛流程控制
    void startSpeech();

    // 抽签
    void speechDraw();
};
