#include "student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    // 获取机房信息
    this->initVector();
}

// 菜单界面
void Student::operMenu()
{
    cout << "欢迎学生代表：" << this->m_Name << "登陆！" << endl;
    cout << "\t\t ------------------------------\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         1.申请预约           |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         2.查看我的预约       |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         3.查看所有预约       |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         4.取消预约           |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|         0.注销登陆           |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t ------------------------------\n";
    cout << "输入您的选择：" << endl;
}

// 申请预约
void Student::applyOrder()
{
    cout << "机房开放时间为周一至周五" << endl;
    cout << "请输入申请预约时间：" << endl;
    cout << "1.周一 2.周二 3.周三 4.周四 5.周五" << endl;
    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请输入预约时间段:" << endl;
    cout << "1.上午 2.下午" << endl;

    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1号机房容量" << vCom[0].m_MaxNum << endl;
    cout << "2号机房容量" << vCom[1].m_MaxNum << endl;
    cout << "3号机房容量" << vCom[2].m_MaxNum << endl;

    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;
    ofs.close();

    system("clear");
    cout << "预约成功！审核中……" << endl;
}

// 查看自己的预约
void Student::showMyOrder()
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
        // string 利用 .c_str() 转 const char *
        // (const char *) 利用 atoi 转 int
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
        {
            cout << "预约日期：周" << of.m_orderData[i]["date"];
            cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房：" << of.m_orderData[i]["roomId"];

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
}

// 查看所有预约
void Student::showAllOrder()
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

        string status = " 状态:";
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

// 取消预约
void Student::cancelOrder()
{
}

void Student::initVector()
{
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
    {
        vCom.push_back(c);
    }
    ifs.close();
}
