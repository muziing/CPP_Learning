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
}

// 查看所有预约
void Student::showAllOrder()
{
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
