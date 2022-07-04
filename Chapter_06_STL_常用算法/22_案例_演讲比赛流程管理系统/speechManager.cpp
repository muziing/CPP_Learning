#include "speechManager.h"

SpeechManager::SpeechManager()
{
    // 初始化容器和属性
    this->initSpeech();

    // 创建12名选手
    this->creatSpeaker();
}
SpeechManager::~SpeechManager()
{
}

void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void SpeechManager::show_Menu()
{
    cout << "******************************" << endl;
    cout << "****** 欢迎参加演讲比赛 ******" << endl;
    cout << "******* 1.开始演讲比赛 *******" << endl;
    cout << "******* 2.查看往届记录 *******" << endl;
    cout << "******* 3.清空比赛记录 *******" << endl;
    cout << "******* 0.退出比赛程序 *******" << endl;
    cout << "******************************" << endl;
    cout << endl;
}

void SpeechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Index = 1;
}

void SpeechManager::creatSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; j++)
        {
            sp.m_Score[j] = 0;
        }

        // 12名选手编号
        this->v1.push_back(i + 10001);

        // 选手编号以及对应的选手
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    // 第一轮比赛
    // 1.抽签
    speechDraw();

    // 2.比赛

    // 3.显示晋级结果

    // 第二轮比赛
    // 1.抽签

    // 2.比赛

    // 3.显示最终结果

    // 4.保存分数
}

void SpeechManager::speechDraw()
{
    system("clear");
    cout << "第 <<" << this->m_Index << ">> 轮选手正在抽签" << endl;
    cout << "------------------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
    cout << endl;
}
