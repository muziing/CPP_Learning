#include <iostream>
#include <map>
#include <vector>
using namespace std;

// STL容器 案例：员工分组
/*
案例描述：
 - 10名新员工（ABCDEFGHIJ），需要指派在哪个部门工作
 - 员工信息：姓名、工资
 - 部门：策划、美术、研发
 - 随机给10名员工分配部门和工资
 - 通过multimap进行信息的插入：key--部门编号, value--员工
 - 分部门显示员工信息
*/

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void creatWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000; // 10000 ~ 19999
        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptId = rand() % 3;

        // 将员工插入到分组中
        // key部门编号， value员工
        m.insert(make_pair(deptId, *it));
    }
}

void printWorker(multimap<int, Worker> &m, int deptId)
{
    multimap<int, Worker>::iterator pos = m.find(deptId);
    int count = m.count(deptId); // 统计具体人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "\t" << pos->second.m_Salary << endl;
    }
    cout << endl;
}

void showWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门：" << endl;
    printWorker(m, CEHUA);
    cout << "美术部门" << endl;
    printWorker(m, MEISHU);
    cout << "研发部门" << endl;
    printWorker(m, YANFA);
}

int main()
{
    srand((unsigned int)time(NULL));

    // 1、创建员工
    vector<Worker> vWorkers;
    creatWorker(vWorkers);

    // 测试
    // for (vector<Worker>::iterator it = vWorkers.begin(); it != vWorkers.end(); it++)
    // {
    //     cout << it->m_Name << "\t" << it->m_Salary << endl;
    // }

    // 2、员工分组
    multimap<int, Worker> mWorkers;
    setGroup(vWorkers, mWorkers);

    // 3、分组显示员工
    showWorkerByGroup(mWorkers);

    return 0;
}