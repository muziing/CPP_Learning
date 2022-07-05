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
    speechContest();

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

void SpeechManager::speechContest()
{
    cout << "---------------- 第" << this->m_Index << "轮比赛开始 ----------------" << endl;
    multimap<double, int, greater<double>> groupScore; // 临时容器，保存key分数 value选手编号

    int num = 0; // 记录参赛人数，6个为1组

    vector<int> v_Src; // 比赛的人员容器
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    // 遍历所有参赛选手
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;
        // 评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f; // 600 ~ 100
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>());       // 排序
        d.pop_front();                                     // 去掉最高分
        d.pop_back();                                      // 去掉最低分
        double sum = accumulate(d.begin(), d.end(), 0.0f); // 获取总分
        double avg = sum / (double)d.size();               // 获取平均分

        // 每个人平均分
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

        // 6个人一组，用临时容器保存
        groupScore.insert(make_pair(avg, *it));
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号：" << it->second << "姓名：" << this->m_Speaker[it->second].m_Name
                     << " 成绩：" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
            }
            int count = 0;

            // 取前三名
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    vVictory.push_back((*it).second);
                }
            }
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "---------------- 第" << this->m_Index << "轮比赛完毕 ----------------\n\n" << endl;
}
