#include "teacher.h"

// 默认构造
Teacher::Teacher()
{
}

// 有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

// 菜单界面
void Teacher::operMenu()
{
    cout << "欢迎教师：" << this->m_Name << "登陆！" << endl;
    cout << "\t\t ------------------------------\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         1.查看所有预约       |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         2.审核预约           |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         0.注销登陆           |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t ------------------------------\n";
    cout << "输入您的选择：" << endl;
}

// 查看所有预约
void Teacher::showAllOrder()
{
    system("clear");
    OrderFile of;
    if (of.m_Size == 0)
    {
        system("clear");
        cout << "无预约记录" << endl;
        return;
    }
    for (int i = 0; i < of.m_Size; i++)
    {
        cout << i + 1 << ". ";
        cout << "预约日期:周" << of.m_orderData[i]["date"];
        cout << " 时段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号:" << of.m_orderData[i]["stuId"];
        cout << " 姓名:" << of.m_orderData[i]["stuName"];
        cout << " 机房:" << of.m_orderData[i]["roomId"];

        string status = " 状态：";
        // 0 取消的预约  1 审核中  2 已预约  -1 预约失败
        int ofStatus = atoi(of.m_orderData[i]["status"].c_str());
        switch (ofStatus)
        {
        case 1:
            status += "审核中";
            break;
        case 2:
            status += "已预约";
            break;
        case -1:
            status += "预约失败";
        default:
            status += "预约已取消";
            break;
        }
        cout << status << endl;
    }
}

// 审核预约
void Teacher::validOrder()
{
    system("clear");
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "无预约记录" << endl;
        return;
    }
    cout << "待审核的预约记录如下：" << endl;

    vector<int> v;
    int index = 0;
    for (int i = 0; i < of.m_Size; i++)
    {
        if (of.m_orderData[i]["status"] == "1")
        {
            v.push_back(i);
            cout << ++index << "、";
            cout << "预约日期：周" << of.m_orderData[i]["date"];
            cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房：" << of.m_orderData[i]["roomId"];
            cout << " 状态：审核中" << endl;
        }
    }
    cout << "请输入要审核的预约记录, 0代表返回" << endl;
    int select = 0;
    int ret = 0;
    while (true)
    {
        cin >> select;
        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                cout << "请输入审核结果" << endl;
                cout << "1.通过  2.不通过" << endl;
                cin >> ret;

                if (ret == 1)
                {
                    of.m_orderData[v[select - 1]]["status"] = "2";
                }
                else if (ret == 2)
                {
                    of.m_orderData[v[select - 1]]["status"] = "-1";
                }
                of.updateOrder();
                cout << "操作成功" << endl;
                break;
            }
        }
        cout << "输入有误，请重新输入" << endl;
    }
}
