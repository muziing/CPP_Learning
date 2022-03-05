#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
案例需求：
  有5名选手ABCDE，10个评委分别对每一位选手打分，去掉最高分和最低分，取平均分作为最后成绩
*/

// 选手类
class Player
{
public:
    Player(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name; // 姓名
    int m_Score;   // 平均分
};

void creatPlayer(vector<Player> &v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameSeed[i];
        int score = 0;

        Player p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Player> &v)
{
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 将评委的分数放入deque容器中
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        // cout << it->m_Name << " 得分:" << endl;
        // for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        // {
        //     cout << *dit << " ";
        // }
        // cout << endl;

        // 排序
        sort(d.begin(), d.end());
        // 去除最高分与最低分
        d.pop_back();
        d.pop_front();

        // 取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit; // 累加每个评委的分数
        }

        int avg = sum / d.size();

        // 将平均分赋值给选手
        it->m_Score = avg;
    }
}

void showScore(vector<Player> &v)
{
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->m_Name << "的平均分为 " << it->m_Score << endl;
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 1、创建5名选手

    // 存放选手容器
    vector<Player> v;
    creatPlayer(v);

    // 测试
    // for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << "姓名: " << (*it).m_Name << "  分数: " << (*it).m_Score << endl;
    // }

    // 2、给5名选手打分
    setScore(v);

    // 3、显示最终得分
    showScore(v);
    return 0;
}