#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
    this->m_Nmae = name;
    this->m_Pwd = pwd;
}

void Manager::operMenu()
{
    cout << "欢迎管理员：" << this->m_Nmae << "登陆！" << endl;
    cout << "\t\t ------------------------------\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|           1.添加帐号         |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|           2.查看帐号         |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|           3.查看机房         |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|           4.清空预约         |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t|           0.注销登陆          |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择：" << endl;
}

void Manager::addPerson()
{
    string fileName;
    string tip;
    ofstream ofs;

    cout << "请输入添加帐号的类型" << endl;
    cout << "1.添加学生" << endl;
    cout << "2.添加老师" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
    }
    else
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
    }

    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout << tip << endl;
    cin >> id;
    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << endl;
    cout << "添加成功" << endl;

    system("clear");
    cout << "添加成功" << endl;

    ofs.close();
}

void Manager::showPerson()
{
}

void Manager::showComputer()
{
}

void Manager::cleanFile()
{
}