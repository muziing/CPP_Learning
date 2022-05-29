#include <algorithm>
#include "manager.h"

void printStudent(Student &s)
{
    cout << "学号：" << s.m_Id << "姓名：" << s.m_Name << "密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher &t)
{
    cout << "职工号：" << t.m_EmpId << "姓名：" << t.m_Name << "密码：" << t.m_Pwd << endl;
}

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;

    // 初始化容器
    this->initVector();
}

void Manager::operMenu()
{
    cout << "欢迎管理员：" << this->m_Name << "登陆！" << endl;
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
    cout << "\t\t|           0.注销登陆         |\n";
    cout << "\t\t|                              |\n";
    cout << "\t\t ------------------------------\n";
    cout << "输入您的选择：" << endl;
}

void Manager::addPerson()
{
    string fileName;
    string tip;
    string errorTip; // 重复错误提示
    ofstream ofs;

    cout << "请输入添加帐号的类型" << endl;
    cout << "1.添加学生" << endl;
    cout << "2.添加老师" << endl;

    // 接收用户输入帐号类型
    int type_select = 0;
    while (true)
    {
        cin >> type_select;

        if (type_select == 1)
        {
            fileName = STUDENT_FILE;
            tip = "请输入学号：";
            errorTip = "学号重复，请重新输入";
            break;
        }
        else if (type_select == 2)
        {
            fileName = TEACHER_FILE;
            tip = "请输入职工编号：";
            errorTip = "职工号重复，请重新输入";
            break;
        }
        else
        {
            cout << "输入错误，请重试" << endl;
        }
    }

    // 接收新账户的信息
    int id;
    string name;
    string pwd;

    cout << tip << endl;
    // 输入ID，并检测重复
    while (true)
    {
        cin >> id;
        bool ret = this->checkRepeat(id, type_select);
        if (ret) // 有重复
        {
            cout << errorTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    // 添加到vector容器中
    if (type_select == 1)
    {
        this->vStu.push_back(Student(id, name, pwd));
    }
    else if (type_select == 2)
    {
        this->vTea.push_back(Teacher(id, name, pwd));
    }

    // 写入文件
    ofs.open(fileName, ios::out | ios::app);
    ofs << id << " " << name << " " << pwd << endl;
    ofs.close();

    system("clear");
    cout << "添加成功" << endl;
}

void Manager::showPerson()
{
    cout << "请选择查看内容：" << endl;
    cout << "1.查看所有学生" << endl;
    cout << "2.查看所有老师" << endl;

    int select = 0;
    cin >> select;

    system("clear");

    if (select == 1)
    {
        cout << "全部学生信息如下：" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else if (select == 2)
    {
        cout << "全部教师信息如下：" << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }
}

void Manager::showComputer()
{
    system("clear");
    cout << "机房信息如下：" << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "机房编号：" << it->m_ComId << "机房最大容量：" << it->m_MaxNum << endl;
    }
}

void Manager::cleanFile()
{
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    system("clear");
    cout << "清空成功！" << endl;
}

void Manager::initVector()
{
    // 读取学生文件中信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    vStu.clear();
    vTea.clear();

    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }
    cout << "当前学生数量为：" << vStu.size() << endl;
    ifs.close(); //学生初始化

    // 读取老师文件信息
    ifs.open(TEACHER_FILE, ios::in);

    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }
    cout << "当前教师数量为：" << vTea.size() << endl;

    ifs.close();

    // 机房信息
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
    {
        vCom.push_back(c);
    }
    cout << "当前机房数量为：" << vCom.size() << endl;
    ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_Id)
            {
                return true;
            }
        }
    }
    else if (type == 2)
    {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->m_EmpId)
            {
                return true;
            }
        }
    }
    return false;
}
